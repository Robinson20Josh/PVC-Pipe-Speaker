//#include <ArduinoBLE.h>
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(70,6); //(Amount, Pin#)

unsigned long startTime = 0; // initialize the start time variable
boolean soundBelowThreshold = false; // initialize the flag variable

int soundSensorPin= 7;
int sound;
//boolean val =0;

void setup(){
Serial.begin (9600);
strip.begin();
strip.clear();
strip.setBrightness(20);

pinMode( 7, INPUT); // check 101 sound sensor project 
     
}
void loop (){

sound = digitalRead(soundSensorPin);
 if (sound == 1) {
 // fucntion light will display when sensor detects sound
 BouncingBrightness(strip.Color(random (0,255), random(0,255),random(0,255)), 10);
 strip.show();
  }


    if (sound == 0) {
  strip.clear();
  }
 
  }


void BouncingBrightness(uint32_t aColor, int anInterval) {
  static int brightness = 0;
  static boolean pixbrightness = true;

  // code for timer
  static unsigned long startTime = millis();
  unsigned long currentTime = millis();

  if (currentTime - startTime >= anInterval) {
    strip.clear();

    for (int index = 0; index < strip.numPixels(); index++) {
      strip.setPixelColor(index, aColor);
    }

    // if statement to brighten and dim lights

    if (pixbrightness == false) {
      brightness--;
    }

    if (pixbrightness == true) {
      brightness++;
    }
    if (brightness >= 255) {
      pixbrightness = false;
    }
    if (brightness <= 0) {
      pixbrightness = true;
    }

    // turn on current neopixel
    strip.setBrightness(brightness);
    strip.show();
    startTime = millis();
  }
}

//// Input a value 0 to 255 to get a color value.
//// The colours are a transition r - g - b - back to r.
//uint32_t Wheel(byte WheelPos) {
//  if (WheelPos < 85) {
//    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
//  }
//  else if (WheelPos < 170) {
//    WheelPos -= 85;
//    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
//  }
//  else {
//    WheelPos -= 170;
//    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
//  }
//}
//
//
//
//void rainbowTimer() { // modified from Adafruit example to make it a state machine
//  static unsigned long startTime = millis();
//  int interval = 20;
//  static uint16_t j = 0;
//
//
//  if (millis() - startTime >= interval){
//    for (int i = 0; i < strip.numPixels(); i++) {
//      strip.setPixelColor(i, Wheel((i + j) & 255));
//    }
//    strip.show();
//    j++;
//    if (j >= 256) j = 0;
//    startTime = millis(); // time for next change to the display
//  }
//}
