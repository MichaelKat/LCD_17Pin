# LCD_17Pin
Using 74HC595's to shiftout bits to control a salvaged LCD with 17 input pins.

More specifically, using three 74HC595 IC's, we can control 17 pins at once and have the 
LCD display whatever digits we want. This version of the code uses the LCD as a digital clock. 
It shifts out specific sequences of bits to the LCD's 17 pin to display the desired digits.

Please, beware, this code is fine-tuned for my LCD and is most likely of no help to anyone else.
However, it does showcase how to easily and purposefully use 74HC595 shift registers.

Disclaimer: I was not very experienced at the time of writing this code - it is not the prettiest code.
   
Author: Michael Katilevsky

13 December 2015
