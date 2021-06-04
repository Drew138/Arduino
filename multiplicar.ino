#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(48, 49, 45, 44, 43, 42);
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};

byte rowPins[ROWS] = {18, 19, 20, 21};
byte colPins[COLS] = {17, 16, 15};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
int puntaje;

void setup()
{
    pinMode(47, OUTPUT);
    digitalWrite(47, 0);
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    puntaje = 0;
}

int teclados()
{
    int key = keypad.getKey();
    while (key == '\0' || key == '#' || key == '*')
        key = keypad.getKey();
    return key - 48;
}

void loop()
{
    lcd.setCursor(0, 0);
    lcd.print("Presione * para comenzar");
    int key = keypad.getKey();
    while (key != '*')
        key = keypad.getKey();
    while (puntaje < 10)
    {
        randomSeed(micros());
        int num1 = random(1, 10);
        int num2 = random(1, 10);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(num1);
        lcd.print(" * ? = ");
        lcd.print(num1 * num2);
        lcd.print(": ");
        int numInsertado = teclados();
        lcd.clear();
        lcd.setCursor(0, 0);
        if (num2 == numInsertado)
        {
            puntaje++;
            lcd.print("Correcto! tienes");
            lcd.setCursor(0, 1);
            lcd.print(puntaje);
            lcd.print(" puntos");
            delay(2000);
        }
        else
        {
            lcd.print("Pierdes, tuviste");
            lcd.setCursor(0, 1);
            lcd.print(puntaje);
            lcd.print(" puntos");
            delay(2000);
            break;
        }
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    if (puntaje == 10)
        lcd.println("Ganaste!");
    delay(3000);
    puntaje = 0;
}
