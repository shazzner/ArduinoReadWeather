/*

    Indoor Weather sensor sketch
    By: Chris Hardee
    Date: August 29, 2015

    Based on the MPL3115A2 Barometric Pressure Sensor Library and the HTU21D Humidity Sensor from Sparkfun
 
*/

#include <Wire.h>
#include "MPL3115A2.h"
#include "HTU21D.h"

//Create an instance of the object
//MPL3115A2 myPressure;
HTU21D myHumidity;

void setup()
{
  //Wire.begin();        // Join i2c bus
  Serial.begin(9600);  // Start serial for output

  //myPressure.begin(); // Get sensor online
  myHumidity.begin();
  
  //myPressure.setModeBarometer(); // Measure pressure in Pascals from 20 to 110 kPa
  
  //myPressure.setOversampleRate(7); // Set Oversample to the recommended 128
  //myPressure.enableEventFlags(); // Enable all three pressure and temp event flags 
}

void loop()
{
  float humd = myHumidity.readHumidity();
  float temp = myHumidity.readTemperature();

  Serial.print("Temperature:");
  Serial.print(temp, 1);
  Serial.print("C");
  Serial.print(" Humidity:");
  Serial.print(humd, 1);
  Serial.print("%");

  Serial.println();
  delay(1000);
}
