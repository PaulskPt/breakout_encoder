/**
 * Partly Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 * Partly Copyright (c) 2020 Pimoroni Ltd.
 * Partly Copyright (c) 2021 Paulus Schulinck @paulsk. 
 * 2021-06-27 at 18h49 PT the project functioning as intended.
 * 'Finishing touch' ready on 2021-06-28 at 18h49 PT (coincidence!)
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "pico/stdlib.h"
#include "../../../../../pico-sdk/src/rp2_common/hardware_watchdog/include/hardware/watchdog.h"
#include <stdio.h>
#include <math.h>
#include "../../common/pimoroni_common.hpp"
#include "../../libraries/breakout_encoder/breakout_encoder.hpp"
#include "../../libraries/pico_explorer/pico_explorer.hpp"
#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include <assert.h>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "demo.hpp"

using namespace pimoroni;

uint16_t buffer[PicoExplorer::WIDTH * PicoExplorer::HEIGHT];
PicoExplorer p_exp(buffer);

bool lStart = true; // start flag to be used in from_hsv()

I2C i2c(BOARD::PICO_EXPLORER); // BREAKOUT_GARDEN);
BreakoutEncoder enc(&i2c);
bool toggle = false;

paulsk::Cnt_it my_ctr; // instantiate object

void count_changed() {
  int16_t count = my_ctr.have_cnt(); // get the current count value
  uint8_t r = 0;
  uint8_t g = 0;
  uint8_t b = 0;
  int8_t idx = 0;
  std::vector<int> rgb = {0,0,0};
  Point p;
  p.x = 10;
  //int pe = 220;
  //int fnt_corps = 6;
  const std::vector<int> ofs_cc = {10, 70, 130, 190};

  if (my_debug)
    printf("\nCount: %d", count);

  if (lStart)
  {
    r = disp_white.at(RED);
    g = disp_white.at(GREEN);
    b = disp_white.at(BLUE);
  }
 
  if (count < 0)
    idx = -count;
  else
    idx = count;

  idx = idx % STEPS_PER_REV;  // range 0-23 only. Needed as index to clrTbl
  if (my_debug)
  {
    printf("\nclrTbl.size(): %d", clrTbl.size());
    printf("\nidx: %d\n", idx);
  }
  //sleep_ms(1000);

  if (count < 0)
  {  //          correct for situation that -1 % 24 gives 23 and -23 % 24 gives 1
    idx = modTbl.at(idx);  // correct step 2)  if idx is 23 then make it 1 ... if idx is 1 then make it 23
    if (my_debug)
      printf("corrected idx: %d\n", idx);
  }

  if (idx >= clrTbl.size())
    idx = clrTbl.size()-1; // set idx to last vector element
  else if (idx < 0)
    idx = 0;
  rgb = clrTbl.at(idx);
  r = rgb.at(0);
  g = rgb.at(1);
  b = rgb.at(2);
  if (my_debug) 
  {
    printf("rgb = %d,%d,%d\n", r, g, b);
    bgnd_colour =  DISP_AUBERGINE;
    fgnd_colour =  DISP_YELLOW;
    set_DispColour(true, bgnd_colour, true);  // clear screen in colour
    sleep_ms(20);
    set_DispColour(true, fgnd_colour, false);
    disp_a_txt(std::to_string(r),0);
    disp_a_txt(std::to_string(g),1);
    disp_a_txt(std::to_string(b),2);
    sleep_ms(3000);
  }
  enc.set_led(r, g, b);
}

void set_DispColour(bool bf, int disp_colour, bool cleardisp)
{
  static const std::string TAG = "Set_DispColour(): ";
  static const std::string T2 = "setting the ";
  static const std::string SFX = "ground colour";
  static const std::vector<std::string> bfs = {"back", "fore"};
  static const std::string CTBST = "colour to be set to: ";
  static const std::string DSP = "display ";

  if (disp_colour < DISP_BLACK || disp_colour > DISP_WHITE)
  {
    if (bf)  // Are we doing background or foreground colour ?
    {
      std::cout << TAG+T2+"back"+SFX << std::endl;
      disp_colour = bgnd_colour;  // Set the background colour to the vaalue of the global variable bgnd_colour
    }
    else
    {
      std::cout << TAG+T2+"fore"+SFX << std::endl;
      disp_colour = fgnd_colour; // Set the foreground colour to the value of the global variable fgnd_colour
    }
  }

  switch (disp_colour)  
  {
    case DISP_BLACK:
       p_exp.set_pen(disp_black[RED], disp_black[GREEN], disp_black[BLUE]);
       break;
    case DISP_RED:
      p_exp.set_pen(disp_red[RED], disp_red[GREEN], disp_red[BLUE]);
      break;
    case DISP_ORANGE:
      p_exp.set_pen(disp_orange[RED], disp_orange[GREEN], disp_orange[BLUE]);
      break;
    case DISP_YELLOW:
      p_exp.set_pen(disp_yellow[RED], disp_yellow[GREEN], disp_yellow[BLUE]);
      break;
    case DISP_GREEN:
      p_exp.set_pen(disp_green[RED], disp_green[GREEN], disp_green[BLUE]);
      break;
    case DISP_BLUE:
      p_exp.set_pen(disp_blue[RED], disp_blue[GREEN], disp_blue[BLUE]);
      break;
    case DISP_AUBERGINE:
      p_exp.set_pen(disp_auber[RED], disp_auber[GREEN], disp_auber[BLUE]);
      break;
    case DISP_WHITE:
      p_exp.set_pen(disp_white[RED], disp_white[GREEN], disp_white[BLUE]);
      break;
    default:
      p_exp.set_pen(disp_green[RED], disp_green[GREEN], disp_green[BLUE]);
      break;
  }
  if (cleardisp)
    p_exp.clear();
}

void enc_intro(int choice) 
{
  static const std::string s1 = "Encoder ";
  static const std::string s1a = "found ";
  static const std::string s2 = "at address: ";
  std::string s3 = "";
  static const std::string s4 = s1 + "not " +s1a;

  int pe = 239;
  int fnt_corps = 4;
  Point p;
  p.x = px_dflt;
  set_DispColour(true, bgnd_colour, true);  // clear the screen
  sleep_ms(20);
  set_DispColour(true, fgnd_colour, false);
  if (choice == 1) 
  {
    p.y = ofs.at(0);
    s3.append(std::to_string(enc.get_address()));
    //enc.set_direction(BreakoutEncoder::DIRECTION_CCW);    // Uncomment this to flip the direction
    if (my_debug)
      std::cout << s1 << s1a << " " << s2 << std::hex << "0x" << enc.get_address() << std::endl;

    for (int i=1; i <4; i++) {
      p.y = ofs.at(i);
      if (i == 1)
        p_exp.text(s1+s1a, Point(p.x, p.y), pe, fnt_corps);
      else if (i == 2)
        p_exp.text(s2, Point(p.x, p.y), pe, fnt_corps);
      else if (i == 3)
        p_exp.text(s3, Point(p.x, p.y), pe, fnt_corps);
    }
  }
  else if (choice == 2) 
  {
    if (my_debug)
      std::cout << s4 << std::endl;
    p.y = ofs.at(3);
    for (int i=1; i <4; i++) {
      p.y = ofs.at(i);
      if (i == 1)
        p_exp.text(s1, Point(p.x, p.y), pe, fnt_corps);
      else if (i == 2)
        p_exp.text("not", Point(p.x, p.y), pe, fnt_corps);
      else if (i == 3)
        p_exp.text(s1a, Point(p.x, p.y), pe, fnt_corps);
    }
  }
  p_exp.update();
  sleep_ms(2000);
}

void enc_loop_txt() 
{
  static const std::string s1 = "entering ";
  static const std::string s2 = "infinite loop...";
  int pe = 239;
  int fnt_corps = 4;
  Point p;
  p.x = px_dflt;
  if (my_debug)
    std::cout << s1 << s2  << std::endl;
  set_DispColour(true, bgnd_colour, true);  // clear the screen
  sleep_ms(20);
  set_DispColour(true, fgnd_colour, false);
  p.y = ofs.at(1);
  p_exp.text(s1, Point(p.x, p.y), pe, fnt_corps);
  p.y = ofs.at(2);
  p_exp.text(s2, Point(p.x, p.y), pe, fnt_corps);
  p_exp.update();
}

void disp_a_txt(std::string s, int row) 
{
  int pe = 239;
  int fnt_corps = 4;
  int n = ofs.size();
  int n2;
  Point p;
  p.x = px_dflt;
  if (row >= 0 && row < n) 
  {
    p.y = ofs.at(row);
    if (s.size() > 0) {
      n2 = s.size() < 11 ? s.size() : 10;
      p_exp.text(s.substr(0,n2), Point(p.x, p.y), pe, fnt_corps);
      p_exp.update();
    }
  }
}

void disp_btn_pr(std::string s, bool nop)
{
  if (nop)
  {
    disp_a_txt("btn not",2);
    disp_a_txt("in use",3);
  }
  else
  {
    if (s.size()>0)
    {
      disp_a_txt("button "+s,2); // display text on 3rd ofs item p.y
      disp_a_txt("pressed",3);
    }
  }
}

void ck_btns(bool show_txt)
{
  bool nop = true;

  if (my_debug && show_txt)
  {
    std::cout << "To proceed: press A,B,X or Y button" << std::endl;
    disp_a_txt("Push btn:", 1);
  }

  if (p_exp.is_pressed(p_exp.A))
  {
    btns[BTN_A] = 1;
    disp_btn_pr(b_tns.at(BTN_A), nop);
    return;
  }
  if (p_exp.is_pressed(p_exp.B))
  {
    btns[BTN_B] = 1;
    disp_btn_pr(b_tns.at(BTN_B), nop);
    return;
  }
  if (p_exp.is_pressed(p_exp.X))
  {
    my_ctr.st_stp(true); // indicate to stop
    btns[BTN_X] = 1;
    //disp_btn_pr(b_tns.at(BTN_X), false);
    return;  
  }
  if (p_exp.is_pressed(p_exp.Y))
  {
    btns[BTN_Y] = 1;
    disp_btn_pr(b_tns.at(BTN_Y), nop);
    return;
  }
  return; 
}

void clr_btns()
{
  for (auto i = 0; i < btns.size(); i++)
    btns[i] = 0;
  my_ctr.st_stp(false); // reset stop flag
}
void _exit(int status) {
  printf("_exit(): status %d", status); // This function added to prevent a compiler error 'unidentified reference
  //                                       to _exit
};

void disp_cnt(){
  static const std::string cnt = "count ";
  set_DispColour(true, bgnd_colour, true);  // clear screen in colour
  sleep_ms(20);
  set_DispColour(true, fgnd_colour, false);
  disp_a_txt(cnt + " " + std::to_string(my_ctr.have_cnt()), 1);
}

int main() {

  bool lStart = true;
  int16_t nw_count = 0;
  std::string btn = "0";
  std::string s = "";

  gpio_init(PICO_DEFAULT_LED_PIN);
  gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

  stdio_init_all();
  p_exp.init();
  sleep_ms(200);

  /* the background colour will be fixed.  We're going to choose the foreground colour */
  set_DispColour(true, bgnd_colour, true);  
  sleep_ms(20);
  set_DispColour(true, fgnd_colour, false);
  disp_a_txt("encoder", 0);
  disp_a_txt("test", 1);
  sleep_ms(2000);
  my_ctr.clr_cnts(); // zero all private count values

  if (enc.init()) 
  {
    enc.clear_interrupt_flag();  // added to free evt. interrupt locks
    bgnd_colour =  DISP_AUBERGINE;
    fgnd_colour =  DISP_YELLOW;
    set_DispColour(true, bgnd_colour, true);  // clear screen in colour
    sleep_ms(20);
    set_DispColour(true, fgnd_colour, false);
    disp_a_txt("enc found", 1);
    enc_intro(1);  // Display text about encoder found
    sleep_ms(1000);
    set_DispColour(true, bgnd_colour, true);  // clear screen in colour
    sleep_ms(20);
    set_DispColour(true, fgnd_colour, false);
    enc.clear_interrupt_flag();
    
    while(true) 
    {
      gpio_put(PICO_DEFAULT_LED_PIN, toggle);
      toggle = !toggle;
      clr_btns();
      if (enc.get_interrupt_flag()) 
      {
        nw_count = enc.read();  // the read() calls the ioe.clear_interrupt_flag()
        if (lStart || (nw_count != my_ctr.have_old_cnt())) {  // show count also at startup
          my_ctr.upd_cnt(nw_count);
          count_changed();
          disp_cnt();
          if (lStart)
            lStart = false;
        }
        //enc.clear_interrupt_flag();
      }
      ck_btns(false); // Check if a btn has been pressed. If so, handle it
      if (my_ctr.is_stp())
      {
        /** 
        *  https://www.raspberrypi.org/forums/viewtopic.php?p=1870355, post by cleverca on 2021-05-27.
        *  \param pc If Zero, a standard boot will be performed, if non-zero this is the program counter to jump to on reset.
        *  \param sp If \p pc is non-zero, this will be the stack pointer used.
        *  \param delay_ms Initial load value. Maximum value 0x7fffff, approximately 8.3s.
        *
        * *            (pc, sp, delay_ms) */
        clr_btns();
        disp_a_txt("reset !", 3);
        //sleep_ms(1000);
        /*            (pc, sp, delay_ms) */
        watchdog_reboot(0, 0, 0x7fffff); // varying delay_ms between 0x1fffff and 0x7fffff does not make much difference!
      }
      else if (my_ctr.IsBtnPressed())
      {
        sleep_ms(1000); // let the 'btn not in use' msg stay for a moment
        disp_cnt();  // method to wipe away btn msg
      }
      sleep_ms(100); // loop delay
    }
  }
  else 
  {
    enc_intro(2);  // Display text about encoder not found
    gpio_put(PICO_DEFAULT_LED_PIN, true);
    sleep_ms(500);
    enc_loop_txt(); // Display text entering infinite loop
    gpio_put(PICO_DEFAULT_LED_PIN, true);
    while(true) 
    {
      gpio_put(PICO_DEFAULT_LED_PIN, toggle);
      toggle = !toggle;
      sleep_ms(1000);
    }
  }

  return 0;
}
