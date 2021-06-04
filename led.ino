unsigned int tinicial1 = millis();
unsigned int tinicial2 = millis();
unsigned int tactual1 = millis();
unsigned int tactual2 = millis();
int led1 = 22;
int led2 = 23;
int inicio = 36;
int detener = 37;
void setup()
{
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(inicio, OUTPUT);
    pinMode(detener, OUTPUT);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    tinicial1 = millis();
    tinicial2 = millis();
}

void loop()
{

    tactual1 = millis();
    tactual2 = millis();
    if (tactual1 - tinicial1 > 500)
    {
        digitalWrite(led1, !digitalRead(led1));
        tinicial1 = millis();
    }
    if (tactual2 - tinicial2 > 800)
    {
        digitalWrite(led2, !digitalRead(led2));
        tinicial2 = millis();
    }
}
