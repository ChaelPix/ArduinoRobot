/***************************************************************
Le robot tourne d'angle précis avec le gyroscope
****************************************************************/
#include <Wire.h>
#include "MeMegaPi.h"  //Motors library

//-------Components Variables
MeMegaPiDCMotor m_moteurG(PORT1B);
MeMegaPiDCMotor m_moteurD(PORT2B);

//-------Variables
int movementSpeed = 100;  //Vitesse, entre 0 et 255, si les moteurs sont inversés, mettre la valeur en négatif.

//-------Main Functions
void setup()
{
  SetupGyro();
  Serial.begin(115200); 
}

void loop()
{
    AngleRotate_Add(72);
    delay(1000);
    AngleRotate_Set(0);
    delay(1000);
    AngleRotate_Set(180);
    delay(1000);
    AngleRotate_Add(-69);
    delay(1000);
    AngleRotate_Set(0);
    exit(0); //Stop le code
}