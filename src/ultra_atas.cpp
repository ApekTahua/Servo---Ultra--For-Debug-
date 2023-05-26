// Ultrasonic atas
#include <header.h>

void ultrasonic_atas()
{
    digitalWrite(TRIG_PIN_2, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_2, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_2, LOW);

    duration_2 = pulseIn(ECHO_PIN_2, HIGH);
    distance_2 = duration_2 * SOUND_SPEED / 2;

    percentage = (height - distance_2) * 100 / height;
}