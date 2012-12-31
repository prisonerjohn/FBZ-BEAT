#include "Globals.h"

#define DEBUG 1

//*************************
// PROGRAM VARIABLES
//*************************

int mode;
int tempo;

int currStep;

//*************************
// MAIN LOOP
//*************************

//-------------------------
void setup() 
{
#ifdef DEBUG
  Serial.begin(9600);
#else 
  Serial.begin(31250);  // MIDI
#endif
 
  initTempo();
  initModeSwitch();
  initLights();
}

//-------------------------
void loop() 
{
  readTempo();
  readModeSwitch();
  
  writeLights();
  
  delay(tempo);  // pause before next iteration
}
