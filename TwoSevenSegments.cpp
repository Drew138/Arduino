int Digito1 = 2;
int Digito2 = 9;
int SegA = 3;
int SegB = 4;
int SegC = 5;
int SegD = 6;
int SegE = 7;
int SegF = 8;
int SegG = 9;
int Valor = 0;

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

    digitalWrite(Digito1, LOW);
    digitalWrite(Digito2, LOW);
    digitalWrite(SegA, LOW);
    digitalWrite(SegB, LOW);
    digitalWrite(SegC, LOW);
    digitalWrite(SegD, LOW);
    digitalWrite(SegE, LOW);
    digitalWrite(SegF, LOW);
    digitalWrite(SegG, LOW);
}

void loop()
{
    digitalWrite(Digito1, HIGH);
    digitalWrite(Digito2, HIGH);
    delay(1);
    mostrarDigito(Valor);
    delay(400);
    Valor++;
    if (Valor > 9)
    {
        Valor = 0;
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