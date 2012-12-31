//-------------------------
void initModeSwitch() 
{
  mode = -1;
}

//-------------------------
void readModeSwitch()
{
  boolean switchMode1 = analogRead(SWITCH_MODE_1);
  boolean switchMode2 = analogRead(SWITCH_MODE_2);
  int newMode;
  if (!switchMode1 && switchMode2) {
    newMode = MODE_BANK_SEL;
  }
  else if (!switchMode1 && !switchMode2) {
    newMode = MODE_PATTERN;
  }
  else {
    newMode = MODE_LIVE_PLAY;
  }
  
  if (mode != newMode) {
    mode = newMode;
#ifdef DEBUG
    Serial.println("***** MODE SWITCH *****");
    Serial.println(mode);
    Serial.println("***********************");
#endif
  }
}
