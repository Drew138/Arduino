int puntaje;
int nivel;
void setup()
{
    puntaje = 0;
    nivel = 1;
    Serial.begin(9600);
}

void loop()
{
    while (puntaje < 10)
    {
        randomSeed(micros());
        int num1 = random(1, 10);
        int num2 = random(1, 10);
        Serial.print(num1);
        Serial.print(" * ? = ");
        Serial.print(num1 * num2);
        Serial.print(": ");
        while (Serial.available() == 0)
            ;
        int numInsertado = Serial.read() - 48;
        Serial.println("");
        if (num2 == numInsertado)
        {
            puntaje++;
            Serial.print("Correcto!, tu puntaje ahora es ");
            Serial.println(puntaje);
        }
        else
        {
            Serial.print("Perdiste, tu puntaje fue ");
            Serial.println(puntaje);
            break;
        }
    }
    if (puntaje == 10)
        Serial.println("Ganaste!");
    puntaje = 0;
}
