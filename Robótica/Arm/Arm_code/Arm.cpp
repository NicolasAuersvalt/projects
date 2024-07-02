#include <Servo.h>
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>

#define BLYNK_TEMPLATE_ID "TMPL9u3ogMD9"
#define BLYNK_DEVICE_NAME "Arm"
#define BLYNK_AUTH_TOKEN "IVPfVD2Jh9oTBzIbc594SNN4V5-WdQws"

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Nicolas";
char pass[] = "7707224527";

#define EspSerial Serial1

//SoftwareSerial EspSerial(2, 3); RX, TX
SoftwareSerial EspSerial(10, 11); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

#define servo_l 2 // Left
#define servo_c 3 // Claw
#define servo_r 4 // Right
#define servo_b 5 // Bottom

Servo l; // Left Servo Object
Servo c; // Claw Servo Object
Servo r; // Right Servo Object
Servo b; // Bottom Servo Object
  
void setup(){
  EspSerial.begin(ESP8266_BAUD);

  Blynk.begin(auth, wifi, ssid, pass);
  
  Serial.begin(9600);
  l.attach(servo_l);
  c.attach(servo_c);
  r.attach(servo_r);
  b.attach(servo_b);
  l.write(0); // Inicia na posição 0
  r.write(180);
  b.write(90);
  delay(500);
}

void loop(){
  Blynk.run();
}

BLYNK_WRITE(V0){ // ARM
  int y = param[0].asInt(); // Eixo Y
  Serial.print(y);
  l.write(y);
  r.write(180 - y); 
}
BLYNK_WRITE(V1){ // Base
  int x = param[1].asInt(); // Eixo X
  Serial.print(x);
  b.write(x);
}
BLYNK_WRITE(V2){ // Claw
  int l = param.asInt(); // Button
  Serial.print(l);

  if(l == 1){ // Pressionado
    for(int ang=0; ang <180; ang += 5){
    c.write(ang);
  }
  if(l == 0){ // Solto
    for(int ang=0; ang <=180; ang -= 5){
  c.write(ang);
  }
  }
  }
}
