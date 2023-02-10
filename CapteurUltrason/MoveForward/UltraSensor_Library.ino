// Param : 
//   float distance > Distance de détection d'un obstacle, en cm
// Return :
//   False > Pas d'obstacle devant
//   True > Obstacle frontal détecté
// Desc : Indique si un obstacle se trouve dans la distance donnée du capteur ultrason 
bool hasDetectedObstacle(float distance) {
  return m_ultraSensor.distanceCm() < distance;
}

// Param : 
//   int checkingSpeed > temps entre chaque vérification, en ms
//   int timeForTest > temps total avant la fin du test, en ms
//   float distance > distance entre capteur et l'obstacle, en cm
// Return :
//   False > L'obstacle a été retiré
//   True > L'obstacle n'a pas bougé
// Desc : Indique si un obstacle se trouve dans la distance donnée du capteur ultrason 
bool isObstaclePersisting(int checkingSpeed, int timeForTest, float distance) {

  float elapsedTime = 0;
  
  while (hasDetectedObstacle(distance)) {
    delay(checkingSpeed);
    elapsedTime += checkingSpeed;

    if (elapsedTime >= timeForTest)
      return true;
  }

  return false;
}

// Param : 
//   int rotateSpeed > temps de rotation par test, en ms
//   int leftOrRightDir > direction de la rotation, 3: Gauche, 4: Droite
//   float distance > distance entre capteur et l'obstacle, en cm
void TurnUntilWayIsCleared(int rotateSpeed, int leftOrRightDir, float distance)
{
  do {
      MoveTo(leftOrRightDir);
      delay(rotateSpeed);
    } while (hasDetectedObstacle(distance)); 
}