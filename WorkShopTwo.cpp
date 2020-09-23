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

void setDigitos(int i)
{
    decenas = i / 10;
    i > 10 ? unidades = i % 10 : unidades = i;
}

void loop()
{
    digitalWrite(RGBGreen, LOW);
    digitalWrite(RGBBlue, LOW);
    digitalWrite(RGBRed, LOW);
    digitalWrite(motor, LOW);
    for (int i = 0; i < 100; i++)
    {
        // MOTOR
        if (i <= 20)
        {
            digitalWrite(motor, LOW);
        }
        else if (i > 43)
        {
            digitalWrite(motor, LOW);
            digitalWrite(motor, HIGH);
        }
        // LED RGB
        if (i < 10)
        {
            analogWrite(RGBGreen, 0);
            analogWrite(RGBBlue, 0);
            analogWrite(RGBRed, 0);
            delay(1);
            analogWrite(RGBGreen, 255);
            analogWrite(RGBBlue, 255);
            analogWrite(RGBRed, 255);
        }
        else if ((i >= 10) && (i <= 28))
        {
            analogWrite(RGBGreen, 0);
            analogWrite(RGBBlue, 0);
            analogWrite(RGBRed, 0);
            delay(1);
            analogWrite(RGBGreen, 201);
            analogWrite(RGBBlue, 14);
            analogWrite(RGBRed, 255);
        }
        else if ((i > 28) && (i <= 30))
        {
            analogWrite(RGBGreen, 0);
            analogWrite(RGBBlue, 0);
            analogWrite(RGBRed, 0);
            delay(1);
            analogWrite(RGBGreen, 0);
            analogWrite(RGBBlue, 0);
            analogWrite(RGBRed, 0);
        }
        else if ((i > 30) && (i <= 60))
        {
            analogWrite(RGBGreen, 0);
            analogWrite(RGBBlue, 0);
            analogWrite(RGBRed, 0);
            delay(1);
            analogWrite(RGBGreen, 128);
            analogWrite(RGBBlue, 0);
            analogWrite(RGBRed, 255);
        }
        else if (i > 85)
        {
            analogWrite(RGBGreen, 0);
            analogWrite(RGBBlue, 0);
            analogWrite(RGBRed, 0);
            delay(1);
            analogWrite(RGBGreen, 0);
            analogWrite(RGBBlue, 0);
            analogWrite(RGBRed, 255);
        }
        // Multiplexacion
        int repetitions = 5;
        while (repetitions--)
        {

            setDigitos(i);
            digitalWrite(Digito1, LOW);
            digitalWrite(Digito2, LOW);
            mostrarDigito(decenas);
            delay(10);
            digitalWrite(Digito1, HIGH);
            digitalWrite(Digito2, LOW);
            delay(50);
            digitalWrite(Digito1, LOW);
            digitalWrite(Digito2, LOW);
            mostrarDigito(unidades);
            delay(10);
            digitalWrite(Digito1, LOW);
            digitalWrite(Digito2, HIGH);
            delay(50);
        }
    }
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
