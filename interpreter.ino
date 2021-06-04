// input
int LDA = 22;
int ADD = 23;
int SUB = 24;
int MUL = 25;
int DIV = 26;
int DECSZ = 27;
int GOTO = 28;
int CALL = 29;
int EXP = 30;
int XOR = 31;
int MOD = 32;
int OUT = 33;
int HLT = 34;
int RETURN = 35;
int ZERODIV = 36;
int ZEROERR = 52;
// output
int EP = 37;
int LM = 38;
int ER = 39;
int LI = 40;
int EI = 41;
int LA = 42;
int EA = 43;
int SUMA = 44;
int REST = 45;
int MULT = 46;
int DIVI = 47;
int EU = 48;
int LB = 49;
int LO = 50;
int XOROP = 51;
// vars
int PC;
int TMP;
int INBUS;

void setup()
{
    // input
    pinMode(LDA, INPUT);
    pinMode(ADD, INPUT);
    pinMode(SUB, INPUT);
    pinMode(MUL, INPUT);
    pinMode(DIV, INPUT);
    pinMode(DECSZ, INPUT);
    pinMode(GOTO, INPUT);
    pinMode(CALL, INPUT);
    pinMode(EXP, INPUT);
    pinMode(XOR, INPUT);
    pinMode(MOD, INPUT);
    pinMode(OUT, INPUT);
    pinMode(HLT, INPUT);
    pinMode(RETURN, INPUT);
    pinMode(ZERODIV, INPUT);
    // output
    pinMode(EP, OUTPUT);
    pinMode(LM, OUTPUT);
    pinMode(ER, OUTPUT);
    pinMode(LI, OUTPUT);
    pinMode(EI, OUTPUT);
    pinMode(LA, OUTPUT);
    pinMode(EA, OUTPUT);
    pinMode(SUMA, OUTPUT);
    pinMode(REST, OUTPUT);
    pinMode(MULT, OUTPUT);
    pinMode(DIVI, OUTPUT);
    pinMode(XOROP, OUTPUT);
    pinMode(EU, OUTPUT);
    pinMode(LB, OUTPUT);
    pinMode(LO, OUTPUT);
    pinMode(ZEROERR, OUTPUT);
    Serial.begin(9600);
    DDRK = 0b11111111;
    DDRF = 0b00000000;
    PC = 0;
}

