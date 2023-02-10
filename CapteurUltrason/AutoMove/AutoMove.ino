/***************************************************************
Le robot avance, 
lorsque le capteur ultrason detecte un obsctale, 
le robot tourne jusqu'à ce que l'obstacle ne soit plus devant.
Il va répéter cette boucle "moves" fois.

Testé sur robot à chenilles.
****************************************************************/
#include "MeMegaPi.h"  //Motors library

//-------Components Variables
MeMegaPiDCMotor m_moteurG(PORT1B);
MeMegaPiDCMotor m_moteurD(PORT2B);
MeUltrasonicSensor m_ultraSensor(PORT_5);

//-------Variables
int movementSpeed = 100;   //Vitesse, entre 0 et 255, si les moteurs sont inversés, mettre la valeur en négatif.
int rotationSpeed = 1000;  //Temps de rotation, en ms. Plus la valeur est grande, plus le robot tourne
int direction = 3;         //3: Tourne vers la gauche, 4: vers la droite

static float triggerDist = 2;  //La distance en cm entre le robot et l'obstacle.
static float moves = 12;       //Nombre de fois que le robot va répéter ce code

//-------Main Function
void setup() {
  Serial.begin(9600);
}

void loop() {

  MoveForward();  //Avance

  if (hasDetectedObstacle(triggerDist)) {
    moves--;       //Retire un déplacement
    StopMoving();  //Stop ses mouvements

    if (moves < 0)  //Stop le programme si le robot n'a plus de movements
      exit(0);

    delay(100);                                                    //Petit temps de transition
    TurnUntilWayIsCleared(rotationSpeed, direction, triggerDist);  //Le robot tourne sur lui même jusqu'à ne plus avoir d'obstacle devant son capteur

  }
}
