//================================================================================

void initiliaseSdCard(int csPin)
{
  Serial.print("Initializing SD card...");
  if (!SD.begin(csPin))
  {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
}

//================================================================================

void writeTextToSdFile(String fileNameToWrite, String writeText)
{
  File writeFile = SD.open(fileNameToWrite, FILE_WRITE); // only one file can be open at a time so, you have to close this one before opening another.

  if (writeFile) // if the file opened okay, write to it:
  {
    Serial.print("Writing to test.txt...");
    writeFile.println(writeText);
    writeFile.close();
    Serial.println("done.");
  }
  else
  {
    fileOpenError(fileNameToWrite);
  }
}

//================================================================================

void readEntireFileFromSd(String filenameToRead)
{
  File readFile = SD.open(filenameToRead);
  if (readFile)
  {
    Serial.print(filenameToRead); Serial.println(" :");

    while (readFile.available()) // read from the file until there's nothing else in it:
    {
      Serial.write(readFile.read());
    }
    readFile.close();
  }
  else
  {
    fileOpenError(filenameToRead);
  }
}

// This is where you can take some action if something goes wrong, blink an LED, save the data elsewhere &c...
void fileOpenError(String filename)
{
  Serial.print("error opening "); Serial.println(filename);// if the file didn't open, print an error:
}

