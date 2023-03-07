/***************************************************************
Le robot attend un objet devant son capteur,
puis il le suit en avant-arrière

Testé sur robot à chenilles.
****************************************************************/
#include "MeMegaPi.h"  //Motors library

//-------Components Variables
MeMegaPiDCMotor m_moteurG(PORT1B);
MeMegaPiDCMotor m_moteurD(PORT2B);
MeUltrasonicSensor m_ultraSensor(PORT_5);

//-------Variables
int movementSpeed = 100;  //Vitesse, entre 0 et 255, si les moteurs sont inversés, mettre la valeur en négatif.

static float dist = 2;     //La distance en cm entre le robot et l'obstacle.
static float maxDist = 4;  //La distance max

bool hasSeenObj;
//-------Main Functions
void setup() {
  Serial.begin(9600);
}

void loop() {

  if (!hasSeenObj) {
    hasSeenObj = hasDetectedObstacle(maxDist);
    delay(100);
    return;
  }

double distance = m_ultraSensor.distanceCm();
Serial.println(distance);

  if (distance > dist + 1) {    
    MoveForward();
  } else if(distance <= (dist + 1) && distance >= (dist - 1)) {
    StopMoving();
  } else{
    MoveBackward();
  }

  delay(333);
}