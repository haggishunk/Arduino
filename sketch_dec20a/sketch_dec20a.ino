/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.

  To upload to your  or Trinket:
  1) Select the proper board from the Tools->Board Menu (Arduino Gemma if
     teal, Adafruit Gemma if black)
  2) Select the uploader from the Tools->Programmer ("Arduino Gemma" if teal, 
   "USBtinyISP" if black Gemma)
  3) Plug in the Gemma into USB, make sure you see the green LED lit
  4) For windows, make sure you install the right Gemma drivers
  5) Press the button on the Gemma/Trinket - verify you see
     the red LED pulse. This means it is ready to receive data
  6) Click the upload button above within 10 seconds
*/
 
int led = 0; // blink 'digital' pin 1 - AKA the built in red LED
int upper = 0; // upper led value
int lower = 0;
int step = 0;
int del = 0;
int bright = 0;
int i = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);

}

// the loop routine runs over and over again forever:
void loop() {
    
/*
 * BLINK WAVE
 * upper = sine(theta)
 * lower = 0
 * theta = 1/8*pi to 7/8*pi
 * step = pi/8
 * 
 */


 
 /*
 * GLOW PULSE
 * upper = 128
 * lower = 0
 * delay = 16
 * step = 8
 * repeat = 4
 */
upper = 128;
lower = 0;
step = 8;
del = 75;

i = 0;
while (i < 8) {
    analogWrite(led, bright);
    delay(del);
    bright = bright + step;
    if (bright <= lower || bright >= upper) {
        step = -step;
        i++;
      }
  }

}
