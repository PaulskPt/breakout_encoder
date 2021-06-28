/**
 * Partly Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 * Partly Copyright (c) 2020 Pimoroni Ltd.
 * Partly Copyright (c) 2021 Paulus Schulinck @paulsk. 
 * 2021-06-27 at 18h49 PT the project functioning as intended.
 * 'Finishing touch' ready on 2021-06-28 at 18h49 PT (coincidence!)
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <string>
#include <vector>
#include <bitset>
#include "hardware/gpio.h"

//using namespace pimoroni;

const std::vector<int> ofs = {20, 60, 110, 180};
const std::vector<std::string> colours = { "blk", "red", "aub", "ora", "yel", "grn", "blu", "whi"};
const std::vector<std::string> colours_h = { "black", "red", "aubergine", "orange", "yellow", "green", "blue", "white"};
// display background colour sets vectors of integer arrays
const std::vector<int> disp_black =  {0,    0,    0};   // black   see: https://rgbcolorcode.com/color/yellow
const std::vector<int> disp_red =    {120,  0,    0};   // aubergine
const std::vector<int> disp_auber =  {120, 40,   60};   // aubergine
const std::vector<int> disp_orange = {255, 128,   0};   // orange
const std::vector<int> disp_yellow = {255, 255,   0};   // yellow
const std::vector<int> disp_green =  {0,   120,   0};   // green
const std::vector<int> disp_blue =   {0,     0, 120};   // blue
const std::vector<int> disp_violet = {170,   0, 255};   // violet
const std::vector<int> disp_white =  {255, 255, 255};   // white

enum disp_colour_order
{
  DISP_BLACK,       // 0
  DISP_RED,         // 1
  DISP_AUBERGINE,   // 2
  DISP_ORANGE,      // 3
  DISP_YELLOW,      // 4
  DISP_GREEN,       // 5
  DISP_BLUE,        // 6
  DISP_WHITE        // 7
};

std::bitset<4> btns; // x[0-3] is valid

enum button_order
{
  BTN_A,   // 0
  BTN_B,   // 1
  BTN_X,   // 2
  BTN_Y    // 3
};
static const std::vector<std::string> b_tns = {"A", "B", "X", "Y"};

static const std::vector<int> modTbl
{     // count:
   0, // dummy
  23, //  -1 % 24 = 23.  modTbl.at(1) results in: 23
  22, //  -2 % 24 = 22
  21, //  -3 % 24 = 21
  20, //  -4 % 24 = 20
  19, //  -5 % 24 = 19
  18, //  -6 % 24 = 18
  17, //  -7 % 24 = 17
  16, //  -8 % 24 = 16
  15, //  -9 % 24 = 15
  14, // -10 % 24 = 14
  13, // -11 % 24 = 13
  12, // -12 % 24 = 12
  11, // -13 % 24 = 11
  10, // -14 % 24 = 10
   9, // -15 % 24 =  9
   8, // -16 % 24 =  8
   7, // -17 % 24 =  7
   6, // -18 % 24 =  6 
   5, // -19 % 24 =  5
   4, // -20 % 24 =  4
   3, // -21 % 24 =  3
   2, // -22 % 24 =  2
   1, // -23 % 24 =  1 modTbl.at(23) results in: 1
   0, // -24 % 24 =  0 modTbl.at(24) results in: 0
};

static const std::vector<std::vector<int>> clrTbl
{
  // r    g    b
  {255,   0,   0}, // count = 0  red
  {255,  63,   0}, //  1
  {255, 127,   0}, //  2
  {255, 191,   0}, //  3
  {255, 255,   0}, //  4  yellow
  {191, 255,   0}, //  5
  {127, 255,   0}, //  6
  { 63, 253,   0}, //  7
  {  0, 255,   0}, //  8  green
  {  0, 255,  63}, //  9
  {  0, 255, 127}, // 10
  {  0, 255, 191}, // 11
  {  0, 255, 255}, // 12
  {  0, 191, 255}, // 13
  {  0, 127, 255}, // 14
  {  0,  63, 255}, // 15
  {  0,   0, 255}, // 17
  {127,   0, 255}, // 18
  {191,   0, 255}, // 19
  {255,   0, 255}, // 20
  {255,   0, 191}, // 21
  {255,   0, 127}, // 22
  {255,   0,  63}, // 23
};

static const uint8_t STEPS_PER_REV = 24;
bool my_debug = false;
int px_dflt = 15;
int bgnd_colour = DISP_ORANGE; // Global display background colour
int fgnd_colour = DISP_YELLOW;  // Global display foreground (text) colour

void count_changed(int16_t);
void set_DispColour(bool, int, bool);
void enc_intro(int);
void enc_loop_txt();
void disp_a_txt(std::string, int);
void disp_btn_pr(std::string );
int16_t ck_btns(bool, int16_t);
void clr_btns();
void _exit(int); // to prevent a build error 'undefined reference to _exit when using arm-none-eabi-g++
void disp_cnt(int16_t);
int main();