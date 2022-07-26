// Configurações passadas pelo App Blynk
#define BLYNK_TEMPLATE_ID "TMPLrG9kgao2"
#define BLYNK_DEVICE_NAME "ESP8266"
#define BLYNK_AUTH_TOKEN "NpE9rh2CVCOxYIGL-78m3zfKID46Rtvh"
#define BLYNK_PRINT Serial

// Bibliotecas
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>
#include <AFMotor.h>

// You should get Auth Token in the Blynk App.
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Nicolas";
char pass[] = "7707224527";

#define EspSerial Serial1

SoftwareSerial EspSerial(9, 10); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

// Define o Motor em M1
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

const int max_range = 200; /* Valor máximo da velocidade */

// Configurações dos Componentes
#define led 2

int time; // Delay Time

// #define servo 9
// #define trig 7
// #define echo 6

//Servo servo_motor;

int mov(int time, int xv, int yv) {

  int x = (xv * 10) / 10;
  int y = (yv * 10) / 10;
  int starting_position = 12800;
  Serial.println("X: ");
  Serial.println(x);
  Serial.println("// Y: ");
  Serial.println(y);
  
  /*
    - Frontal
    motor1 - Right
    motor2 - Left

    - Back
    motor3 - Left
    motor4 - Right
  */
  
  // Accelerated Movement

  if ((x > starting_position) && (y > starting_position)) // Right Turn
  {
    Serial.println("Right Turn!!"); // TESTE
    
    // Start motor running (FORWARD AND BACKWARD)
    motor1.run(RELEASE);
    motor1.setSpeed(y);
     // Stopped

    motor2.setSpeed(y);
    motor2.run(FORWARD);

    motor3.setSpeed(y);
    motor3.run(BACKWARD);

    motor4.setSpeed(y);
    motor4.run(BACKWARD);
    delay(time);
  }

  else if ((x < starting_position) && (y > starting_position)) // Left Turn
  {
    Serial.println("Left Turn!!");
    motor1.run(FORWARD);
    motor1.setSpeed(y);
    
    motor2.setSpeed(y);
    motor2.run(RELEASE);

    motor3.setSpeed(y);
    motor3.run(BACKWARD);

    motor4.setSpeed(y);
    motor4.run(BACKWARD);
    delay(time);
  }

  // Retograde Movement

  else if ((x > starting_position) && (y < starting_position)) // Right Turn ALAN
  {
    Serial.println("ALAN!!");
    motor1.setSpeed(y);
    motor1.run(RELEASE);

    motor2.setSpeed(y);
    motor2.run(BACKWARD);

    motor3.setSpeed(y);
    motor3.run(FORWARD);

    motor4.setSpeed(y);
    motor4.run(FORWARD);
    delay(time);
  }

  else if ((x < starting_position) && (y < starting_position)) // Left Turn CELL
  {
    Serial.println("CELL!!");
    motor1.run(BACKWARD);
    motor1.setSpeed(y);

    motor2.setSpeed(y);
    motor2.run(RELEASE);

    motor3.setSpeed(y);
    motor3.run(FORWARD);

    motor4.setSpeed(y);
    motor4.run(FORWARD);
    delay(time);
  }

  else if ((x == starting_position) && (y > starting_position)) // BÃO
  {
    Serial.println("BÃO");
    motor1.setSpeed(y);
    motor1.run(FORWARD);

    motor2.setSpeed(y);
    motor2.run(FORWARD);

    motor3.setSpeed(y);
    motor3.run(BACKWARD);

    motor4.setSpeed(y);
    motor4.run(BACKWARD);
    delay(time);
  }

  else if ((x == starting_position) && (y < starting_position)) // TUDO SIM
  {
    Serial.println("TUDO SIM");
    motor1.setSpeed(y);
    motor1.run(BACKWARD);

    motor2.setSpeed(y);
    motor2.run(BACKWARD);

    motor3.setSpeed(y);
    motor3.run(FORWARD);

    motor4.setSpeed(y);
    motor4.run(FORWARD);
    delay(time);
  }
  else if ((x == starting_position) && (y == starting_position)) // ATA
  {
    Serial.println("ATA");
    motor1.setSpeed(10);
    motor1.run(FORWARD);

    motor2.setSpeed(y);
    motor2.run(RELEASE);

    motor3.setSpeed(y);
    motor3.run(RELEASE);

    motor4.setSpeed(y);
    motor4.run(RELEASE);
    delay(time);
  }
}

void setup() {
  motor1.setSpeed(200);
  motor1.run(RELEASE);
  motor2.setSpeed(200);
  motor2.run(RELEASE);
  motor3.setSpeed(200);
  motor3.run(RELEASE);
  motor4.setSpeed(200);
  motor4.run(RELEASE);
  
  // Debug console
  Serial.begin(9600);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);

  Blynk.begin(auth, wifi, ssid, pass);

  // Defines the Inicial Velocity
  // Defines the Stop Function

  
}

void loop() {
  Blynk.run();
}

/*
  Joystick (V0 and V1)
  Led_Button (V3)
*/

/* Pino Virtual Selecionado no Joystick

*/
BLYNK_WRITE(V1){ 
  int xv = param[0].asInt();
  int yv = param[1].asInt();

  Serial.println("// yv: ");
  Serial.print(yv);

  mov(time, xv, yv);
}



/*
  BLYNK_WRITE(V1){ // X_Axis
  int x = param[0].asInt();
  Serial.print(x);
  //analogWrite(pwm, x);
  }
*/


/*
  // Led
  BLYNK_WRITE(V3){
  int l = param.asInt();
  Serial.print(l);

  if(l == 1){
    digitalWrite(led, HIGH);
  }
  if(l == 0){
    digitalWrite(led, LOW);
  }
  }
*/