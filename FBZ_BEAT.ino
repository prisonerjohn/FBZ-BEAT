//Pin connected to ST_CP of 74HC595to D8 or D7 (green)
int latchPin = 7;
//Pin connected to SH_CP of 74HC595 to D12 or D6 (yellow)
int clockPin = 6;
////Pin connected to DS of 74HC595 to D11 or D5 (blue)
int dataPin = 5;

int pot = A0;
int tempo;

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  Serial.begin(9600);
  tempo = analogRead(pot);
  // count from 0 to 255 and display the number 
  // on the LEDs
  for (int numberToDisplay = 1; numberToDisplay < 129; numberToDisplay = numberToDisplay*2) {
    // take the latchPin low so 
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW); 
    // shift out the bits:
    //shiftOut(dataPin, clockPin, MSBFIRST, 1); //LED 1
    //shiftOut(dataPin, clockPin, MSBFIRST, 2); //LED 2
    //shiftOut(dataPin, clockPin, MSBFIRST, 3); //LED 1 & 2
    //shiftOut(dataPin, clockPin, MSBFIRST, 4); //LED 3
    //shiftOut(dataPin, clockPin, MSBFIRST, 8); //LED 4
    //shiftOut(dataPin, clockPin, MSBFIRST, 16); //LED 5
    //shiftOut(dataPin, clockPin, MSBFIRST, 32); //LED 6
    //shiftOut(dataPin, clockPin, MSBFIRST, 64); //LED 7
    //shiftOut(dataPin, clockPin, MSBFIRST, 128); //LED 8
    
      shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay); //LED 2
      //Serial.println(numberToDisplay);

    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    // pause before next value:
    delay(tempo);
 }
 
 
}
