#include<Wire.h>
#include <LiquidCrystal_I2C.h> // libray lcd
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
}

void loop(){
  lcd.setCursor(0,0);
  lcd.print("Belajar LCD I2C");
  lcd.setCursor(0,1);
  lcd.print("M.AbidzarChannel");
}
