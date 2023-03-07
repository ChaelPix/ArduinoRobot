MeMegaPiDCMotor moteurPince(PORT4B);

//duration 3500 && intensity -100 = full;
void OpenPince(int duration, int intensity)
{
     _ControlPince(duration, -intensity);
}

//duration 3500 && intensity 100 = full;
void ClosePince(int duration, int intensity)
{
    _ControlPince(duration, intensity);
}

void _ControlPince(int duration, int intensity)
{
      moteurPince.run(intensity);  // négatif = ouvrir
      delay(duration);  
      moteurPince.stop();
      
}