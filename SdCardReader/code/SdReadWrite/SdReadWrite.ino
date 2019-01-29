/*
   SD card read/write for Arduino Micro
*/
//================================================================================
#include <SPI.h>
#include <SD.h>
//================================================================================
const int chipSelectPin = 8; // Micro pin connected to pin D3 (Sparkfun) or CS (Adafruit)
//================================================================================
String filename = "sensor.txt";
String textToWrite = "Hello.";
//================================================================================
void setup()
{
  //------------------------------------------------------------------------------
  setupSerial();
  //------------------------------------------------------------------------------
  initiliaseSdCard(chipSelectPin);
  //------------------------------------------------------------------------------
  writeTextToSdFile(filename, textToWrite);
  //------------------------------------------------------------------------------
  readEntireFileFromSd(filename);
  //------------------------------------------------------------------------------
}

void loop()
{
  int sensorValue = analogRead(A0);
  writeTextToSdFile(filename, String(sensorValue));
  delay(5000);
}


