#include <header.h>

// int capacity = (BIN_HEIGHT - distance_2) / BIN_HEIGHT * 100;

void setup()
{
  Serial.begin(115200);

  pinMode(TRIG_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);

  // pinMode(TRIG_PIN_2, OUTPUT);
  // pinMode(ECHO_PIN_2, INPUT);

  servo.attach(SERVO_PIN);
  servo.write(0); // Close the bin
}

void Open_Bin()
{
  servo.write(155);
}

void print_status()
{
  Serial.print("Distance Depan: ");
  Serial.print(distance_1);
  Serial.println(" cm");

  // Serial.print("Distance Atas: ");
  // Serial.print(distance_2);
  // Serial.println(" cm");

  // Serial.print("Capacity: ");
  // Serial.print(capacity);
  // Serial.println(" %");

  delay(1000);
}

void loop()
{
  digitalWrite(TRIG_PIN_1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_1, LOW);

  // digitalWrite(TRIG_PIN_2, LOW);
  // delayMicroseconds(2);
  // digitalWrite(TRIG_PIN_2, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(TRIG_PIN_2, LOW);

  duration_1 = pulseIn(ECHO_PIN_1, HIGH);
  distance_1 = duration_1 * SOUND_SPEED / 2;

  // duration_2 = pulseIn(ECHO_PIN_2, HIGH);
  // distance_2 = duration_2 * SOUND_SPEED / 2;

  if (distance_1 < distance)
  {
    Open_Bin();
  }
  else
  {
    servo.write(0);
  }

  print_status();
}