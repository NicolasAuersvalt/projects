// Developed by Nícolas Auersvalt
/*
Robotic Car with Arm controlled by Blink IOT.

Current Version(1.1)
*/

// Blink App
#define BLYNK_TEMPLATE_ID "TMPLrG9kgao2"
#define BLYNK_DEVICE_NAME "ESP8266"
#define BLYNK_AUTH_TOKEN "NpE9rh2CVCOxYIGL-78m3zfKID46Rtvh"
#define BLYNK_PRINT Serial

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>
#include <AFMotor.h>

// You should get Auth Token in the Blynk App.
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "removed_for_security";
char pass[] = "removed_for_security";

#define EspSerial Serial1

// ESP Pins
SoftwareSerial EspSerial(9, 10); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

// Define motors in M[1-4] output
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

const int max_range = 200; /* Valor máximo da velocidade */

// Components (soon)
#define led 2

// Delay Time
int time; 

// Arm Motors (soon)
// #define servo 9
// #define trig 7
// #define echo 6

// Servo servo_motor;

int mov(int time, int x, int y)
{
    int starting_position = 128;
    int lim_nx = 108;
    int lim_x = 148;

    /*
      Motors Position:

        motor1 - Frontal Left

        motor2 - Back Left

        motor3 - Back Right

        motor4 - Frontal Right
    */

    // Accelerated Motion

    if ((x > lim_x) && (y > starting_position)) // Frontal Right Turn
    {
        Serial.println("Frontal Right Turn");

        // Start motor running (FORWARD AND BACKWARD)
        motor1.run(BACKWARD); // Frontal Left
        motor1.setSpeed(y);

        motor2.setSpeed(y); // Back Left
        motor2.run(FORWARD);

        motor3.setSpeed(y); // Back Right
        motor3.run(FORWARD);

        motor4.setSpeed(y);  // Frontal Right
        motor4.run(RELEASE); // Stopped
        delay(time);
    }

    else if ((x < lim_nx) && (y > starting_position)) // Frontal Left Turn
    {
        Serial.println("Frontal Left Turn");
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

    // Retograde Motion

    else if ((x > lim_x) && (y < starting_position)) // Back Right Turn
    {
        Serial.println("Back Right Turn");
        motor1.setSpeed(255-y);
        motor1.run(FORWARD);

        motor2.setSpeed(255-y);
        motor2.run(FORWARD);

        motor3.setSpeed(255-y);
        motor3.run(RELEASE);

        motor4.setSpeed(255-y);
        motor4.run(BACKWARD);
        delay(time);
    }

    else if ((x < lim_nx) && (y < starting_position)) // Back Left Turn
    {
        Serial.println("Back Left Turn!");
        motor1.run(FORWARD);
        motor1.setSpeed(255-y);

        motor2.setSpeed(255-y);
        motor2.run(RELEASE);

        motor3.setSpeed(255-y);
        motor3.run(BACKWARD);

        motor4.setSpeed(255-y);
        motor4.run(BACKWARD);
        delay(time);
    }

    else if ((x == starting_position) && (y == starting_position)) // Rest
    {
        Serial.println("Resting");
        motor1.setSpeed(y);
        motor1.run(RELEASE);

        motor2.setSpeed(y);
        motor2.run(RELEASE);

        motor3.setSpeed(y);
        motor3.run(RELEASE);

        motor4.setSpeed(y);
        motor4.run(RELEASE);
        delay(time);
    }

    else if ((lim_nx < x < lim_x) && (y > starting_position)) // Frontal Movement
    {
        Serial.println("Frontal Motion");
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

    else if ((lim_nx < x < lim_x) && (y < starting_position)) // Back Movement
    {
        Serial.println("Back Motion");
        motor1.setSpeed(255-y);
        motor1.run(FORWARD);

        motor2.setSpeed(255-y);
        motor2.run(FORWARD);

        motor3.setSpeed(255-y);
        motor3.run(BACKWARD);

        motor4.setSpeed(255-y);
        motor4.run(BACKWARD);
        delay(time);
    }
}

void setup()
{
    // Debug console
    Serial.begin(9600);

    // Set ESP8266 baud rate
    EspSerial.begin(ESP8266_BAUD);

    Blynk.begin(auth, wifi, ssid, pass);
}

void loop()
{
    Blynk.run();
}

/*
  Pins List:
    Joystick (V0)
*/

// Joystick Virtual Pins
BLYNK_WRITE(V0)
{
    int x = param[0].asInt(); // X Axis
    int y = param[1].asInt(); // Y Axis
    mov(time, x, y);
}

// Coming Soon!

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
