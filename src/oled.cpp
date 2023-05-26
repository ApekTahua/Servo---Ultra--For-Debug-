// Oled
#include <header.h>

void setup_oled()
{
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ;
    }
    delay(2000);
    display.clearDisplay();
    display.setTextColor(WHITE);

    Serial.println("Initializing the scale");
    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
    scale.set_scale(-371);
    scale.tare();
}

void displayWeight(int reading)
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);

    // Display weight
    display.println("Weight:");
    display.display();
    display.setCursor(0, 30);
    display.setTextSize(2);
    display.print(reading);
    display.print(" ");
    display.print("grams");
    display.display();
}
