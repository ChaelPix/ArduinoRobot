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