#include <Eled.h>

int pin 16;
int nLed=60;

//Init led strip
Eled eled(nLed,pin);


void setup() {
 
  eled.setAllOff();
}

void loop(){

  eled.BreathBlue(255,0.008,5);
}

