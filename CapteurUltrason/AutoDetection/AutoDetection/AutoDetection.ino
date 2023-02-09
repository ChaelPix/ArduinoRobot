#include "MeMegaPi.h" //Motors library

MeMegaPiDCMotor moteurG(PORT1B);
MeMegaPiDCMotor moteurD(PORT2B);
MeUltrasonicSensor m_ultraSensor(PORT_5);

//-------Variables
int movementSpeed = 100; //Max 255
static float triggerDist = 1; //cm
static float moves = 3;

bool m_isRunning = true;

//-------Main Function

void setup() {

  Serial.begin(9600);

  // while(m_isRunning)
  // {
    
  // }



}

void loop()
{
  if(!m_isRunning) return;
  
  MoveF();   
  
    if(hasDetectedObstacle())
      {
        ObstacleDetected();
      }
}