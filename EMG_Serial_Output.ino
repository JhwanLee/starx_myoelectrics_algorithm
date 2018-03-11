#include "GLOBALS.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
    int angle, b, t, torque, dir;
  
  //replace oldest array entries with new (scaled) values
  bs[mai] = (int)analogRead(bicepPin)*bScale;
  ts[mai] = (int)analogRead(tricepPin)*tScale;
  //printTwo(bs[mai], ts[mai]);
  if (bs[mai] > bFloating) //subtract off the floating values
    bs[mai] -= bFloating;
  if (ts[mai] > tFloating)
    ts[mai] -= tFloating;
  
  if (bs[mai] > 1024) //make sure it doesn't go above 1024
    bs[mai] = 1024;
  if (ts[mai] > 1024)
    ts[mai] = 1024;

  b = 0;
  t = 0;
  for (int avgcount = 0; avgcount < AVERAGEINTERVAL; avgcount++)
  {
    b += bs[avgcount];
    t += ts[avgcount];
  }
  b /= AVERAGEINTERVAL;
  t /= AVERAGEINTERVAL;
  
  //angle = 1024 - analogRead(potPin);// angle is not an array
  //Serial.println("MAI Tricep\t");
  Serial.println(t);
  //Serial.print("\t MAI Bicep\t");
  Serial.println(b);
}
