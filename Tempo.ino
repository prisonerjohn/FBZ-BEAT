//-------------------------
void initTempo() 
{
  tempo = 0;
}

//-------------------------
void readTempo()
{
  tempo = analogRead(KNOB_TEMPO);
}
