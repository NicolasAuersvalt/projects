#include <Servo.h>

// Micro Servos
Servo left;
Servo right;
Servo bottom; // Base Servo 
Servo top; // Claw Servo

// Components
#define axis_y A2
#define axis_x A3
#define button 6

int x;
int y;

const int tmp = 1000;

void setup(){

  Serial.begin(9600);

  // Pins
  left.attach(2);
  right.attach(3);
  bottom.attach(4);

  // Joystick
  pinMode(axis_x, INPUT);
  pinMode(axis_y, INPUT);
  pinMode(button, INPUT);
}

void loop(){
  
  int angle = analogRead(0);
  int angle1= analogRead(1);
  valbase = map(analogRead(axis_x), 0, 1023, 1, 180);
  
  angle=map(angle, 0, 1023, 20, 73); // altura
  angle1=map(angle1, 0, 1023, 20, 120); // profundidade
  
  Serial.println("Profundidade: ");
  Serial.println(angle);
  Serial.println("Altura: ");
  Serial.println(angle1);


  // Contraido  
  // profundidade 37
  // altura 20
  
  //altura 120
  //prof 83
  
  /*
  // Esticado
  left.write(30);
  right.write(160);
  
  delay(5000);
  //levantado
  left.write(160);
  right.write(30);
  delay(tmp);
  delay(5000);
  */
  
  bottom.write(valbase);
  delay(40);
  left.write(angle);
  delay(40);
  right.write(angle1);
  delay(40);
}


