# slotmachineArduino
Simple slotmachine project, based on an Arduino MEGA with a 64x32 RGB LED matrix.

# Presentation (May Golshi help me)
## How to build the machine?
1. Hardware: get an Arduino MEGA, an 64x32 RGB Matrix,  some wires, a button. Build the box out of what you have, I made mine with 8.5 mm MDF.
2. Software: get the Arduino IDE and install Adafruit's RGBMatrixPanel lib.
3. Follow the wiring scheme: ![Wiring scheme, good luck if it's not displaying](./images/scheme.jpg)
4. Power: you need 5V/500mA to be chill, so any phone charger may be enough.
## How does it works?
### was.h: is it even working?
A non blcoking timer I've developped for the project. Feel free to use it if it even works.
### pile.h: this is surely not working.
A pile structure used in

[reels_and_random_logic.h]:(./blob/main/src/SlotMachine_Gala_2026/reels_and_random_logic.h)

to keep track of the symbol whom you're checking victory condition. 
