// Param :
//   int rpm > vitesse rpm des encodeurs (entre 25 et rpm max)
// Return :
//   float fact > le facteur pour calculer la durée
// Desc : Donne un facteur précis par palier de 25rpm pour un meilleur calcul de temps
float GetRpmCmFactor(int rpm) {
  float fact = 0;
  rpm = ((rpm / 5) / 5) * 25; //Arrondi au 25 inférieur

  switch (rpm) {
    case 25: fact = 0.2533333; break;
    case 50: fact = 0.275; break;
    case 75: fact = 0.2833333; break;
    case 100: fact = 0.2858333; break;
    case 125: fact = 0.29066666; break;
    case 150: fact = 0.2888888; break;
    default: fact = 0.28;
  }

  return fact;
}

// Param :
//   int cm > Distance à parcourir, en cm
// Return :
//   int time > Temps pour parcourir la distance en rpm donné
// Desc : Calcule le temps de parcours
int CalculateMovingTime(int cm, int rpm) {
  float fact = GetRpmCmFactor(rpm);
  float time = cm / (rpm * fact); //calcul la durée du déplacement à partir de la distance et du temps
  time *= 1000; // converti en ms
  return (int)time;
}

// Param :
//   int distance > Distance à parcourir, en cm
//   int rpm > Rpm voulu
//   int isForward > 1 pour avancer, -1 pour reculer
// Desc : Avance du nombre de cm (à 2cm près) donné
void AccurateMoving(int distance, int rpm, int isForward) {

  rpm *= isForward;  //rpm * -1 inverse le sens de direction
  Encoder_1.runSpeed(-rpm);
  Encoder_2.runSpeed(rpm);

  int time = CalculateMovingTime(distance, abs(rpm));
  _delay(time);

  Encoder_1.setTarPWM(0);  //Stop les moteurs
  Encoder_2.setTarPWM(0);

}