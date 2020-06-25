/*************************************************** 
  This is a library example for the MLX90614 Temp Sensor
  Designed specifically to work with the MLX90614 sensors in the
  adafruit shop
  ----> https://www.adafruit.com/products/1747 3V version
  ----> https://www.adafruit.com/products/1748 5V version
  These sensors use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!
  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal_I2C.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
LiquidCrystal_I2C lcd(0x27, 16, 2);

double temp_amb;
double temp_obj;

void setup() {
  Serial.begin(9600);

  Serial.println("Temperature Sensor MLX90614");

  lcd.init();
  lcd.backlight();


  mlx.begin();  
}

void loop() {
  temp_amb = mlx.readAmbientTempC();
  temp_obj = mlx.readObjectTempC();

  lcd.setCursor(0,0);
  lcd.print("Room Temp :");
  lcd.setCursor(10,0);
  lcd.print(temp_amb);
  lcd.setCursor(15,0);
  lcd.write(1);
  lcd.setCursor(0,1);
  lcd.print("Object :");
  lcd.setCursor(10,1);
  lcd.print(temp_obj);
  lcd.setCursor(15,1);
  lcd.write(1);

  Serial.print("Room Temp = ");
  Serial.print(temp_amb);
  Serial.print("Object Temp = ");
  Serial.print(temp_obj);
 Serial.println();
delay(500);


}