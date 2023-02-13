MeGyro gyro;

/*
Desc :
  Démarre le gyroscope
*/
void SetupGyro() {
  gyro.begin();

}

/*
Desc :
  Actualise le gyroscope
*/
void UpdateGyro()
{
  gyro.update();
}

/*
Desc :
  Récupère l'angle Z du robot en int
*/
int GetGyroZ() {
  return (int)gyro.getAngleZ();
}

/*
Param :
  int direction : direction 3: Gauche, 4: Droite
  int anglet Target : Angle à atteindre
Desc :
  Tourne le robot jusqu'à atteindre l'angle donné.
  A NE PAS UTILISER EXTERIEUREMENT
*/
void RotatingToTarget(int direction, int angleTarget) {
  do {
    MoveTo(direction);  //Continu de tourner
    gyro.update();      //reactualise le gyro

    Serial.println(angleTarget);
    Serial.println(GetGyroZ());

  } while (GetGyroZ() != angleTarget);  //Tant que l'angle du gyro != l'objectif

  StopMoving();  //S'arrete quand fini
}

/*
Param :
  int angleAdd : angle à ajouter au robot. Ex : 90 -> Tourne de 90 degrés vers la gauche.
  Négatif = Tourner Gauche, Positif = Tourner Droite
*/
void AngleRotate_Add(int angleAdd) {
  gyro.update();

  int actualAngle = gyro.getAngleZ() + 179;                  //Recupere angle et le map sur 0-359
  int angleTarget = ((actualAngle + angleAdd) % 359) - 178;  //Ajoute l'angle voulu, et remap sur -179;179

  int direction = 4;                //Tourne à droite
  if (angleAdd < 0) direction = 3;  //Si angle négatif, tourne à gauche

  AngleTargetChecker(angleTarget);
  RotatingToTarget(direction, angleTarget);
}

/*
Param :
 int &angleTarget : angle à atteindre
Desc :
  Corrige l'angle si il dépasse de -179;179
*/
void AngleTargetChecker(int &angleTarget) {
  if (angleTarget >= 180)
    angleTarget = 179;
  if (angleTarget <= -180)
    angleTarget = -179;
}

/*
Param :
  int angleTarget : angle à atteindre (-179;179)      (+ = Gauche, - = Droite)
*/
void AngleRotate_Set(int angleTarget) {

  AngleTargetChecker(angleTarget);

  int direction = 3;
  gyro.update();
  int x = GetGyroZ() - angleTarget;
  if (x >= 180) x = (x - 180) * -1;
  if (x < 0)  //sens horaire
    direction = 4;

  RotatingToTarget(direction, angleTarget);
}