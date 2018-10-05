void printCardType(Sd2Card sdCard)
{
  Serial.println();
  Serial.print("Card type:         ");
  switch (sdCard.type()) 
  {
    case SD_CARD_TYPE_SD1:
      Serial.println("SD1");
      break;
    case SD_CARD_TYPE_SD2:
      Serial.println("SD2");
      break;
    case SD_CARD_TYPE_SDHC:
      Serial.println("SDHC");
      break;
    default:
      Serial.println("Unknown");
  }
}


void printVolumeDetails(SdVolume sdVolume)
{
    //------------------------------------------------------------------------------
  Serial.print("Clusters:          ");
  Serial.println(sdVolume.clusterCount());
  Serial.print("Blocks x Cluster:  ");
  Serial.println(sdVolume.blocksPerCluster());
  //------------------------------------------------------------------------------
  Serial.print("Total Blocks:      ");
  Serial.println(sdVolume.blocksPerCluster() * volume.clusterCount());
  Serial.println(); 
  //------------------------------------------------------------------------------
  // print the type and size of the first FAT-type volume
  uint32_t volumesize;
  Serial.print("Volume type is:    FAT");
  Serial.println(sdVolume.fatType(), DEC);

  volumesize = sdVolume.blocksPerCluster();    // clusters are collections of blocks
  volumesize *= sdVolume.clusterCount();       // we'll have a lot of clusters
  volumesize /= 2;                           // SD card blocks are always 512 bytes (2 blocks are 1KB)
  Serial.print("Volume size (Kb):  ");
  Serial.println(volumesize);
  Serial.print("Volume size (Mb):  ");
  volumesize /= 1024;
  Serial.println(volumesize);
  Serial.print("Volume size (Gb):  ");
  Serial.println((float)volumesize / 1024.0);
}

void checkCardStatus (bool cardInitialised)
{
  if (!cardInitialised) 
  {
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card inserted?");
    Serial.println("* is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
    while (1);
  } 
  else 
  {
    Serial.println("Wiring is correct and a card is present.");
  }
}

void checkVolumeStatus(bool volumeInitialised)
{
  if (!volumeInitialised) 
  {
    Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
    while (1);
  }
}
