#include <Adafruit_NeoPixel.h>

#define NUM_LEDS 1
#define PIN 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN);

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.setBrightness(100);
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:

  // loop through 256 colors
  for(int j=0; j<256; j++) {
    // loop through neopixels
    for(int i=0; i<NUM_LEDS; i++){
      // set a color for the neopixel
      // color is shifted 8 bits for each progressive neopixel
      strip.setPixelColor(i, Wheel((i * 8 + j) & 255));
    }
    // show once all neopixels are set with new color
    strip.show();
    delay(20);
  }
}

uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85){
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170){
    WheelPos -= 85;
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else{
    WheelPos -= 170;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
