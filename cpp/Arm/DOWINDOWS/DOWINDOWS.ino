#define BLYNK_TEMPLATE_ID "TMPL9u3ogMD9"
#define BLYNK_DEVICE_NAME "Arm"
#define BLYNK_AUTH_TOKEN "IVPfVD2Jh9oTBzIbc594SNN4V5-WdQws"

//Definicao do monitoramento de conexao da placa pela serial
#define BLYNK_PRINT Serial

//Adicao das bibliotecas
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>
#include <Servo.h>

//Declaracao da variavel que armazena o codigo de autenticacao para conexao
char auth[] = BLYNK_AUTH_TOKEN;

//Declaracao do nome e senha da rede Wi-Fi
//Altere as variaveis abaixo com o nome e senha da sua rede Wi-Fi
char ssid[] = "Nicolas";
char pass[] = "7707224527";

//Criacao do objeto serial para comunicacao com o ESP8266
SoftwareSerial EspSerial(11, 10); // RX, TX

//Declaracao da variavel que armazena a velocidade de comunicacao do modulo
const int ESP8266_BAUD = 9600;

//Confiracao do objeto 'wifi' para usar a serial do ESP8266 para conexao
ESP8266 wifi(&EspSerial);

#define servo_l 2 // Left
#define servo_c 3 // Claw
#define servo_r 4 // Right
#define servo_b 5 // Bottom

Servo l; // Left Servo Object
Servo c; // Claw Servo Object
Servo r; // Right Servo Object
Servo b; // Bottom Servo Object

//Configuracao do codigo
void setup(){

  //Inicializacao do monitor serial
  Serial.begin(9600);

  //Configura o pino do LED interno da placa como saida
  pinMode(LED_BUILTIN, OUTPUT);

  //Inicializa a comunicacao serial do ESP8266
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  //Inicializacao da comunicacao e conexao do modulo ao aplicativo
  Blynk.begin(auth, wifi, ssid, pass);

  l.attach(servo_l);
  c.attach(servo_c);
  r.attach(servo_r);
  b.attach(servo_b);
  

}

//Repeticao do codigo
void loop(){
  Blynk.run(); //Mantem a conexao ativa com o aplicativo e processa comandos recebidos ou enviados
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
