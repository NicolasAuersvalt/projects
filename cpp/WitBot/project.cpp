// Configurações passadas pelo App Blynk
#define BLYNK_TEMPLATE_ID "TMPLrG9kgao2"
#define BLYNK_DEVICE_NAME "ESP8266"
#define BLYNK_AUTH_TOKEN "NpE9rh2CVCOxYIGL-78m3zfKID46Rtvh"
#define BLYNK_PRINT Serial

// Bibliotecas
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>

// You should get Auth Token in the Blynk App.
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Nicolas";
char pass[] = "7707224527";

#define EspSerial Serial1

//SoftwareSerial EspSerial(2, 3); // RX, TX
SoftwareSerial EspSerial(11, 10); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

// Configurações dos Motores
#define pwm 3 /* Transistor */
const int max_range = 200; /* Valor máximo da velocidade */

void setup(){
  pinMode(pwm, OUTPUT);-

  // Debug console
  Serial.begin(9600);
  
  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);

  Blynk.begin(auth, wifi, ssid, pass);
}

void loop(){
  Blynk.run();
}

//Pino Virtual Selecionado no Joystick
BLYNK_WRITE(V1){ /* Joystick (V1), Button (V2) */
  int y = param[0].asInt();
  
  // Teste
  Serial.print(y);

  // Função
  analogWrite(pwm, y);
}
