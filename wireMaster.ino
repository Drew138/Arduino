#include <Wire.h>
int but1 = 35;
int but2 = 36;

void setup()
{
    pinMode(but1, INPUT);
    pinMode(but2, INPUT);
    Wire.begin();
}

void loop()
{
    Wire.beginTransmission(1);
    Wire.write(digitalRead(but1) ? 1 : 0);
    Wire.endTransmission();
    Wire.beginTransmission(2);
    Wire.write(digitalRead(but2) ? 1 : 0);
    Wire.endTransmission();
    delay(200);
}
