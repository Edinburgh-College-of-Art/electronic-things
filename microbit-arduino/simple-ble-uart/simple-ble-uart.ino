/*
 * Send 8bit number over serial
 */
//=============================================================================
#include <Adafruit_Microbit.h>
//=============================================================================
Adafruit_Microbit microbit;
int count = 0;
//=============================================================================
void setup()
{
  Serial.begin(115200);
  Serial.println("Microbit ready!");
  microbit.BTLESerial.begin(); // custom services and characteristics can be added as well
  microbit.BTLESerial.setLocalName("microbit");
  microbit.begin(); // Start LED matrix driver after radio (required)
}
//=============================================================================
void loop()
{
  microbit.BTLESerial.poll();
  bleSend();
}
//=============================================================================
void bleSend()
{
  if (microbit.BTLESerial)
  {
    microbit.BTLESerial.println(count++);
    count %= 16;
    delay(100);
  }
}
