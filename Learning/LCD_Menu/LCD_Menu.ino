/*
  LiquidCrystal Library - setCursor

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints to all the positions of the LCD using the
 setCursor() method:

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalSetCursor

 */

// include the library code:
#include <LiquidCrystal.h>

// these constants won't change.  But you can change the size of
// your LCD using them:
const int numRows = 3;
const int numCols = 16;
const int buttonPin = 13;

char* menu[3] = {">Push me!", ">Or me!", ">Off screen!"};
//const char* menu1 = ">Push me!";
//const char* menu2 = ">Or me!";
//const char* menu3 = ">Off screen!";

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

int pushed = 0;
int row = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  pinMode(buttonPin, INPUT);
  lcd.begin(numCols, numRows);
  Serial.begin(9600);

  lcd.write(menu[0]);
  lcd.setCursor(0,1);
  lcd.write(menu[1]);
  lcd.setCursor(0,0);
  lcd.cursor();
}

void loop() {
  if (digitalRead(buttonPin) == LOW){
    if (row == numRows){
      row = 0;
      //move cursor 
      scrollDown(row, row+1);
      row++;
    }
    else{
      //move cursor
      scrollDown(row, row+1);
      row++;
    }
    
    //lcd.setCursor(0, row);
    //debounce
    delay(300);
  }  
}

void scrollDown(int current, int next){
  Serial.println(current);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write(menu[current]);
  
  lcd.setCursor(0, 1);
  lcd.write(menu[next]);
  if (current == 0){
    lcd.setCursor(0,0);
  }
  else{
    lcd.setCursor(0, 1);
  }
  lcd.cursor();
}


