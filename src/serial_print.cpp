// Untuk print data ke serial monitor + HX711 + OLED
#include <header.h>

void print_status()
{
    weight = scale.get_units();

    float lastReading;

    if (scale.wait_ready_timeout(2000))
    {
        Serial.print("Weight: ");
        Serial.print(weight);
        Serial.println(" g");

        Serial.print("Distance Depan: ");
        Serial.print(distance_1);
        Serial.println(" cm");

        Serial.print("Distance Atas: ");
        Serial.print(distance_2);
        Serial.println(" cm");

        Serial.print("Percentage: ");
        Serial.print(percentage);
        Serial.println(" %");

        if (weight != lastReading)
        {
            displayWeight(weight);
        }
        lastReading = weight;
    }
    else
    {
        Serial.println("HX711 Hilang cokkk");
    }
    scale.power_down(); // put the ADC in sleep mode
    delay(100);
    scale.power_up();
}