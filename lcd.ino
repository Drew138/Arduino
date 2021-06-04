#include <LiquidCrystal.h>

void setup()
{
    pinMode(47, OUTPUT);
    digitalWrite(47, 0);
    lcd.begin(16, 2);
}

void loop()
{
    lcd.setCursor(5, 0);
    lcd.print("Andres");
    lcd.setCursor(1, 1);
    lcd.print("Salazar Galeano");
}
