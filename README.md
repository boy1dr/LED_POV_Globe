# LED_POV_Globe
Make an 8x RGB LED POV globe. (Persistance of vision, arduino)

The supplied Arduino files are experimental, you will need to adjust to suit your project.

Originaly used a Leostick but a Nano would suffice.
LED's: Common Anode/Cathode, doesn't matter.

Basic mode of operation.

Since having 8 RGB LED's connected would require 8x3 pins on the arduino we need to optimize the circuit a little.
This is achieved by displaying 1 color at a time.
All RGD LED's have 4 pins. One for ground or supply and 1 for each color (RGB).
Connect all 8 RED pins together. Then connect all 8 BLUE together, then all GREEN.
These 3 common wires connect to 3 pins on the arduino.
The remaining wire for each LED (ground or supply) connects to a seperate pin on the arduino.

So to control 8 RGB LED's you need to have only 12 pins.
