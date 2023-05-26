#include <header.h>
#include <ultra_depan.cpp>
#include <ultra_atas.cpp>
#include <serial_print.cpp>
#include <oled.cpp>
#include <wifi.cpp>
#include <firebase.cpp>

void setup()
{
  Serial.begin(115200);

  pinMode(TRIG_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);

  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);

  pinMode(SERVO_PIN, OUTPUT);

  servo.attach(SERVO_PIN);
  servo.write(0); // Close the bin

  setup_wifi();
  setup_firebase();
  setup_oled();

  timeClient.begin();
  timeClient.update();
  timeClient.setTimeOffset(25200);
}

void loop()
{
  ultrasonic_depan();

  if (distance_1 < distance)
  {
    Open_Bin();
  }
  else
  {
    servo.write(0);
  }

  ultrasonic_atas();
  print_status();
  send24h();
  realtimeSend();
}