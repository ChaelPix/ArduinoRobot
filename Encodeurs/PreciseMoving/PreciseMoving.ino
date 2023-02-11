/***************************************************************
Le robot avance du nombre de cm donné.
Utilise les encodeurs des moteurs

Testé sur robot à chenilles.
****************************************************************/
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <MeMegaPi.h>

//-------Components Variables
MeEncoderOnBoard Encoder_1(SLOT1);
MeEncoderOnBoard Encoder_2(SLOT2);

//-------Private Variables (do not touch)
double angle_rad = PI / 180.0;
double angle_deg = 180.0 / PI;

//-------Variables
int encodersRPM = 50;     //Vitesse, entre 0 et 180, nombre de tours/min des encodeurs

//-------Main Function

/// Met en Pause le code mais permet de continuer la boucle loop()
void _delay(float ms) {
  if (ms < 0.0) {
    ms = 0.0;
  }
  long endTime = millis() + ms;
  while (millis() < endTime) _loop();
}

void setup() {

  InitializeEncoders();
  Serial.begin(9600);

  //Ajouter les étapes ici
  AccurateMoving(40, 50, 1); //Avance de 40cm à 50 rpm
  _delay(1000);
  AccurateMoving(40, 50, -1);//Recule de 40cm à 50 rpm
}

void _loop() {
  Encoder_1.loop();
  Encoder_2.loop();
}

void loop() {
  _loop();
}