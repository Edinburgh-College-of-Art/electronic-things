// you do the same thing over and over to setup serial, so save yourself a couple of lines and make a function
void setupSerial()
{ 
  Serial.begin(9600);
  while (!Serial) {  }
}
