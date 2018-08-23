/*
		Eled.h - Easy led Rgb
		Library for easy use some effect with Adafruit Neopixel
		*Based on Adafruit_NeoPixel library
		
		Created by: Trafitto
*/

#ifndef Eled_h
#define Eled_h

#include "Arduino.h"
#include "Adafruit_NeoPixel.h"
class Eled
{
		public:
			Eled(int nLed,int pin);
			void setAllOff();
			void BreathBlue(float MaximumBrightness,float SpeedFactor,float StepDelay); 
			void colorWipe(uint32_t c, uint8_t wait); //From Adafruit library example
			void rainbow(uint8_t wait); //From Adafruit library example
			void theaterChase(uint32_t c, uint8_t wait); //From Adafruit library example
			void theaterChaseRainbow(uint8_t wait); //From Adafruit library example
			
		private:
			uint32_t Wheel(byte WheelPos);   //From Adafruit library example
			Adafruit_NeoPixel _strip;
			int _nLed; //Number of the led in a strip
			int _pin;
};
#endif