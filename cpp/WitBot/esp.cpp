/* Comment this out to disable prints and save space */
#define BLYNK_TEMPLATE_ID "TMPLrG9kgao2"
#define BLYNK_DEVICE_NAME "ESP8266"
#define BLYNK_AUTH_TOKEN "NpE9rh2CVCOxYIGL-78m3zfKID46Rtvh"
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "Nicolas";
char pass[] = "7707224527";


// Hardware Serial on Mega, Leonardo, Micro...
#define EspSerial Serial1

// or Software Serial on Uno, Nano...
// #include <SoftwareSerial.h>
//SoftwareSerial EspSerial(2, 3); // RX, TX

SoftwareSerial EspSerial(11, 10); // RX, TX
// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

#define pwm 3 /* Transistor */
int tmp = 40; /* Tempo de rotação */
int max_range = 200;

void movimento(int y){
  /* Neutro */
  if(y = 0){
    analogWrite(pwm, 0); 
  }
  /* Frente */
  else if(y > 0 && y <= max_range){
    analogWrite(pwm, y); 
  }
}
void setup(){
  pinMode(pwm, OUTPUT);
  // Debug console
  Serial.begin(9600);

  delay(10);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
}

void loop()
{
  Blynk.run();
}
  BLYNK_WRITE(V1){               //pino virtual selecionado no joystick
  int y = param[1].asInt();
  movimento(y);
  Serial.print(y);
}
