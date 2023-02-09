#include "MeMegaPi.h" //Motors library

MeMegaPiDCMotor moteurG(PORT1B);
MeMegaPiDCMotor moteurD(PORT2B);

//-------Variables
int movementSpeed = 100; //Max 255
static float triggerDist = 3; //cm

static float moves = 3;
bool isRunning = true;

//-------Main Functions
void setup() {
  Serial.begin(9600);



  while(isRunning)
  {
   moteurG.run(movementSpeed);
  moteurD.run(-movementSpeed);
    if(m_ultraSensor.distanceCm() < 1)
    {
      isRunning = false;
      Serial.println("Obstacle detecte");
      StopMove();
    }
  }

}