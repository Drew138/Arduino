#include <Wire.h>
int led = 37;

void sendInstructions()
{
    digitalWrite(led, Wire.read());
}

void setup()
{

    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
    Wire.begin(1);
    Wire.onReceive(sendInstructions);
}

void loop()
{
}