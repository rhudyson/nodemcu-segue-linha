//variaveis correspondentes aos pinos do nodemcu e da placa do motor
#define ENA   14          // Enable/speed motors Right        GPIO14(D5)
#define ENB   12          // Enable/speed motors Left         GPIO12(D6)
#define IN_1  15          // L298N in1 motors Right           GPIO15(D8)
#define IN_2  13          // L298N in2 motors Right           GPIO13(D7)
#define IN_3  2           // L298N in3 motors Left            GPIO2(D4)
#define IN_4  0           // L298N in4 motors Left            GPIO0(D3)
#define Sensor_direita D1
#define Sensor_esquerda D2

bool direita, esquerda;
int speedCar = 750;  //velocidade  400 - 1023.
int speedCurvas = 650; // velocidade 400 -1023

void setup() {
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN_1, OUTPUT);
    pinMode(IN_2, OUTPUT);
    pinMode(IN_3, OUTPUT);
    pinMode(IN_4, OUTPUT);
    pinMode(Sensor_direita, INPUT);
    pinMode(Sensor_esquerda, INPUT);
}

void paraFrente(){
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    analogWrite(ENA, speedCar);

    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
    analogWrite(ENB, speedCar);
}

void paraTras(){
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    analogWrite(ENA, speedCar);

    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
    analogWrite(ENB, speedCar);
}

void paraDireita(){
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    analogWrite(ENA, speedCurvas);

    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
    analogWrite(ENB, speedCurvas);
}

void paraEsquerda(){
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    analogWrite(ENA, speedCurvas);

    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
    analogWrite(ENB, speedCurvas);
}

void pararCarro(){
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
    analogWrite(ENA, speedCar);

    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, LOW);
    analogWrite(ENB, speedCar);
}

void loop() {
    direita = digitalRead(Sensor_direita);
    esquerda = digitalRead(Sensor_esquerda);

    //Rodando os motores dependendo das leituras
    if (direita == false && esquerda == false) {
        paraFrente();
    } else if (direita == false && esquerda == true) {
        delay(1);
        paraEsquerda();
        delay(1);
    } else if (direita == true && esquerda == false) {
        delay(1);
        paraDireita();
        delay(1);
    } else if (direita == true && esquerda == true) {
        pararCarro();
    }
}
