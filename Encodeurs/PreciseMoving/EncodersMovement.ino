// Param :
//   int cm > Distance à parcourir, en cm
// Return :
//   int time > Temps pour parcourir la distance en rpm donné
// Desc : Calcule le temps de parcours
int CalculateMovingTime(int cm, int rpm) {
  float time = cm / (rpm * 0.272);
  time *= 1000;
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