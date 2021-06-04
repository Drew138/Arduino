
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

void setup()
{
    pinMode(47, OUTPUT);
    digitalWrite(47, 0);
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
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
    lcd.setCursor(0, 1);
    lcd.print("comenzar");
    int key = keypad.getKey();
    while (key != '*')
        key = keypad.getKey();
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print("Ingrese un");
    lcd.setCursor(0, 1);
    lcd.print("numero");
    int contador = 0;
    for (int i = 0; i < 3; ++i)
    {
        int tecla = teclados();
        if (i == 0)
        {
            lcd.setCursor(0, 0);
            lcd.clear();
        }
        lcd.print(tecla);
        contador *= 10;
        contador += tecla;
    }

    int tinicial = millis();
    int tfinal = millis();
    while (contador > 0)
    {
        if (tfinal - tinicial > 500)
        {
            lcd.setCursor(0, 0);
            lcd.clear();
            --contador;
            lcd.print(contador);
            tinicial = millis();
        }
        key = keypad.getKey();
        while (key == '#')
        {
            int entry = keypad.getKey();
            if (entry == '*')
                key = entry;
        }
        tfinal = millis();
    }
}
