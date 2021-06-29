# breakout_encoder
This is version 2.0 of a C++ project using a Pimoroni rgb breakout pack on a Pimoroni pico explorer base and a Raspberry Pi Pico mounted onto the explorer base.
 
Idea and sources are from the Pimoroni-pico repo, especially the part from the Examples / breakout_encoder.
The original example demo.cpp I modified quite a bit, for example: 
  instead of calculation of the rgb color values for the led, originally done in the function from_hsv().
This project uses another approach. Departing with the value of variable 'count' and an index two tables: modTbl and clrTbl.

In the function count_changed() variable idx is an index to the two-dimensional vector table clrTbl.
The function contains an algorythm that ensures the idx is alway valid as index to clrTbl.

This repo only worked good with the latest version of the pico-sdk repo and the latest version of the Pimoroni-pico repo, both available here on GitHub. I assume that you are familiar with the pico-sdk and have your development environment setup correctly to build C++ applications for the Raspberry Pi Pico using the pico-sdk. This project comes with all the needed CMakeLists.txt files. For those who are not able to build this project from source: see the ready built files in the /build/src/demo folder. There is, among other files, the file 'encoder_explorer.uf2' that you can flash to your Raspberry Pi Pico.

Important:
The original demo.cpp from the Pimoroni-pico examples, contains in line 12 the command: 'I2C i2c(BOARD::BREAKOUT_GARDEN);'
For use with the Pimoroni pico explorer base (which this repo is build upon), this line has to be changed into:
'I2C i2c(BOARD::PICO_EXPLORER);'. There is no need to set an I2C address. Using "BOARD::PICO_EXPLORER" is sufficient. The addressing is handled by the Pimoroni-pico repo parts.

I used the MS VSCode IDE to edit and manage the project. Built using WSL1/Ubuntu 20.04 from MS Window 10. During the development I also tested and build the project
from within a Linux Ubuntu 20.04 O.S.

ToDo:
It is known that interrupt polling and subsequent reading of the rgb encoder needs some time. The communication between the Pimoroni rgb encoder breakout pack and de Raspberry Pi Pico is via an I2C interface.
Turning the rotary encoder too quickly can result in a lockup of the program.
I use a RPi Pico that has a Pimoroni Resetti hardware button soldered onto. This reset button can successfully be used to reset the program. In version 2.0 there is also added a software reset. See below.

Buttons (experimental):
This project (demo.cpp) contains a function to handle button presses.
In version 2.0 all buttons are polled in every iteration of the loop in main(). However only button X is used.
Button X: reset the Pico. The reset procedure takes about 9 seconds. This function has been added as an experiment. I could be useful for those who use a Raspberry Pi Pico that does not have an added hardware reset button.

The functionality of the buttons A, B and Y have been deleted. Pressing one of these buttons result in the message: 'BUTTON NOT IN USE'.

In version 2.0 has been added a class Cnt_it. This class is used to encapsulate the encoder count value and the reset flag. The Cnt_it class is defined in demo.hpp. An instance of this class, name: my_ctr is defined in line 37 of demo.cpp.

At start (boot up) of the Pico or before starting a reset by pressing button X, it is adviseable to set the rotary encoder button with the black index line in the 12 o'clock position.

If, at start of the program, no rgb encoder breakout pack is found, the program will display the message 'ENCODER NOT FOUND', then displaying the text: 'ENTERING INFINITE LOOP...' and entering in an infinite loop while blinking the built-in led of the Pico 1 time per second.

