#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
void setup() {
  Wire.begin(21, 22);   // SDA, SCL
  lcd.init();
  lcd.backlight();

  dht.begin();

  lcd.setCursor(0, 0);
  lcd.print("ESP32 Weather");
  delay(2000);
  lcd.clear();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Celsius

  if (isnan(humidity) || isnan(temperature)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    delay(2000);
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Hum : ");
  lcd.print(humidity);
  lcd.print(" %");

  delay(2000);
}
