/*
   SD card read/write for Arduino Micro
*/
//================================================================================
#include <SPI.h>
#include <SD.h>
//================================================================================
const int chipSelect = 10; // Micro pin connected to pin D3 (Sparkfun) or CS (Adafruit)
void setup()
{
  setupSerial();

  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect))
  {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  writeToSdFile("test.txt");
  readEntireFileFromSd("test.txt");
}

void loop()
{
}


