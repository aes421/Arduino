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
const int scrollPin = 12;
const int selectPin = 13;

char const * menu[3] = {">a-h", ">i-q!", ">r-z"};

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int row = 1;
int thisLetter;
int lastLetter;

void setup() {
  // set up the LCD's number of columns and rows:
  pinMode(scrollPin, INPUT);
  pinMode(selectPin, INPUT);
  lcd.begin(numCols, numRows);
  Serial.begin(9600);

  lcd.write(menu[0]);
  lcd.setCursor(0,1);
  lcd.write(menu[1]);
  lcd.setCursor(0,0);
  lcd.cursor();
}

void loop() {
  if (digitalRead(scrollPin) == LOW){
    if (row == numRows){
      row = 0;
      //move cursor 
      scrollDown(row, row+1, row);
    }
    else{
      if (row%2 != 0){
        scrollDown(row-1, row, 1);
      }
      else{
        scrollDown(row, row+1, 0);
      }
    }

    row++;
    //debounce
    delay(300);
  } 
  
  if (digitalRead(selectPin) == LOW){
    select_item(row);
  }
}

void scrollDown(int top, int bottom, int current){

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write(menu[top]);
  
  lcd.setCursor(0, 1);
  lcd.write(menu[bottom]);
  
  lcd.setCursor(0,current);
  
  lcd.cursor();
}

void select_item(int i){
    lcd.clear();
    
    if (i == 1){
      thisLetter = 'a';
      lastLetter = 'h';
    }
    else if (i == 2){
      thisLetter = 'i';
      lastLetter = 'q';
    }
    else if (i == 3){
      thisLetter = 'r';
      lastLetter = 'z';
    }
    else{
      //Serial.println("Error in row number");
    }
    
    // loop from ASCII 'a' to ASCII 'z':
    for (int abcrow=0; abcrow < numRows;  abcrow++) {
      for (int abccol=0; abccol < numCols;  abccol++) {
          lcd.setCursor(abccol, abcrow);
          // print the letter:
          lcd.write(thisLetter);
          delay(200);
          if (thisLetter == lastLetter){
            abcrow = numRows;
            abccol = numCols;
          }
          else{
            thisLetter++;
          }
      }
    }
 }

