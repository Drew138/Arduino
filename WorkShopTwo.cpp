int Digito1 = 2;
int Digito2 = 10;
int SegA = 3;
int SegB = 4;
int SegC = 5;
int SegD = 6;
int SegE = 7;
int SegF = 8;
int SegG = 9;
int unidades = 0;
int decenas = 0;
int RGBGreen = 11;
int RGBBlue = 12;
int RGBRed = 13;
int motor = 1;
int PushButton = 0;
int contador = 0;

void setup()
{
    pinMode(Digito1, OUTPUT);
    pinMode(Digito2, OUTPUT);
    pinMode(SegA, OUTPUT);
    pinMode(SegB, OUTPUT);
    pinMode(SegC, OUTPUT);
    pinMode(SegD, OUTPUT);
    pinMode(SegE, OUTPUT);
    pinMode(SegF, OUTPUT);
    pinMode(SegG, OUTPUT);
    pinMode(RGBGreen, OUTPUT);
    pinMode(RGBBlue, OUTPUT);
    pinMode(RGBRed, OUTPUT);
    pinMode(motor, OUTPUT);
    pinMode(PushButton, INPUT);

    digitalWrite(Digito1, LOW);
    digitalWrite(Digito2, LOW);
    digitalWrite(SegA, LOW);
    digitalWrite(SegB, LOW);
    digitalWrite(SegC, LOW);
    digitalWrite(SegD, LOW);
    digitalWrite(SegE, LOW);
    digitalWrite(SegF, LOW);
    digitalWrite(SegG, LOW);
    digitalWrite(RGBGreen, LOW);
    digitalWrite(RGBBlue, LOW);
    digitalWrite(RGBRed, LOW);
    digitalWrite(motor, LOW);
}

void setDigitos(int contador)
{
    decenas = contador / 10;
    contador >= 10 ? unidades = contador % 10 : unidades = contador;
}

void loop()
{
    digitalWrite(RGBGreen, LOW);
    digitalWrite(RGBBlue, LOW);
    digitalWrite(RGBRed, LOW);
    digitalWrite(motor, LOW);

    if (digitalRead(PushButton) == LOW)
    {
        contador += 1;
        delay(150);
        if (contador > 99)
            contador = 0;
    }

    // MOTOR
    if (contador <= 20)
    {
        digitalWrite(motor, LOW);
    }
    else if (contador > 43)
    {
        digitalWrite(motor, LOW);
        digitalWrite(motor, HIGH);
    }
    // LED RGB
    analogWrite(RGBGreen, 0);
    analogWrite(RGBBlue, 0);
    analogWrite(RGBRed, 0);
    if (contador < 10)
    {
        analogWrite(RGBGreen, 255);
        analogWrite(RGBBlue, 255);
        analogWrite(RGBRed, 255);
    }
    else if ((contador >= 10) && (contador <= 28))
    {
        analogWrite(RGBGreen, 201);
        analogWrite(RGBBlue, 14);
        analogWrite(RGBRed, 255);
    }
    else if ((contador > 28) && (contador <= 30))
    {
        analogWrite(RGBGreen, 0);
        analogWrite(RGBBlue, 0);
        analogWrite(RGBRed, 0);
    }
    else if ((contador > 30) && (contador <= 60))
    {
        analogWrite(RGBGreen, 128);
        analogWrite(RGBBlue, 0);
        analogWrite(RGBRed, 255);
    }
    else if (contador > 85)
    {
        analogWrite(RGBGreen, 0);
        analogWrite(RGBBlue, 0);
        analogWrite(RGBRed, 255);
    }
    // Multiplexacion

    setDigitos(contador);
    digitalWrite(Digito1, LOW);
    digitalWrite(Digito2, LOW);
    mostrarDigito(decenas);
    delay(1);
    digitalWrite(Digito1, HIGH);
    digitalWrite(Digito2, LOW);
    delay(20);
    digitalWrite(Digito1, LOW);
    digitalWrite(Digito2, LOW);
    mostrarDigito(unidades);
    delay(1);
    digitalWrite(Digito1, LOW);
    digitalWrite(Digito2, HIGH);
    delay(20);
}

void mostrarDigito(int Value)
{
    switch (Value)
    {
    case 0:
        digitalWrite(SegA, HIGH);
        digitalWrite(SegB, HIGH);
        digitalWrite(SegC, HIGH);
        digitalWrite(SegD, HIGH);
        digitalWrite(SegE, HIGH);
        digitalWrite(SegF, HIGH);
        digitalWrite(SegG, LOW);
        break;
    case 1:
        digitalWrite(SegA, LOW);
        digitalWrite(SegB, HIGH);
        digitalWrite(SegC, HIGH);
        digitalWrite(SegD, LOW);
        digitalWrite(SegE, LOW);
        digitalWrite(SegF, LOW);
        digitalWrite(SegG, LOW);
        break;
    case 2:
        digitalWrite(SegA, HIGH);
        digitalWrite(SegB, HIGH);
        digitalWrite(SegC, LOW);
        digitalWrite(SegD, HIGH);
        digitalWrite(SegE, HIGH);
        digitalWrite(SegF, LOW);
        digitalWrite(SegG, HIGH);
        break;
    case 3:
        digitalWrite(SegA, HIGH);
        digitalWrite(SegB, HIGH);
        digitalWrite(SegC, HIGH);
        digitalWrite(SegD, HIGH);
        digitalWrite(SegE, LOW);
        digitalWrite(SegF, LOW);
        digitalWrite(SegG, HIGH);
        break;
    case 4:
        digitalWrite(SegA, LOW);
        digitalWrite(SegB, HIGH);
        digitalWrite(SegC, HIGH);
        digitalWrite(SegD, LOW);
        digitalWrite(SegE, LOW);
        digitalWrite(SegF, HIGH);
        digitalWrite(SegG, HIGH);
        break;
    case 5:
        digitalWrite(SegA, HIGH);
        digitalWrite(SegB, LOW);
        digitalWrite(SegC, HIGH);
        digitalWrite(SegD, HIGH);
        digitalWrite(SegE, LOW);
        digitalWrite(SegF, HIGH);
        digitalWrite(SegG, HIGH);
        break;
    case 6:
        digitalWrite(SegA, HIGH);
        digitalWrite(SegB, LOW);
        digitalWrite(SegC, HIGH);
        digitalWrite(SegD, HIGH);
        digitalWrite(SegE, HIGH);
        digitalWrite(SegF, HIGH);
        digitalWrite(SegG, HIGH);
        break;
    case 7:
        digitalWrite(SegA, HIGH);
        digitalWrite(SegB, HIGH);
        digitalWrite(SegC, HIGH);
        digitalWrite(SegD, LOW);
        digitalWrite(SegE, LOW);
        digitalWrite(SegF, LOW);
        digitalWrite(SegG, LOW);
        break;
    case 8:
        digitalWrite(SegA, HIGH);
        digitalWrite(SegB, HIGH);
        digitalWrite(SegC, HIGH);
        digitalWrite(SegD, HIGH);
        digitalWrite(SegE, HIGH);
        digitalWrite(SegF, HIGH);
        digitalWrite(SegG, HIGH);
        break;
    case 9:
        digitalWrite(SegA, HIGH);
        digitalWrite(SegB, HIGH);
        digitalWrite(SegC, HIGH);
        digitalWrite(SegD, LOW);
        digitalWrite(SegE, LOW);
        digitalWrite(SegF, HIGH);
        digitalWrite(SegG, HIGH);
        break;
    }
}
