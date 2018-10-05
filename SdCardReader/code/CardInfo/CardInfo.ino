/*
 * SD card test for Arduino Micro
 */
//================================================================================
#include <SPI.h>
#include <SD.h>
//================================================================================
Sd2Card card;
SdVolume volume;
SdFile root;
//================================================================================
const int chipSelect = 10; // Micro pin connected to pin D3 (Sparkfun) or CS (Adafruit)
//================================================================================
void setup() 
{
  //------------------------------------------------------------------------------
  setupSerial();
  Serial.print("\nInitializing SD card...");
  //------------------------------------------------------------------------------
  bool cardStatus = card.init(SPI_HALF_SPEED, chipSelect);
  checkCardStatus(cardStatus);
  printCardType(card);  
  //------------------------------------------------------------------------------
  bool volumeStatus = volume.init(card);
  checkVolumeStatus(volumeStatus);
  printVolumeDetails(volume);
  //------------------------------------------------------------------------------
  Serial.println("\nFiles found on the card (name, date and size in bytes): ");
  root.openRoot(volume);
  //------------------------------------------------------------------------------
  // list all files in the card with date and size
  root.ls(LS_R | LS_DATE | LS_SIZE);
   //------------------------------------------------------------------------------
}
//================================================================================
void loop(void) 
{
}
