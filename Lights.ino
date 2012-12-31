//-------------------------
void initLights() 
{
  // set pins to output so you can control the shift register
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  
  currStep = 0;
}

//-------------------------
void writeLights()
{
  int val = 1 << currStep;
 
  digitalWrite(LATCH_PIN, LOW);  // set the latchPin LOW so the LEDs don't change while you're sending in bits
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, val);
  digitalWrite(LATCH_PIN, HIGH);  // set the latch pin HIGH so the LEDs will light up
    
  // increment the step
  currStep = (currStep + 1) % NUM_STEPS;
}
