

#include <Stepper.h>    // Stepper Motor Library which contains all the needed functions

const int stepsPerRevolution = 360;  // Now, each step is 1 degree



// Making pins 8,9,10 & 11 control the stepper motors:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);



int stepCount = 0;  // indexing the number of steps

void setup() 
{
}

void loop() 
{

  // Keep pin A0 HIGH
  int sensorReading = analogRead(A0);


 
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);


 
  if (motorSpeed > 0) {
    
    // Declare motor speed
    // If we need to make the motor stop, we will need to write "myStepper.setSpeed(0);" after the function
    myStepper.setSpeed(motorSpeed);


    // step 1/100 of a revolution:
    // We said that each step = 1 degree, so we divide 360 over 100
    //*(im not sure why 100, but this number is mentioned in the "map" function, maybe it equals 360 degrees)
    //** if you have time, replace "100" with "360" here, and in the "map" function, and try to only write the degrees, no division needed
    myStepper.step( 360/100);


  }
}



