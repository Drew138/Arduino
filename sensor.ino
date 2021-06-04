#include <Servo.h>
Servo servo;

void setup()
{
    servo.attach(2);
    // servo.write(0);
    Serial.begin(9600);
}

void loop()
{
    int val = analogRead(2);
    delay(200);
    int angle = map(val, 0, 1023, 0, 180);
    Serial.print("Value: ");
    Serial.print(val);
    Serial.print(" Angle: ");
    Serial.println(angle);
    servo.write(angle);
}