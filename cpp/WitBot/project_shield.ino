#include <AFMotor.h>

// Define o Motor em M1
AF_DCmotor motor1(1); 
AF_DCmotor motor2(2);
AF_DCmotor motor3(3);
AF_DCmotor motor4(4);

void setup(){
    
    // Define a velocidade inicial
    motor1.setSpeed(200);
    motor2.setSpeed(200);
    motor3.setSpeed(200);
    motor4.setSpeed(200);

    // Define a função stop
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}

void movement(){
    /* Unsigned Int = Basic type
    ex: uint8_ = 8 bytes
    uint16 = 16 bytes

    Optimazed for simple systems
    */
    uint8_t i; // i = velocity

    // Sense of Movement
    motor1.run(FORWARD) // Start motor running Forward
    motor2.run(FORWARD)
    motor3.run(BACKWARD) // Start motor running Backward
    motor4.run(BACKWARD)

    // Accelerated Frontal Movement
    for(i=0;i<200;i++){
    motor1.setSpeed(i) 
    motor2.setSpeed(i)
    motor3.setSpeed(i) 
    motor4.setSpeed(i)
    }

    // Retrograde Frontal Movement
    for(i=200;i>=0;i--){
    motor1.setSpeed(i) 
    motor2.setSpeed(i)
    motor3.setSpeed(i) 
    motor4.setSpeed(i)
    }

    // Inverse the Sense
    motor1.run(BACKWARD)
    motor2.run(BACKWARD)
    motor3.run(FORWARD)
    motor4.run(FORWARD)

    // Accelerated Back Movement
    for(i=0;i<200;i++){
    motor1.setSpeed(i) 
    motor2.setSpeed(i)
    motor3.setSpeed(i) 
    motor4.setSpeed(i)
    }

    // Retrograde Back Movement
    for(i=200;i>=0;i--){
    motor1.setSpeed(i) 
    motor2.setSpeed(i)
    motor3.setSpeed(i) 
    motor4.setSpeed(i)
    }
}

void loop(){

    
}

