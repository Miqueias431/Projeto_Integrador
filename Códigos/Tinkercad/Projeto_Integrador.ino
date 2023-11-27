/**
  Iluminação de garagem automática
  ------------------------
  |  Sensor  |  Arduino  |
  |   VCC    |    5V     |
  |  Trig    |    4V     |
  |  Echo    |    A4     |
  |   GND    |    GND    |
  ------------------------
  @author Luis, Pedro, Lucas, Miqueias e Joao
*/
int sensorLDR = 700;
long sensor;
int oitava = 1;
float SE5 = 659.25;
float SC5 = 523.25;
int LED = 9;
int leitor;
#include <Servo.h>
Servo servo1;

void setup() {
  Serial.begin(9600);
  digitalWrite(13, HIGH);    //LEDs do interruptor
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(10, INPUT_PULLUP);  //Campainha
  pinMode(9, OUTPUT);        //LED
  pinMode(8, OUTPUT);        //Buzzer
  pinMode(12, OUTPUT);  
  pinMode(11, OUTPUT);
  pinMode(6, OUTPUT);        //Buzzer
  servo1.attach(7);
  servo1.write(0);
  
 }

void loop() {

bluetooth();
campainha();
sensorLuminosidade();

}

void bluetooth() {



  if (Serial.available()) {                //essa estrutura evita o acionamento indevido do led ou de outros dispostivos
    leitor = Serial.read();                //armazenando a tecla pressionada na variavel leitor
    if (leitor == '1') {                   //se tecla 1 for pressionada
      digitalWrite(12, !digitalRead(12));  //ele vai verificar se o dispositivo esta ativado ou desativado
    } else if (leitor == '2') {            //se tecla 4 for pressionada
      digitalWrite(11, !digitalRead(11));  //ele vai verificar se o dispositivo esta ativado ou desativado
    } else if (leitor == '3') {            //abrir garagem via bluetooth
      abrirg();
    } else if (leitor == '4') {            //fechar garagem via bluetooth        /3 FECHA /4 LED
      fecharg();
    }
  }  
}

void abrirg() {

      servo1.write(90);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      tone(6, 262);
      delay(500);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      noTone(6);
      delay(500);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      tone(6, 262);
      delay(500);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      noTone(6);
      delay(500);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      tone(6, 262);
      delay(500);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      noTone(6);
      delay(500);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      tone(6, 262);
      delay(500);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      noTone(6);
      delay(500);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      tone(6, 262);
      delay(500);
      digitalWrite(4, LOW);
      noTone(6);
}

void fecharg() {
      servo1.write(0);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      tone(6, 262);
      delay(500);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      noTone(6);
      delay(500);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      tone(6, 262);
      delay(500);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      noTone(6);
      delay(500);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      tone(6, 262);
      delay(500);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      noTone(6);
      delay(500);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      tone(6, 262);
      delay(500);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      noTone(6);
      delay(500);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      tone(6, 262);
      delay(500);
      digitalWrite(4, LOW);
      noTone(6);
}

void sensorLuminosidade() {
  
int sensorLDR = analogRead(A0);
if (sensorLDR > 500) {
    digitalWrite(2, LOW);
 } else {
    digitalWrite(2, HIGH);
 }
  
}

void campainha() {
int campainha = 8;
  
  int sw2 = digitalRead(10);

  if (sw2 == 0) {
    tone(campainha, SE5 * oitava);
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
    digitalWrite(LED, HIGH);
    delay(200);
    tone(campainha, SC5 * oitava);
    digitalWrite(LED, LOW);
    delay(200);
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
  } else {
    digitalWrite(LED, LOW);
    noTone(campainha);
  }
}
