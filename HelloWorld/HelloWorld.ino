#include <Adafruit_LiquidCrystal.h>
#include <DHT.h>
#define DHT11_PIN 2

DHT dht(DHT11_PIN, DHT11); // Create an instance of the DHT class

//2016.12.9

/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>
int hour = 4;
long min = 45;
long tempchecker;
long sec;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  Serial.begin(9600);
  dht.begin(); // Initialize the sensor
}

void loop() {
  float temperature = dht.readTemperature(); // Read temperature
  float humidity = dht.readHumidity(); // Read humidity
  lcd.print("Temp = ");
  lcd.print(temperature);
  Serial.print("Temperature = ");
  Serial.println(temperature);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  lcd.print("Humidity = ");
  lcd.print(humidity);

  // print the number of seconds since reset:
  sec = (millis()/1000) + 50;
  //lcd.print(hour);
  //lcd.print(":");
  //lcd.print(min);
  //lcd.print(":");
  if(sec<10)
  {
    //lcd.print(0);
    //lcd.print(sec % 60);
  }
  //else lcd.print(sec % 60);
  if(sec%60 == 0 )
  {
    tempchecker++;
    if(tempchecker == 1)checker();
    if (sec%60)tempchecker = 0;
  }
  else if(min%60 == 0)
  {
    hour++;
    min = 0;
    sec = 0;
  }
}
void checker()
{
  min++;
  sec = 1;
}

