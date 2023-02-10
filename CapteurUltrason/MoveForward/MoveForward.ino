/***************************************************************
Le robot avance, 
lorsque le capteur ultrason detecte un obsctale, 
le robot s'arrête. 
Si l'obstacle reste trop longtemps, le robot s'éteint.

Testé sur robot à chenilles.
****************************************************************/
#include "MeMegaPi.h"  //Motors library

//-------Components Variables
MeMegaPiDCMotor m_moteurG(PORT1B);
MeMegaPiDCMotor m_moteurD(PORT2B);
MeUltrasonicSensor m_ultraSensor(PORT_5);

//-------Variables
int movementSpeed = 100;   //Vitesse, entre 0 et 255, si les moteurs sont inversés, mettre la valeur en négatif.
int timeBeforeOff = 1500;  //Temps d'attente devant l'obstacle, en ms.

static float triggerDist = 1;  //La distance en cm entre le robot et l'obstacle.

int elapsedTime = 0;

//-------Main Functions
void setup() {
  Serial.begin(9600);
}

void loop() {
  MoveForward();

  if (hasDetectedObstacle(triggerDist)) {
    StopMoving();
    
    bool isObstacle = isObstaclePersisting(200, timeBeforeOff, triggerDist);
    if(isObstacle) exit(0);
  }
}