#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <MeMegaPi.h>

double angle_rad = PI / 180.0;
double angle_deg = 180.0 / PI;
MeEncoderOnBoard Encoder_1(SLOT1);
MeEncoderOnBoard Encoder_2(SLOT2);

void isr_process_encoder1(void) {
  if (digitalRead(Encoder_1.getPortB()) == 0) {
    Encoder_1.pulsePosMinus();
  } else {
    Encoder_1.pulsePosPlus();
  }
}

void isr_process_encoder2(void) {
  if (digitalRead(Encoder_2.getPortB()) == 0) {
    Encoder_2.pulsePosMinus();
  } else {
    Encoder_2.pulsePosPlus();
  }
}

void _delay(float ms) {
  if (ms < 0.0) {
    ms = 0.0;
  }
  long endTime = millis() + ms;
  while (millis() < endTime) _loop();
}

void setup() {
  //Set PWM 8KHz
  TCCR1A = _BV(WGM10);
  TCCR1B = _BV(CS11) | _BV(WGM12);

  TCCR2A = _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS21);

  attachInterrupt(Encoder_1.getIntNum(), isr_process_encoder1, RISING);
  Encoder_1.setPulse(8);
  Encoder_1.setRatio(46.67);
  Encoder_1.setPosPid(1.8, 0, 1.2);
  Encoder_1.setSpeedPid(0.18, 0, 0);

  attachInterrupt(Encoder_2.getIntNum(), isr_process_encoder2, RISING);
  Encoder_2.setPulse(8);
  Encoder_2.setRatio(46.67);
  Encoder_2.setPosPid(1.8, 0, 1.2);
  Encoder_2.setSpeedPid(0.18, 0, 0);

  Serial.begin(9600);

  Encoder_1.runSpeed(-60);
  Encoder_2.runSpeed(60);  //encodeur avance à x r/min
  _delay(6127); // cm voulu * 6 / 81.5 ou temps = cm/(rpm*0.27322)

  Encoder_1.setTarPWM(0);
  Encoder_2.setTarPWM(0);
  // Encoder_1.move(-1000,abs(50)); //encodeur tourne de x degré à y r/min
  // Encoder_2.move(1000,abs(50)); //encodeur tourne de x degré à y r/min

  //Get speed
  //   Encoder_1.setMotorPwm(100);
  // Encoder_2.setMotorPwm(-100);
  // Encoder_1.updateSpeed();
  // Encoder_2.updateSpeed();
  // Serial.print("Spped 1 : ");
  // Serial.print(Encoder_1.getCurrentSpeed());
  // Serial.print(" ,Spped 2 : ");
  // Serial.println(Encoder_2.getCurrentSpeed());
}
void _loop() {
  Encoder_1.loop();
  Encoder_2.loop();
}

void loop() {
  _loop();
}