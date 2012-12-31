#include "Globals.h"

#define DEBUG 1

//*************************
// PROGRAM VARIABLES
//*************************

//Pin connected to ST_CP of 74HC595 to D8 or D7 (green)
int latchPin = 7;
//Pin connected to SH_CP of 74HC595 to D12 or D6 (yellow)
int clockPin = 6;
////Pin connected to DS of 74HC595 to D11 or D5 (blue)
int dataPin = 5;

int mode;

int pot = A0;
int tempo;
int numberToDisplay;

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
  
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  numberToDisplay = 1;
  
  initModeSwitch();
}

//-------------------------
void loop() 
{
  readModeSwitch();
 
  tempo = analogRead(pot);
  
  if (numberToDisplay < 129) {
    // take the latchPin low so 
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW); 
    
    shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);
    
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    
    // increment the number for the next iteration:
    numberToDisplay = numberToDisplay*2;
    
    // pause before next value:
    delay(tempo);
  }
  else {
    numberToDisplay = 1;
  }
}