void loop()
{
    PORTK = PC;
    digitalWrite(EP, HIGH);
    digitalWrite(LM, HIGH);
    delay(200);
    digitalWrite(LM, LOW);
    digitalWrite(EP, LOW);
    delay(200);
    digitalWrite(ER, HIGH);
    digitalWrite(LI, HIGH);
    delay(200);
    digitalWrite(LI, LOW);
    digitalWrite(ER, LOW);
    delay(200);
    if (digitalRead(LDA))
    {
        digitalWrite(EI, HIGH);
        digitalWrite(LM, HIGH);
        delay(200);
        digitalWrite(LM, LOW);
        digitalWrite(EI, LOW);
        delay(200);
        digitalWrite(ER, HIGH);
        digitalWrite(LA, HIGH);
        delay(200);
        digitalWrite(LA, LOW);
        digitalWrite(ER, LOW);
    }
    else if (digitalRead(ADD))
    {
        digitalWrite(EI, HIGH);
        digitalWrite(LM, HIGH);
        delay(200);
        digitalWrite(LM, LOW);
        digitalWrite(EI, LOW);
        delay(200);
        digitalWrite(ER, HIGH);
        digitalWrite(LB, HIGH);
        delay(200);
        digitalWrite(LB, LOW);
        digitalWrite(ER, LOW);
        delay(200);
        digitalWrite(SUMA, HIGH);
        delay(200);
        digitalWrite(SUMA, LOW);
        delay(200);
        digitalWrite(EU, HIGH);
        digitalWrite(LA, HIGH);
        delay(200);
        digitalWrite(LA, LOW);
        digitalWrite(EU, LOW);
    }
    else if (digitalRead(SUB))
    {
        digitalWrite(EI, HIGH);
        digitalWrite(LM, HIGH);
        delay(200);
        digitalWrite(LM, LOW);
        digitalWrite(EI, LOW);
        delay(200);
        digitalWrite(ER, HIGH);
        digitalWrite(LB, HIGH);
        delay(200);
        digitalWrite(LB, LOW);
        digitalWrite(ER, LOW);
        delay(200);
        digitalWrite(REST, HIGH);
        digitalWrite(EU, HIGH);
        delay(200);
        digitalWrite(LA, HIGH);
        delay(200);
        digitalWrite(LA, LOW);
        digitalWrite(REST, LOW);
        digitalWrite(EU, LOW);
        delay(200);
    }
    else if (digitalRead(MUL))
    {
        digitalWrite(EI, HIGH);
        digitalWrite(LM, HIGH);
        delay(200);
        digitalWrite(LM, LOW);
        digitalWrite(EI, LOW);
        delay(200);
        digitalWrite(ER, HIGH);
        digitalWrite(LB, HIGH);
        delay(200);
        digitalWrite(LB, LOW);
        digitalWrite(ER, LOW);
        delay(200);
        digitalWrite(MULT, HIGH);
        delay(200);
        digitalWrite(MULT, LOW);
        delay(200);
        digitalWrite(EU, HIGH);
        digitalWrite(LA, HIGH);
        delay(200);
        digitalWrite(LA, LOW);
        digitalWrite(EU, LOW);
    }
    else if (digitalRead(DIV))
    {
        digitalWrite(EI, HIGH);
        digitalWrite(LM, HIGH);
        delay(200);
        digitalWrite(LM, LOW);
        digitalWrite(EI, LOW);
        delay(200);
        digitalWrite(ER, HIGH);
        digitalWrite(LB, HIGH);
        delay(200);
        digitalWrite(LB, LOW);
        digitalWrite(ER, LOW);
        delay(200);

        if (digitalRead(ZERODIV))
        {
            digitalWrite(ZEROERR, HIGH);
            PORTK = 0xEE;
            digitalWrite(EP, HIGH);
            digitalWrite(LO, HIGH);
            delay(200);
            digitalWrite(LO, LOW);
            digitalWrite(EP, LOW);
            while (true)
            {
            }
        }
        digitalWrite(DIVI, HIGH);
        delay(200);
        // delay(200);
        digitalWrite(EU, HIGH);
        digitalWrite(LA, HIGH);
        delay(200);
        digitalWrite(DIVI, LOW);
        digitalWrite(LA, LOW);
        digitalWrite(EU, LOW);
    }
    else if (digitalRead(DECSZ))
    {
        PORTK = 1; // preguntar
        digitalWrite(EP, HIGH);
        digitalWrite(LB, HIGH);
        delay(200);
        digitalWrite(LB, LOW);
        digitalWrite(EP, LOW);
        delay(200);
        digitalWrite(REST, HIGH);
        digitalWrite(EU, HIGH);
        delay(200);
        digitalWrite(LA, HIGH);
        INBUS = PINF;
        delay(200);
        digitalWrite(LA, LOW);
        digitalWrite(REST, LOW);
        digitalWrite(EU, LOW);
        if (!INBUS)
            PC++;
    }
    else if (digitalRead(GOTO))
    {
        digitalWrite(EI, HIGH);
        delay(200);
        PC = PINF;
        digitalWrite(EI, LOW);
        PC--;
    }
    else if (digitalRead(CALL))
    {
        TMP = PC + 1;
        digitalWrite(EI, HIGH);
        delay(200);
        PC = PINF;
        digitalWrite(EI, LOW);
        PC--;
    }
    else if (digitalRead(EXP))
    {
        digitalWrite(EA, HIGH);
        digitalWrite(LB, HIGH);
        delay(200);
        digitalWrite(LB, LOW);
        digitalWrite(EA, LOW);
        delay(200);
        digitalWrite(MULT, HIGH);
        delay(200);
        digitalWrite(EU, HIGH);
        digitalWrite(LA, HIGH);
        delay(200);
        digitalWrite(LA, LOW);
        digitalWrite(EU, LOW);
        digitalWrite(MULT, LOW);
        delay(200);
    }
    else if (digitalRead(XOR))
    {
        digitalWrite(EI, HIGH);
        digitalWrite(LM, HIGH);
        delay(200);
        digitalWrite(LM, LOW);
        digitalWrite(EI, LOW);
        delay(200);
        digitalWrite(ER, HIGH);
        digitalWrite(LB, HIGH);
        delay(200);
        digitalWrite(LB, LOW);
        digitalWrite(ER, LOW);
        delay(200);
        digitalWrite(XOROP, HIGH);
        delay(200);
        digitalWrite(XOROP, LOW);
        delay(200);
        digitalWrite(EU, HIGH);
        digitalWrite(LA, HIGH);
        delay(200);
        digitalWrite(LA, LOW);
        digitalWrite(EU, LOW);
    }
    else if (digitalRead(MOD))
    {
        digitalWrite(EA, HIGH);
        delay(200);
        INBUS = PINF;
        digitalWrite(EA, LOW);
        delay(200);
        digitalWrite(ER, HIGH);
        digitalWrite(LB, HIGH);
        delay(200);
        digitalWrite(LB, LOW);
        digitalWrite(ER, LOW);
        delay(200);
        digitalWrite(DIVI, HIGH);
        delay(200);
        digitalWrite(DIVI, LOW);
        delay(200);
        digitalWrite(EU, HIGH);
        digitalWrite(LA, HIGH);
        delay(200);
        digitalWrite(LA, LOW);
        digitalWrite(EU, LOW);
        // mult
        digitalWrite(MULT, HIGH);
        delay(200);
        digitalWrite(MULT, LOW);
        delay(200);
        digitalWrite(EU, HIGH);
        digitalWrite(LB, HIGH);
        delay(200);
        digitalWrite(LB, LOW);
        digitalWrite(EU, LOW);
        delay(200);
        PORTK = INBUS;
        digitalWrite(EP, HIGH);
        digitalWrite(LA, HIGH);
        delay(200);
        digitalWrite(LA, LOW);
        digitalWrite(EP, LOW);
        delay(200);
        digitalWrite(REST, HIGH);
        delay(200);
        digitalWrite(REST, LOW);
        delay(200);
        digitalWrite(EU, HIGH);
        digitalWrite(LA, HIGH);
        delay(200);
        digitalWrite(LA, LOW);
        digitalWrite(EU, LOW);

        // dividir y multiplicar y restar
    }
    else if (digitalRead(OUT))
    {
        digitalWrite(EA, HIGH);
        digitalWrite(LO, HIGH);
        delay(200);
        digitalWrite(LO, LOW);
        digitalWrite(EA, LOW);
    }
    else if (digitalRead(HLT))
    {
        while (true)
        {
        }
    }
    else if (digitalRead(RETURN))
    {
        PC = TMP;
        PC--;
    }
    PC++;
}