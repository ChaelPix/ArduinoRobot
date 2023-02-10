bool hasDetectedObstacle()
{
  return m_ultraSensor.distanceCm() < triggerDist;;
}

void TurnToClearTheWay()
{
  do {
      TurnL(); //Tourne vers la gauche
      delay(rotateSpeed); //Temps de tourner
    } while (hasDetectedObstacle()); //Tant qu'il y a un objet devant le capteur
}
