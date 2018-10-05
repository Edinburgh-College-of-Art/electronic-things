void writeToSdFile(String filename)
{
  File writeFile = SD.open(filename, FILE_WRITE); // only one file can be open at a time so, you have to close this one before opening another.

  if (writeFile) // if the file opened okay, write to it:
  {
    Serial.print("Writing to test.txt...");
    writeFile.println("testing 1, 2, 3.");
    writeFile.close();
    Serial.println("done.");
  }
  else
  {
    fileOpenError(filename);
  }
}

void readEntireFileFromSd(String filename)
{
  File readFile = SD.open(filename);
  if (readFile)
  {
    Serial.print(filename); Serial.println(" :");

    while (readFile.available()) // read from the file until there's nothing else in it:
    {
      Serial.write(readFile.read());
    }
    readFile.close();
  }
  else
  {
    fileOpenError(filename);
  }
}

// This is where you can take some action if something goes wrong, blink an LED, save the data elsewhere &c...
void fileOpenError(String filename)
{
  Serial.print("error opening "); Serial.println(filename);// if the file didn't open, print an error:
}

