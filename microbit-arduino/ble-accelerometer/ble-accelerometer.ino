/*
   Send Accelerometer data over BLE
*/
//=============================================================================
#include <Adafruit_Microbit.h>
#include "Wire.h"
#include "MMA8653.h"
//=============================================================================
Adafruit_Microbit microbit;
MMA8653 accel;
//=============================================================================
void setup()
{
  Serial.begin(115200);
  accel.begin(false, 2);        // 8-bit mode, 2g range
  microbit.BTLESerial.begin();  // custom services and characteristics can be added as well
  microbit.BTLESerial.setLocalName("microbit");
  microbit.begin();             // Start LED matrix driver after radio (required)
}

//=============================================================================
void loop()
{
  microbit.BTLESerial.poll();
  sendBleAccl();
}

//=============================================================================
// periodically sent time stamps
void sendBleAccl()
{
  if (microbit.BTLESerial)
  {
    accel.update();
    microbit.BTLESerial.print((float)accel.getX() * 0.0156);
    microbit.BTLESerial.print(" , ");
    microbit.BTLESerial.print((float)accel.getY() * 0.0156);
    microbit.BTLESerial.print(" , ");
    microbit.BTLESerial.println((float)accel.getZ() * 0.0156);
    delay(100);
  }
}
