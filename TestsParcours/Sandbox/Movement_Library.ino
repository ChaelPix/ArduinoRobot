//-------Components Variables
MeMegaPiDCMotor m_moteurG(PORT1B);
MeMegaPiDCMotor m_moteurD(PORT2B);
MeUltrasonicSensor m_ultraSensor(PORT_5);

//-------Variables
int movementSpeed = 100;   //Vitesse, entre 0 et 255, si les moteurs sont inversés, mettre la valeur en négatif.


//------------Functions
void TurnLeft() {
  //Serial.println("Turn Left");
  m_moteurG.run(movementSpeed);
  m_moteurD.run(movementSpeed);
}
void TurnRight() {
  //Serial.println("Turn Right");
  m_moteurG.run(-movementSpeed);
  m_moteurD.run(-movementSpeed);
}
void MoveBackward() {
  //Serial.println("Move Backward");
  m_moteurG.run(-movementSpeed);
  m_moteurD.run(movementSpeed);
}
void MoveForward() {
  //Serial.println("Move Forward");
  m_moteurG.run(movementSpeed);
  m_moteurD.run(-movementSpeed);
}
void StopMoving() {
  //Serial.println("Stop Moving");
  m_moteurG.stop();
  m_moteurD.stop();
}

// Param :
//   int direction > 1: MoveF, 2: MoveB, 3: TurnL, 4: TurnR
void MoveTo(int direction)
{
  switch(direction)
    {
      case 1: MoveForward(); break;
      case 2: MoveBackward(); break;
      case 3: TurnLeft(); break;
      case 4: TurnRight();
    }
}