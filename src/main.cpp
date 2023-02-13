#include <Arduino.h>
#include <User_Setups/Setup25_TTGO_T_Display.h>
#include <TFT_eSPI.h>       // Include the graphics library


#include "NotoSansBold15.h"
#include "NotoSansBold36.h"
#include "NotoSansMonoSCB20.h"

// The font names are arrays references, thus must NOT be in quotes ""
#define AA_FONT_SMALL NotoSansBold15
#define AA_FONT_LARGE NotoSansBold36
#define AA_FONT_MONO  NotoSansMonoSCB20

uint8_t readStatus = 0;
float temp = 0;
float humidity = 0;
char buffer[50];

TFT_eSPI tft = TFT_eSPI();

// -------------------------------------------------------------------------
// Setup
// -------------------------------------------------------------------------
void setup(void) {
  Serial.begin(115200);
  Serial.println();

  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_DARKGREY);
}

// -------------------------------------------------------------------------
void loop()
{
  temp = random(0, 100);
  humidity = random(0, 100);

  Serial.println(F("DEMO 1: read 12-bytes, show 255 if communication error is occurred"));
  Serial.print(F("Temperature: ")); Serial.print(temp); Serial.println(F(" +-0.3C")); //by default "AHT10_FORCE_READ_DATA"
  Serial.print(F("Humidity...: ")); Serial.print(humidity);    Serial.println(F(" +-2%"));   //by default "AHT10_FORCE_READ_DATA"


  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_WHITE, TFT_BLACK); // Set the font colour and the background colour

  tft.setTextDatum(TC_DATUM); // Top Centre datum

  int xpos = tft.width() / 2; // Half the screen width
  int ypos = 10+random(0, 20); // 10 pixels down


  tft.loadFont(AA_FONT_LARGE); // Must load the font first


  tft.setTextColor(TFT_LIGHTGREY, TFT_BLACK);

  //tft.drawString("Temp", xpos, ypos);

  ypos += tft.fontHeight();   // Get the font height and move ypos down
  sprintf(buffer, "%.1fC", temp);
  tft.drawString(buffer, xpos, ypos);
  ypos += 2*tft.fontHeight(); 
  //tft.drawString("Humidity", xpos, ypos);

  //ypos += tft.fontHeight();
  sprintf(buffer, "%.1f%%", humidity);

  tft.drawString(buffer, xpos, ypos);

  tft.unloadFont(); // Remove the font to recover memory used


  delay(10000);

  }




/***************************************************************************************************/
/* 
   This is an Arduino library for Aosong ASAIR AHT10, AHT15 Digital Humidity & Temperature Sensor

   written by : enjoyneering79
   sourse code: https://github.com/enjoyneering/

   This chip uses I2C bus to communicate, specials pins are required to interface
   Board:                                    SDA                    SCL                    Level
   Uno, Mini, Pro, ATmega168, ATmega328..... A4                     A5                     5v
   Mega2560................................. 20                     21                     5v
   Due, SAM3X8E............................. 20                     21                     3.3v
   Leonardo, Micro, ATmega32U4.............. 2                      3                      5v
   Digistump, Trinket, ATtiny85............. 0/physical pin no.5    2/physical pin no.7    5v
   Blue Pill, STM32F103xxxx boards.......... PB7                    PB6                    3.3v/5v
   ESP8266 ESP-01........................... GPIO0/D5               GPIO2/D3               3.3v/5v
   NodeMCU 1.0, WeMos D1 Mini............... GPIO4/D2               GPIO5/D1               3.3v/5v
   ESP32.................................... GPIO21/D21             GPIO22/D22             3.3v
    ESP32-S2................................ GPIO21/D21             GPIO22/D22             3.3v
    ESP32-S2 Saola 1 Wrover.................. GPIO21/D21             GPIO22/D22             3.3v
    ESP32-S2 Saola 1 Wrover Kit.............. GPIO21/D21             GPIO22/D22             3.3v
    ESP32-S2 Saola 1 Wrover Module........... GPIO21/D21             GPIO22/D22             3.3v
    ESP32-S2 Saola 1 Wrover Module (Rev 1)... GPIO21/D21             GPIO22/D22             3.3v
    ESP32-S2 Saola 1 Wrover Module (Rev 2)... GPIO21/D21             GPIO22/D22             3.3v
    ESP32-S2 Saola 1 Wrover Module (Rev 3)... GPIO21/D21             GPIO22/D22             3.3v
    ESP32-S2 Saola 1 Wrover Module (Rev 4)... GPIO21/D21             GPIO22/D22             3.3v
    ESP32-S2 Saola 1 Wrover Module (Rev 5)... GPIO21/D21             GPIO22/D22             3.3v
    ESP32-S2 Saola 1 Wrover Module (Rev 6)... GPIO21/D21             GPIO22/D22             3.3v
    ESP32-S2 Saola 1 Wrover Module (Rev 7)... GPIO21/D21             GPIO22/D22             3.3v
    ESP32-S2 Saola 1 Wrover Module (Rev 8)... GPIO21/D21             GPIO22/D22             3.3v
    ESP32-S2 Saola 1 Wrover Module (Rev 9)... GPIO21/D21             GPIO22/D22             3.3v
    ESP32-S2 Saola 1 Wrover Module (Rev 10).. GPIO21/D21             GPIO22/D22             3.3v
    ESP32-S2 Saola 1 Wrover Module (Rev 11).. GPIO21/D21             GPIO22/D22             3.3v
    ESP32-S2 Saola 1 Wrover Module (Rev 12).. GPIO21/D21             GPIO22/D22             3.3v
    ESP32-S2 Saola 1 Wrover Module (Rev 13).. GPIO21/D21             GPIO22/D22             3.3v

    This sensor uses I2C address 0x38(56)

    AHT10/AHT15 datasheet:
    
    https://www.aosong.com/en/pdf/AHT10.pdf
    https://www.aosong.com/en/pdf/AHT15.pdf

*/
