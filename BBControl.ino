#include <SparkFun_TB6612.h> // Motor driver library
#include "FlySkyIBus.h"

// Motor driver pins
#define AIN1 7
#define BIN1 5
#define AIN2 8
#define BIN2 4
#define PWMA 9
#define PWMB 3
#define STBY 6

// these constants are used to allow you to make your motor configuration 
// line up with function names like forward.  Value can be 1 or -1
const int offsetA = 1;
const int offsetB = 1;

// Initializing motors.  The library will allow you to initialize as many
Motor lMotor = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor rMotor = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

int throttle = 0;
int turn = 0;
int lSpeed = 0;
int rSpeed = 0;

void setup()
{
 IBus.begin(Serial); // 115200 baud
}


void loop()
{
  IBus.loop();
  
  throttle = map(IBus.readChannel(2), 1017, 2000, -255, 255);
  turn = map(IBus.readChannel(0), 1026, 2000, -100, 100);
  
  lSpeed = throttle + turn;
  rSpeed = throttle - turn;
  
  lMotor.drive(lSpeed);
  rMotor.drive(rSpeed); 
}
