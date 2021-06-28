# breakout_encoder
This is a C++ project using a Pimoroni rgb breakout pack on a Pimoroni pico explorer base and a Raspberry Pi Pico mounted onto the explorer base.
 
Idea and sources are from the Pimoroni-pico repo, especially the part from the Examples / breakout_encoder.
The original example demo.cpp I modified quite a bit, for example: 
  instead of calculation of the rgb color values for the led, originally done in the function from_hsv().
This project uses another approach. Departing with the value of variable 'count' and an index two tables: modTbl and clrTbl.

In the function count_changed() variable idx is an index to the two-dimensional vector table clrTbl.
The function contains an algorythm that ensures the idx is alway valid as index to clrTbl.

This repo only worked good with the latest version of the pico-sdk repo and the latest version of the Pimoroni-pico repo, both available here on GitHub.

Important:
The original demo.cpp from the Pimoroni-pico examples, contains in line 12 the command: 'I2C i2c(BOARD::BREAKOUT_GARDEN);'
For use with the Pimoroni pico explorer base (which this repo is build upon), this line has to be changed into:
'I2C i2c(BOARD::PICO_EXPLORER);'. There is no need to set an I2C address. Using "BOARD::PICO_EXPLORER" is sufficient. The addressing is handled by the Pimoroni-pico repo parts.

I used the MS VSCode IDE to edit and manage the project. Built using WSL1/Ubuntu 20.04 from MS Window 10. During the development I also tested and build the project
from within a Linux Ubuntu 20.04 O.S.

ToDo:
It is known that interrupt polling and subsequent reading of the rgb encoder needs some time. The communication between the Pico and the rgb encoder is via an I2C interface.
The current situation is that when turning the rotary encoder fast it happens that the program locks up. 
I use a RPi Pico that has a Pimoroni Resetti button. This reset button can successfully be used to reset the program.

Buttons (experimental):
The current functionality of the four buttons alongside the display on the pico explorer base has been added just as part of an experiment.
The functionality is not perfect. In fact these four buttons are not needed for testing the Pimoroni rgb encoder pack.
This project (demo.cpp) contains a function to handle button presses.
Button A: increase count;
Button B: decrease count;
Button Y: reset count to 0;
Button X: leave the main program execution loop and go into a perpetual loop, doing nothing else than blinking the built-in led of the RPi Pico.

ToDo: after increasing/decreasing the count by means of buttons A/B, the rgb color of the rotary encoder led has to be 'updated/aligned'. As far as I learned,
the values of the encoder are readonly. Thus the current effect of zero'ing the count is a kind of presetting the count.
Example: say, the black index line on the rotary encoder knob is in the 3 o'clock position. If one presses either the Y-button or the reset button, the variable 'count' will be zero'ed. Turning the rotary encoder knob CCW to the 12 o'clock position will result in the value of 'count' becoming -6. Usually the 12 o'clock position would be the 'count' zero position.


At start (boot up) of the Pico and before pressing the reset button, it is adviseable to set the rotary encoder button with the black index line in the 12 o'clock position.


