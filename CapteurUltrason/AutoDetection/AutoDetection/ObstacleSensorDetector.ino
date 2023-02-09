bool hasDetectedObstacle()
{
  bool hasIt =  m_ultraSensor.distanceCm() < triggerDist;
  if(hasIt) Serial.println("Obstacle detecte");
  return hasIt;
}

void ClearingObstacle()
{
  while(hasDetectedObstacle())
        {
          TurnL();
          delay(100);
        } 
}

void ObstacleDetected()
{
      moves--;
      if(moves == 0)
      {
        m_isRunning = false;
        StopMove();
      }  else {
      ClearingObstacle();
      }
}
