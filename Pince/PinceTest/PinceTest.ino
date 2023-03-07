
#include "MeMegaPi.h" //Motors library
#include <Pixy2.h> //Pixy library

Pixy2 pixy;

MeMegaPiDCMotor moteurG(PORT1B);
MeMegaPiDCMotor moteurD(PORT2B);

MeUltrasonicSensor m_ultraSensor(PORT_5);

//-------Variables


//-------Main Functions
void setup() {
  Serial.begin(9600);

  while(true)
    {
      OpenPince(3500, 100);
      delay(50);
      ClosePince(3500, 100);
    }
}


void loop() {


}
