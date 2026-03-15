# slotmachineArduino
Simple slot machine project, based on an Arduino MEGA with a 64x32 RGB LED matrix.

# Presentation [(May Golshi help me)](https://www.youtube.com/shorts/HzwK-xqT4yc)
## What's this machine?
It's a slot machine you can find in casinos. It was meant to decorate the room for the school's Gala in 2026, which theme was "Royal Casino".
## How does it works? User edition
This machine uses 5 reels with 3 symbols each, means that you display 15 symbols at each pull. I chose to be Mr. Not Nice At All, you need to have 5 of a symbol to be able to win.
#### The payline AKA "Why do you need 5 symbols and WHY IT'S NOT A LINE????"
A payline in a slot machine is defined by the type of machine you use. In this case, you need 5 symbols, thus the payline is always defined as a group of 5 symbols.

**DEFINITION**: a payline is a group of 5 compatible symbols, each one coming from a different reel. Symbols are compatible if they are the same symbol **OR** one of them is the wild symbol (the joker hat here). Exeption is made for the scatter symbol (the casino coin), which is compatible with itself only.
## How to build the machine?
1. Hardware: get an Arduino MEGA, an 64x32 RGB Matrix,  some wires, a button. Build the box out of what you have, I made mine with 8.5 mm MDF.
2. Software: get the Arduino IDE and install Adafruit's RGBMatrixPanel lib.
3. Follow the wiring scheme: ![Wiring scheme, good luck if it's not displaying](./images/MBOT.png)
It's normal for pin A7 to be floating, it's used to create a simili-random seed in [SlotMachine_Gala_2026.ino](./src/SlotMachine_Gala_2026/SlotMachine_Gala_2026.ino).
4. Power: you need 5V/500mA to be chill, so any phone charger may be enough.
## How does it works? Dev edition
### [was.h](./src/SlotMachine_Gala_2026/was.h): is it even working?
"Wait A Second" is a non blcoking timer I've developped for the project. Feel free to use it if it even works.
### [pile.h](./src/SlotMachine_Gala_2026/pile.h): this is surely not working.
A pile structure used in [reels_and_random_logic.h](./src/SlotMachine_Gala_2026/reels_and_random_logic.h) to keep track of the symbol whom you're checking victory condition. May crash for whatever reason when changing max array size, forgot how it works exactly and no time to fix it.
### [matrix_text.h](./src/SlotMachine_Gala_2026/matrix_text.h): the GUI
Contains all the functions for [rollin' rollin' rollin' rollin'](https://www.youtube.com/watch?v=RYnFIRc0k6E) the reels.
### [images.h](./src/SlotMachine_Gala_2026/images.h): The nice looking icons to display
Contains all the images in 565 RGB format, and the function that we'll be using to display them on the screen.
### [reels_and_random_logic.h](./src/SlotMachine_Gala_2026/reels_and_random_logic.h): the awful losing machine
You can find the reels and the sybols comparator here. It's this part of the code, with the *selectRandom()* function, that determines the positions of the reels. Be careful: I've locked it to maximum 3 winning paylines, since we were meant to make people win soft drinks.
### [SlotMachine_Gala_2026.ino](./src/SlotMachine_Gala_2026/SlotMachine_Gala_2026.ino): the complete project
This declares the *matrix* object, the button logic of the lever, and makes the whole thing run.
## Why you should maybe do your own project on your side and not copypasting my code:
Well you might have seen that only 55 of the 243 paylines are enabled. In fact, you can't enable more than 200 of them because the whole thing crashes at start if so. Worse, even with only 55, it crashes after 20 or 30 pulls. And since I'm lazy and I don't have time to fix this properly, this might clearly be left as it.
