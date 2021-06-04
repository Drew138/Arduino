byte displays[10] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103};
int contador = 0;
int pull1 = 24;
int pull2 = 27;
int pull3 = 30;
int UNIDADES = 43;
int DECENAS = 44;
int CENTENAS = 45;
int LED = 22;

void setup()
{
    DDRK = 0b1111111;
    pinMode(pull1, INPUT);
    pinMode(pull2, INPUT);
    pinMode(pull3, INPUT);
    pinMode(UNIDADES, OUTPUT);
    pinMode(DECENAS, OUTPUT);
    pinMode(CENTENAS, OUTPUT);
    pinMode(LED, OUTPUT);
}

void mostrar()
{
    int unidades = contador % 10;
    int decenas = (contador % 100) / 10;
    int centenas = contador / 100;
    PORTK = displays[unidades];
    digitalWrite(UNIDADES, HIGH);
    delay(5);
    digitalWrite(UNIDADES, LOW);
    PORTK = displays[decenas];
    digitalWrite(DECENAS, HIGH);
    delay(5);
    digitalWrite(DECENAS, LOW);
    PORTK = displays[centenas];
    digitalWrite(CENTENAS, HIGH);
    delay(5);
    digitalWrite(CENTENAS, LOW);
}

void loop()
{
    mostrar();
    if (digitalRead(pull1))
    {
        contador++;
        if (contador == 1000)
            contador = 0;
        while (digitalRead(pull1))
            mostrar();
    }
    else if (digitalRead(pull2))
    {
        contador--;
        if (contador < 0)
            contador = 999;
        while (digitalRead(pull2))
            mostrar();
    }
    else if (digitalRead(pull3))
    {
        while (contador > 0)
        {
            for (int i = 0; i < 50; ++i)
                mostrar();
            contador--;
        }
        digitalWrite(LED, HIGH);
        for (int i = 0; i < 50; ++i)
            mostrar();
        digitalWrite(LED, LOW);
        for (int i = 0; i < 50; ++i)
            mostrar();
        digitalWrite(LED, HIGH);
        for (int i = 0; i < 50; ++i)
            mostrar();
        digitalWrite(LED, LOW);
        for (int i = 0; i < 50; ++i)
            mostrar();
        digitalWrite(LED, HIGH);
        for (int i = 0; i < 50; ++i)
            mostrar();
        digitalWrite(LED, LOW);
    }
}
