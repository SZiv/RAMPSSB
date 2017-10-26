# RAMPSSB
Be sure to take a look at the Wiki before attempting a build: http://reprap.org/wiki/RAMPSSB and if you are curious more as to the development and technological reasoning behind this project, take a look at my blog post at http://scottziv.com/rampssb-bringing-closed-loop-dc-motor-control-to-3d-printers/

RAMPS Servo Board. Released under GPLv3.

Replaces the X and Y stepper drivers on a RAMPS CNC control board with two channel DC motor quadrature encoder control using cheap, common, easy to solder components.

Uses a square L298N DC motor driver, attached with standoffs to the PCB, over 2 Arduino Pro Micros for control. PCB board is less than 100m square, so it can be produced for $5 + shipping from Seeedstudio, and the L298N driver board is cheap (like $3), and the controllers, Pro Micros, are maybe 5 bucks a piece.

For more steppers, this is compatable with the Reprap.me stepper expander, or, with some modification, my other board, the RAMPSXB. 

Can also be used as a simple non-RAMPS step/direction to DC encoder motor setup by directly wiring the pins. 

The firmware could use some work, and I am slowly developing it. It does function, but it is not as stable as I would like. If anyone has better luck with control software, let me know and I can add it to the official repo.  
