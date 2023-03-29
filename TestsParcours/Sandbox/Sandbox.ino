/***************************************************************
Parcours où le robot doit passer une ligne droite semée d'obstacles disposés mobiles disposés aléatoirement.
Le robot doit donc conserver sa vitesse et sa trrajectoire. 
Le robot doit faire 2 tours en partant du carré blanc, et arriver au dernier tour dessus.
Il doit éviter de toucher les limites du parcours.

Restriction : Le robot ne peut utiliser ses Moteurs/Encodeurs et le gyroscope.

Testé sur robot à chenilles.
****************************************************************/
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <MeMegaPi.h>

//-------Components Variables
MeEncoderOnBoard Encoder_1(SLOT1);
MeEncoderOnBoard Encoder_2(SLOT2);
MeEncoderOnBoard Encoder_3(SLOT3);

//-------Private Variables (do not touch)
double angle_rad = PI / 180.0;
double angle_deg = 180.0 / PI;

//-------Variables
int encodersRPM = 75;  //Vitesse, entre 0 et 180, nombre de tours/min des encodeurs, 25, 50, 75, 100, 125 conseillés

//-------Main Function

/// Met en Pause le code mais permet de continuer la boucle loop()
void _delay(float ms) {
  if (ms < 0.0) {
    ms = 0.0;
  }
  long endTime = millis() + ms;
  while (millis() < endTime) _loop();
}

void FapFap()
{
  while(true)
  {
    Encoder_3.moveTo(75);
    _delay(750);
    Encoder_3.moveTo(-10); 
    _delay(750);
  } 
}

void OP()
{
   while(true)
    {
      OpenPince(0, 100);
      delay(50);
      ClosePince(3500, 100);
    }
}

void Pickup()
{
  OpenPince(0, 255);
  delay(50);
  
  Encoder_3.moveTo(75);
  _delay(750);
  
  ClosePince(0, 255);
  _delay(250);
  
  Encoder_3.moveTo(-10);
}

//Fonction de lancement du programme
void setup() {

  SetupGyro();
  InitializeEncoders();
  Serial.begin(9600);

  //Ajouter les étapes ici
  Pickup();
  _delay(3000);
  OpenPince(0, 255);
  
}

//Boucler Alternative, pour pouvoir agir sur le robot même pendant un delay(). (utilisation de _delay())
void _loop() {
  Encoder_1.loop();
  Encoder_2.loop();
  Encoder_3.loop();
  UpdateGyro();
}

void loop() {
  _loop(); 
}