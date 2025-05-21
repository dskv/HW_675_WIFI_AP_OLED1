//Arduino Code
//Works on, Boad type as: "Adafruit QT Py ESP32-C3"
//Dont forget to make sure that you downloaded and installed the board manager: "'esp32' by Espressif Systems"

#include <U8g2lib.h>
#include <Wire.h>

// there is no 72x40 constructor in u8g2 hence the 72x40 screen is mapped in the middle of the 132x64 pixel buffer of the SSD1306 controller
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, 6, 5);
int width = 72;
int height = 40;
int xOffset = 30; // = (132-w)/2
int yOffset = 12; // = (64-h)/2

void setup(void)
{
     delay(1000);
     u8g2.begin();
     u8g2.setContrast(255); // set contrast to maximum 
     u8g2.setBusClock(400000); //400kHz I2C 
     u8g2.setFont(u8g2_font_ncenB10_tr);
}

void loop(void)
{
    u8g2.clearBuffer(); // clear the internal memory
    u8g2.drawFrame(xOffset+0, yOffset+0, width, height); //draw a frame around the border
    u8g2.setCursor(xOffset+15, yOffset+25);
    u8g2.printf("%dx%d", width, height);
    u8g2.sendBuffer(); // transfer internal memory to the display
    u8g2.
}
