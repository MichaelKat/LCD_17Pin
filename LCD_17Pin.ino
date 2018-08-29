// **********************************************************
//   LCD_17Pin.ino
//
//   Using three 74HC595 IC's, all 17 pins of an LCD can be 
//   controlled at once to display any desired digits. 
//   In this program, the LCD is used as a digital clock.
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

byte minutes;
byte tenMinutes;
byte hours;
byte tenHours;

int duration;

void setup() 
{
  minutes = 0;
  tenMinutes = 0;
  hours = 0;
  tenHours = 0;
  
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
  minutesUpdate();
  tenMinutesUpdate();
  hoursUpdate();
  tenHoursUpdate();
  }

  ++minutes; // increment the minutes
}



void minutesUpdate()
{
  if(minutes >= 10)
  {
    minutes = 0;
    ++tenMinutes;
  }

  cleanDigits();

  if(minutes == 0)
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

  else if(minutes == 1)
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

  else if(minutes == 2)
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

  else if(minutes == 3)
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

  else if(minutes == 4)
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

  else if(minutes == 5)
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

  else if(minutes == 6)
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

  else if(minutes == 7)
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

  else if(minutes == 8)
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

  else if(minutes == 9)
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

void tenMinutesUpdate()
{
  if(tenMinutes >= 6)
  {
    tenMinutes = 0;
    ++hours;
  }
  
cleanDigits();

if(tenMinutes == 0)
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

else if(tenMinutes == 1)
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

else if(tenMinutes == 2)
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

else if(tenMinutes == 3)
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

  else if(tenMinutes == 4)
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

  else if(tenMinutes == 5)
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

  else if(tenMinutes == 6)
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

  else if(tenMinutes == 7)
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

  else if(tenMinutes == 8)
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

  else if(tenMinutes == 9)
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

void hoursUpdate()
{
  if(hours >= 10)
  {
    hours = 0;
    ++tenHours;
  }

cleanDigits();

if(hours == 0)
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

else if(hours == 1)
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

else if(hours == 2)
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

  else if(hours == 3)
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

  else if(hours == 4)
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

  else if(hours == 5)
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

  else if(hours== 6)
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

  else if(hours == 7)
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

  else if(hours == 8)
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

  else if(hours == 9)
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

void tenHoursUpdate()
{
  if(tenHours >= 3)
  {
    minutes = 0;
    tenMinutes = 0;
    hours = 0;
    tenHours = 0;
  }

  cleanDigits();
  
  if(tenHours == 0)
  {
   if(hours == 4)
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

  else if(tenHours == 1)
  {
    //ONE --- 1
  
  if(hours == 4)
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

  else if(tenHours == 2)
  {
    // TWO --- 2
    
    if(hours == 4)
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
