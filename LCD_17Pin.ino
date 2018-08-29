// **********************************************************
//   LCD_17Pin.ino
//
//   Using three 74HC595 IC's, this allows a 17 pin salvaged 
//   LCD display to show time digitally. It shifts out specific 
//   sequences of bits to the LCD's 17 pin to display the 
//   desired digits. Pardon the mess.
//   
//   Author: Michael Katilevsky
//
//   13 December 2015
//
// **********************************************************

// Define which Arduino pins will correspong to the 74HC595 pins
const byte latchPin = 4;
const byte dataPin = 5;
const byte clockPin = 6;

byte Seconds;
byte TenSeconds;
byte Minutes;
byte TenMinutes;

int duration;

void setup() 
{
  Seconds = 0;
  TenSeconds = 0;
  Minutes = 0;
  TenMinutes = 0;
  
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  duration = 60000; // update the smallest digit every 60 000 milliseconds (1 minute)
}

void loop() 
{
  long startTime = millis();
  
  while(millis()-startTime < duration)
  {
  seconds();
  tenSeconds();
  minutes();
  tenMinutes();
  }

  ++Seconds; // increment the smallest digit (minutes, in this case)
}



void seconds()
{
  if(Seconds >= 10)
  {
    Seconds = 0;
    ++TenSeconds;
  }

  cleanDigits();

  if(Seconds == 0)
  {
    //ZERO --- 0
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00100000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00100000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000101);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(Seconds == 1)
  {
    //ONE --- 1
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000011);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(Seconds == 2)
  {
    //TWO --- 2
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00100000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00100000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(Seconds == 3)
  {
    //THREE --- 3
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00100000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00100000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000101);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(Seconds == 4)
  {
    //FOUR --- 4

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00110000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00100000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(Seconds == 5)
  {
    //FIVE --- 5
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
   
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00100000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00100000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(Seconds == 6)
  {
    //SIX --- 6
        
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00100000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00100000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH); 
  }

  else if(Seconds == 7)
  {
    //SEVEN --- 7
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000111);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(Seconds == 8)
  {
    //EIGHT --- 8
        
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00100000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00100000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000111);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(Seconds == 9)
  {
    //NINE --- 9
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00100000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00010000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000110);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00100000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }
}

void tenSeconds()
{
  if(TenSeconds >= 6)
  {
    TenSeconds = 0;
    ++Minutes;
  }
  
cleanDigits();

if(TenSeconds == 0)
{
  // ZERO --- 0
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000101);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);
  }

else if(TenSeconds == 1)
{
  //ONE --- 1
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000011);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);


  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);
  }

else if(TenSeconds == 2)
{
  // TWO --- 2

  
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

else if(TenSeconds == 3)
{
  //THREE --- 3
  
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000101);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(TenSeconds == 4)
  {
  //FOUR --- 4
  
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B11000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(TenSeconds == 5)
  {
    //FIVE --- 5
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
   
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(TenSeconds == 6)
  {
    //SIX --- 6

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(TenSeconds == 7)
  {
    //SEVEN --- 7

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000111);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);
  }

  else if(TenSeconds == 8)
  {
   //EIGHT --- 8

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000111);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(TenSeconds == 9)
  {
    //NINE --- 9

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B01000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000110);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }
}

void minutes()
{
  if(Minutes >= 10)
  {
    Minutes = 0;
    ++TenMinutes;
  }

cleanDigits();

if(Minutes == 0)
{
  // ZERO --- 0
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B10000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B10000010);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000101);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);
  }

else if(Minutes == 1)
{
  //ONE --- 1
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000011);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);
  }

else if(Minutes == 2)
{
  // TWO --- 2
  
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B10000100);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(Minutes == 3)
  {
    //THREE --- 3
  
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B10000101);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(Minutes == 4)
  {
  //FOUR --- 4
  
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B10000001);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(Minutes == 5)
  {
    //FIVE --- 5
   
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B10000001);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(Minutes== 6)
  {
    //SIX --- 6

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(Minutes == 7)
  {
    //SEVEN --- 7

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000111);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);
  }

  else if(Minutes == 8)
  {
   //EIGHT --- 8

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000111);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else if(Minutes == 9)
  {
    //NINE --- 9

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000001);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000110);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B10000001);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }
}

void tenMinutes()
{
  if(TenMinutes >= 3)
  {
    Seconds = 0;
    TenSeconds = 0;
    Minutes = 0;
    TenMinutes = 0;
  }

  cleanDigits();
  
  if(TenMinutes == 0)
  {
   if(Minutes == 4)
   {
    ; 
   }

   else
   {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
   }
  }

  else if(TenMinutes == 1)
  {
    //ONE --- 1
  
  if(Minutes == 4)
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }

  else
  {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);
  }
    
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B01000010);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B01000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);
  }

  else if(TenMinutes == 2)
  {
    // TWO --- 2
    
    if(Minutes == 4)
    {
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
      shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
      shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
      digitalWrite(latchPin, HIGH);
    }
  
    else
    {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B10000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
    }
      
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B01000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B01000001);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
    digitalWrite(latchPin, HIGH);
  }
}

// Resets the display so that the next digit can be drawn crispy clean.
// Otherwise electrical current bleeds through and digits seem blurry.
void cleanDigits()
{  
  for(byte counter = 0; counter < 4; counter++)
  {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                     //Rightmost LCD pin
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);                            //LeftmostLCD pin
  digitalWrite(latchPin, HIGH);
  }
}
