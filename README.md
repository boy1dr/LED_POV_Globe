# LED_POV_Globe
Make an 8x RGB LED POV globe. (Persistence of vision, Arduino)

See it running here
 https://youtu.be/0UaTpHEGnHw
 https://youtu.be/WNXS8rF-QKY
 
The supplied Arduino files are experimental, you will need to adjust to suit your project.

I originally used a Leostick but a Nano would suffice. LED's: Common Anode/Cathode, doesn't matter.


Basic mode of operation.

Since having 8 RGB LED's connected would require 8x4 pins on the Arduino we need to optimise the circuit a little. This is achieved by displaying 1 colour at a time. All RGB LED's have 4 pins. One for ground or supply and 1 for each colour (RGB). Connect all 8 RED pins together. Then connect all 8 BLUE together, then all GREEN. 
These 3 common wires connect to 3 pins on the Arduino. 
The remaining wire for each LED (ground or supply) connects to a separate pin on the Arduino.

So to control 8 RGB LED's you need to have only 12 pins.
