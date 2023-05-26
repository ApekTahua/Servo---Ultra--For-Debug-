// Ultrasonic Depan
#include <header.h>

void ultrasonic_depan()
{
  digitalWrite(TRIG_PIN_1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_1, LOW);

  duration_1 = pulseIn(ECHO_PIN_1, HIGH);
  distance_1 = duration_1 * SOUND_SPEED / 2;
}

void Open_Bin()
{
  servo.write(155);
}