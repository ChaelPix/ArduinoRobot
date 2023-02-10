/***************************************************************

****************************************************************/
#include "MeMegaPi.h"  //Motors library
#include <Pixy2.h> //Pixy library

//-------Components Variables
Pixy2 pixy;

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
      pixy.ccc.getBlocks();

      if (pixy.ccc.blocks[i].m_x <= 200 && pixy.ccc.blocks[i].m_x >= 125) {
      Serial.println("Objectif Devant!");
      MoveF(); 
      } 
      else if (pixy.ccc.blocks[i].m_x > 125) 
      {
        Serial.println("L'objectif est a Droite");
        TurnR(); 
      }
      else if (pixy.ccc.blocks[i].m_x < 200) {
         Serial.println("L'objectif est a Gauche");
         TurnL(); 
      } else 
      {
        Serial.println("L'objectif n'est pas ici");
        exit(0);
        
      }

      // if(m_ultraSensor.distanceCm() <  triggerDist)
      //   {
      //     Serial.println("Gobelet en position");
      //     hasFoundWater = true;
      //     ApproachContainer();
      //     return;
      //   }
    }
}