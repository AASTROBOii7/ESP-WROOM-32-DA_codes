#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int counter = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  lcd.init();              
  lcd.backlight();          
  lcd.clear();                      
}
void loop() {
  lcd.setCursor(0, 0);        
  lcd.print("Hello world");    
  lcd.setCursor(0,1);
  lcd.print(counter);
  counter = counter + 1;
  delay(500);                        
}
