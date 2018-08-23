/*
		Eled.cpp - Easy led Rgb
		Library for easy use some effect with Adafruit Neopixel
		*Based on Adafruit_NeoPixel library
		
		Created by: Trafitto
*/


#include "Arduino.h"
#include "Eled.h"
#include "Adafruit_NeoPixel.h"

Adafruit_NeoPixel _strip;
int _nLed;
int _pin;
Eled::Eled(int nLed,int pin)
{
	_strip=Adafruit_NeoPixel(nLed, pin, NEO_GRB + NEO_KHZ800);
	_nLed=nLed;
	_pin=pin;
	
	//setAllOff();
}

void Eled::setAllOff()
{
	_strip.begin();
	_strip.show(); 
}

//Breath in blue color
//Breath(255,0.005,5)
void Eled::BreathBlue(float MaximumBrightness,float SpeedFactor,float StepDelay)
{
  
      // Make the lights breathe
      for (int i = 0; i < 65535; i++) {
      // Intensity will go from 10 - MaximumBrightness in a "breathing" manner
      float intensity = MaximumBrightness /2.0 * (1.0 + sin(SpeedFactor * i));
      _strip.setBrightness(intensity);
      // Now set every LED to that color
      for (int ledNumber=0; ledNumber<_nLed; ledNumber++) {
      _strip.setPixelColor(ledNumber, 0, 0, 255);
      }
      
      _strip.show();
      //Wait a bit before continuing to breathe
      delay(StepDelay);
      
      }
}

/* ----- Effect from Adafruit neopixel example ------- */


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Eled::Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return _strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return _strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return _strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


// Fill the dots one after the other with a color
void Eled::colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<_strip.numPixels(); i++) {
    _strip.setPixelColor(i, c);
    _strip.show();
    delay(wait);
  }
}


void Eled::rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<_strip.numPixels(); i++) {
      _strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    _strip.show();
    delay(wait);
  }
}


//Theatre-style crawling lights.
void Eled::theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < _strip.numPixels(); i=i+3) {
        _strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      _strip.show();

      delay(wait);

      for (uint16_t i=0; i < _strip.numPixels(); i=i+3) {
        _strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}


//Theatre-style crawling lights with rainbow effect
void Eled::theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < _strip.numPixels(); i=i+3) {
        _strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      _strip.show();

      delay(wait);

      for (uint16_t i=0; i < _strip.numPixels(); i=i+3) {
        _strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}



/* ----- End effect from Adafruit neopixel example ------- */