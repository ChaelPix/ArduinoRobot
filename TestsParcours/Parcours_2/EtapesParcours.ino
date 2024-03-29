//Variables utiles par étape
struct MoveRotateStep {
  int moveDistance; //distance à parcourir en cm
  int rotateAngle; //rotation après movement, entre -180, 180
  //int ScndLapModifier; //décalage à ajouter/soustraire pour le 2e tour
};

void Steps() {
  
  // const int xSteps = 10; //Nombre d'étapes
  // MoveRotateStep steps[xSteps] = { { 30, -90, -2 }, { 30, 0 , 0}, { 50, 90, 0}, 
  // { 48, 142, 0 }, { 78, 180, 4 }, { 10, -110, 3 }, { 64, -35, 0 }, {19, 0, 0}, {1, 0, 3} }; //Etapes {distance, rotation, modif pr 2e tour}

  // for(int j = 0; j < 2; j++) // 2 Tour
  // {
  //     for (int i = 0; i < xSteps; i++) {
  //     AccurateMoving(steps[i].moveDistance, encodersRPM, 1); // Avance en cm
  //     _delay(25);
  //     AngleRotate_Set(steps[i].rotateAngle); //Règle la rotation du robot
  //     _delay(25);
  //     steps[i].moveDistance += steps[i].ScndLapModifier; //ajuste le décalage au 2e tour
  //   }
  // }


  const int xSteps = 10; //Nombre d'étapes 34
  MoveRotateStep steps[xSteps] = { {80, 0}, {120, -90}, {60, -180}, {75, 90}, {50, 90}, {170, 180}, {70, 90}, {45, -180}, {80, 90}, {100, -90}}; //Etapes {distance, rotation, modif pr 2e tour}

//  const int xSteps = 34; //Nombre d'étapes 34
//    MoveRotateStep steps[xSteps] = { {5, 90}, {5, 180}, {5, -90}, {5, 0}};
 for (int i = 0; i < xSteps; i++) {
      AccurateMoving(steps[i].moveDistance, encodersRPM, 1); // Avance en cm
      _delay(50);
      AngleRotate_Set(steps[i].rotateAngle); //Règle la rotation du robot
      _delay(50);
 }
 
}
