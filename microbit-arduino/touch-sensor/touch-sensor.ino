/*
   Microbit Touch Sensor
*/
#include <Adafruit_Microbit.h>
Adafruit_Microbit_Matrix microbit;
//==============================================================================
bool state = false;
int samples = 8;
bool sensing = false;
int reading = 0;
int calibration_value = 0;
int threshold = 2;
//==============================================================================
void setup ()
{
  Serial.begin(9600);
  Serial.println("microbit is ready!");
  pinMode(PIN_BUTTON_A, INPUT);
  pinMode(PIN_BUTTON_B, INPUT);
  pinMode(0, INPUT_PULLUP);
}

//==============================================================================
void loop()
{
  readButtons();
}
//==============================================================================
void readButtons()
{
  if (! digitalRead(PIN_BUTTON_A))
  {
    buttonA();
  }
  if (! digitalRead(PIN_BUTTON_B))
  {
    buttonB();
  }
}

void calibrate()
{
  reading = 0;
  for (int i = 0; i <= samples; i++)
  {
    readPin();
    delay(1);
  }
  calibration_value = reading / samples;
}
//==============================================================================
void readPin()
{
  reading += analogRead(0);
  digitalWrite(0, HIGH);
}
//==============================================================================
void sense()
{
  reading = 0;

  for (int i = 0; i <= samples; i++)
  {
    readPin();
    delay(1);
  }
  (state = calibration_value + threshold) < (reading / samples);
}
//==============================================================================
void buttonA()
{
  calibration_value = 0;
  calibrate();
  microbit.print(calibration_value);
}
//==============================================================================
void buttonB()
{
  sensing = true;
  while (sensing)
  {
    sense();
    if (state)
    {
      microbit.fillScreen(LED_ON);
    }
    else
    {
      uint8_t centerLed[] =
      { B00000,
        B00000,
        B00100,
        B00000,
        B00000,
      };
      microbit.show(centerLed);
    }
    delay(10);
  }
}
//==============================================================================
