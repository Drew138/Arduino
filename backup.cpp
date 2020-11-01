//Definicion de pines
//Defino librería para incluir servomotor

#include <Servo.h>

Servo Servo_puerta; // Objeto servo para controlar la puerta
int Angulo = 0;     // Variable angulo
int TRIG = 11;      // Pin sensor HC-SR
int ECHO = 12;      // Pin sensor HC-SR
int PIR = 13;       // Pin sensor de presencia
int TEMP = A0;      // Pin entrada analoga sensor temperatura
int S_LUZ = A1;     // Pin sensor luz
int SER = 3;        // Pin para controlar el servomotor
int VALOR = 0;      // Valor analogo de la temperatura
int VALOR_ESC = 0;  // Valor escalado de la temperatura
int R = 5;          // Pin puerto rojo led RGB
int G = 9;          // Pin puerto verde led RGB
int B = 6;          // Pin puerto azul led RGB

void setup()
{
    //configurar salidas
    pinMode(SER, OUTPUT);     // Pin salida servmotor
    pinMode(TRIG, OUTPUT);    // Pin salida sensor HC-SR04
    Servo_puerta.attach(SER); // Vincula el servo al pin digital 3

    pinMode(R, OUTPUT); // Pin salida LED RGB ROJO
    pinMode(G, OUTPUT); // Pin salida LED RGB VERDE
    pinMode(B, OUTPUT); // Pin salida LED RGB AZUL

    pinMode(TEMP, INPUT);       // Sensor temperatura
    pinMode(ECHO, INPUT);       // Pin entrada sensor HC-SR04
    pinMode(PIR, INPUT);        // Pin entrada sensor de presencia PIR
    pinMode(S_LUZ, INPUT);      // Pin entrada sensor de presencia IR
    Servo_puerta.write(Angulo); // Configuro el servomotor en 0 grados
    Serial.begin(9600);         // Habilito el puerto serial para monitoreo
}

//Funcion para cálcular distancia
int Pin_delta(int TRIG, int ECHO)
{
    long Tiempo_1, X_cm;

    digitalWrite(TRIG, LOW); // para generar un pulso limpio ponemos a LOW 4us
    delayMicroseconds(4);
    digitalWrite(TRIG, HIGH); // generamos Trigger (disparo) de 10us
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    Tiempo_1 = pulseIn(ECHO, HIGH); // medimos el tiempo entre pulsos, en microsegundos

    X_cm = Tiempo_1 * 10 / 292 / 2; // convertimos a distancia, en cm
    return X_cm;
}

/*
	Proceso de escalizacion
    
	Cambio de escala entre floats

	Se tuvo problemas a la hora escalizar la temperatura
    con la formula que estaba por defecto, por lo que se
    prefirio utilizar calculo y crear una funcion de linea
    recta que pasara por los puntos (153, 25) (osea que 
    cuando el valor analogo valga 153, la temperatura valga
    25 grados) y (358, 125). La ecuación resultante fue 
           
            20       2035
    f(x) = ---- x - ------
            41        41

	Y es la ecuacion que estaremos empleando en la escalizacion
    de la temperatura
*/
float fmap(float x)
{
    return (20.0 / 41.0) * x - (2035.0 / 41);
}

void loop()
{

    digitalWrite(R, 255); // Encendido del led
    digitalWrite(G, 255); // RGB en el color blanco
    digitalWrite(B, 255);

    if (digitalRead(PIR) == HIGH)
    { // Detecta si se encuentra una persona

        Serial.println("Persona detectada"); // Alerta de una persona detectada
        digitalWrite(R, 255);
        digitalWrite(G, 255); // Enciende el led RGB de color amarillo
        digitalWrite(B, 0);

        int x_cm = Pin_delta(TRIG, ECHO); // Lee con el sensor HC-SR04 la distancia
                                          // de la persona en centimetros

        if (x_cm <= 15)
        {   // Pregunta si esta distancia es menor o
            // o igual a 15cm

            VALOR = analogRead(TEMP); // Si es así,  lee la temperatura
            delay(3000);              // durante 3000 milisegundos (3 segundos)
            VALOR_ESC = fmap(VALOR);  // Escala el valor con la ecuacion diseñada
            Serial.print("Temperatura aproximada de ");
            Serial.print(VALOR_ESC); // Alerta el valor de la temperatura
            Serial.println(" grados");

            if (VALOR_ESC >= 37.5)
            {   // Pregunta si esta temperatura es mayor o
                // igual a 37.5 grados

                digitalWrite(R, 255);
                digitalWrite(G, 0); // Si es asi, enciende el led RGB en rojo
                digitalWrite(B, 0);

                Serial.println("Temperatura por encima de 37.5 grados, acceso denegado");

                while (x_cm <= 100)
                {
                    x_cm = Pin_delta(TRIG, ECHO); // Espera que se retire la persona
                    delay(500);
                }

                Serial.println("La persona se ha retirado");
            }
            else
            { // De lo contrario, si es menor a 37.5 grados

                digitalWrite(R, 0);
                digitalWrite(G, 255); // Enciende el led RGB en verde
                digitalWrite(B, 0);

                Serial.println("Temperatura por debajo de 37.5 grados, acceso concedido");
                Serial.println("Abriendo puerta");

                Angulo = 90;
                Servo_puerta.write(Angulo); // Abre la puerta con el servomotor
                delay(1000);

                while (analogRead(S_LUZ) >= 200)
                {
                    delay(500);
                } // Espera a que la persona ingrese
                  // y uando haya un corte de luz, sale
                  // del ciclo

                delay(5000); // Espera 5 segundos a que la persona termine de pasar por la puerta

                Serial.println("Ya ingreso, cerrando puerta");

                Angulo = 0;
                Servo_puerta.write(Angulo); // Cierra nuevamente la puerta
                delay(1000);
            }
        }
        else
        {

            Serial.println("Debes estar a una distancia menor o igual a 15cm");
        }
    }
    delay(10);
}