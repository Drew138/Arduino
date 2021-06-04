#include <TimerOne.h>

int contador = 0;
const int AUMENTAR = 21;
const int DISMINUIR = 20;
const int PARAR = 19;
const int START = 18;

void aumentar()
{
    ++contador;
    delay(150);
    Serial.println(contador);
}

void disminuir()
{
    --contador;
    if (contador < 0)
    {
        contador = 0;
        Timer1.detachInterrupt();
        attachInterrupt(0, aumentar, RISING);
        attachInterrupt(0, disminuir, RISING);
    }
    delay(150);
    Serial.println(contador);
}

void reloj()
{
    --contador;
    if (contador == 0)
    {
        contador = 0;
        Timer1.detachInterrupt();
        attachInterrupt(2, aumentar, RISING);
        attachInterrupt(3, disminuir, RISING);
    }
    Serial.println(contador);
}

void start()
{
    detachInterrupt(aumentar);
    detachInterrupt(disminuir);
    Timer1.attachInterrupt(reloj);
}

void parar()
{
    contador = 0;
    Timer1.detachInterrupt();
    attachInterrupt(2, aumentar, RISING);
    attachInterrupt(3, disminuir, RISING);
    delay(150);
    Serial.println(contador);
}

void setup()
{
    Serial.begin(9600);
    pinMode(AUMENTAR, INPUT);
    pinMode(DISMINUIR, INPUT);
    pinMode(START, INPUT);
    pinMode(PARAR, INPUT);
    Timer1.initialize(10000000);
    attachInterrupt(2, aumentar, RISING);
    attachInterrupt(3, disminuir, RISING);
    attachInterrupt(4, parar, RISING);
    attachInterrupt(5, start, RISING);
}

void loop()
{
}