unsigned int tinicial = millis();
unsigned int tactual = millis();
int motor = 22;
int inicio = 37;
int detener = 36;
void setup()
{
    pinMode(motor, OUTPUT);
    pinMode(inicio, OUTPUT);
    pinMode(detener, OUTPUT);
}

void tiempo(int intervalo)
{

    tinicial = millis();
    tactual = millis();
    while ((tactual - tinicial < intervalo) && digitalRead(detener) == 0)
    {
        tactual = millis();
    }
}

void loop()
{
    if (digitalRead(inicio))
    {
        digitalWrite(motor, HIGH);
        tiempo(10000);
        digitalWrite(motor, LOW);
    }
}
