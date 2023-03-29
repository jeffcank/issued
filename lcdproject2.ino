#include "Arduino.h"
#include "uRTCLib.h"
#include <LiquidCrystal.h>

// uRTCLib rtc;
uRTCLib rtc(0x68);

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//LCD pin to Arduino
const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 

const int pin_BL = 10; 

LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);

#include <Wire.h>

// Set I2C bus to use: Wire, Wire1, etc.
#define WIRE Wire

void setup() {
 

  URTCLIB_WIRE.begin();

  // Comment out below line once you set the date & time.
  // Following line sets the RTC with an explicit date & time
  // for example to set January 13 2022 at 12:56 you would call:
 // rtc.set(0, 12, 13, 1, 26, 3, 23);
  // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
  // set day of week (1=Sunday, 7=Saturday)
  lcd.begin(16, 2);

}

void loop() {
  rtc.refresh();
   


  lcd.setCursor(4,0);
  
   if(rtc.hour() < 10){           // Zero padding if value less than 10 ie."09" instead of "9"
      lcd.print("0");
   }
  lcd.print(rtc.hour());
  lcd.print(':');

   if(rtc.minute() < 10){           // Zero padding if value less than 10 ie."09" instead of "9"
      lcd.print("0");
   }
  
  lcd.print(rtc.minute());
  
  lcd.print(':');

  if(rtc.second() < 10){           // Zero padding if value less than 10 ie."09" instead of "9"
      lcd.print("0");
   }
  
  lcd.print(rtc.second()); 
  
  lcd.setCursor(4,1);
  
     if(rtc.day() < 10){           // Zero padding if value less than 10 ie."09" instead of "9"
      lcd.print("0");
   }
 
  lcd.print(rtc.day());
  lcd.print('/');
     if(rtc.month() < 10){           // Zero padding if value less than 10 ie."09" instead of "9"
      lcd.print("0");
   }
  
  lcd.print(rtc.month());
  lcd.print('/');
  
      if(rtc.year() < 10){           // Zero padding if value less than 10 ie."09" instead of "9"
      lcd.print("0");
   }

  lcd.print(rtc.year());
  
  delay(1000);
  
}
