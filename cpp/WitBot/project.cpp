// Configurações passadas pelo App Blynk
#define BLYNK_TEMPLATE_ID "TMPLrG9kgao2"
#define BLYNK_DEVICE_NAME "ESP8266"
#define BLYNK_AUTH_TOKEN "NpE9rh2CVCOxYIGL-78m3zfKID46Rtvh"
#define BLYNK_PRINT Serial

// Bibliotecas
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>
#include <Servo.h>

// You should get Auth Token in the Blynk App.
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Nicolas";
char pass[] = "7707224527";

#define EspSerial Serial1

//SoftwareSerial EspSerial(2, 3); // RX, TX
SoftwareSerial EspSerial(10, 11); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

// Configurações dos Motores
#define pwm 3 /* Transistor */
const int max_range = 200; /* Valor máximo da velocidade */

// Configurações dos Componentes
#define led 2
// #define servo 9
// #define trig 7
// #define echo 6

//Servo servo_motor;

void setup(){
  pinMode(pwm, OUTPUT);
  pinMode(led, OUTPUT);
  // Debug console
  Serial.begin(9600);
  
  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);

  Blynk.begin(auth, wifi, ssid, pass);
  //servo_motor.attach(servo);
}

void loop(){
  Blynk.run();
}
//Pino Virtual Selecionado no Joystick
BLYNK_WRITE(V0){ /* Joystick (V1), Button (V2) */
  int y = param[0].asInt();
  Serial.print(y);
  analogWrite(pwm, y); 
}
BLYNK_WRITE(V1){
  int x = param[1].asInt();
  Serial.print(x);
  analogWrite(pwm, x); 
}
BLYNK_WRITE(V2){
  int l = param.asInt();
  Serial.print(l);

  if(l == 1){
    digitalWrite(led, HIGH);
  }
  if(l == 0){
    digitalWrite(led, LOW);
  }
}
  // Teste

  // Função
  
  // servo_motor.write(x);
