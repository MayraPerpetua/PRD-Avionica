// Programa : Sensor de temperatura e pressao BMP180
// Autor : FILIPEFLOP
 
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <LiquidCrystal.h>
 
LiquidCrystal lcd(12,11, 5, 4, 3, 2);
 
Adafruit_BMP085 bmp180;
 
int mostrador = 0;
   
void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2);
  if (!bmp180.begin()) 
  {
    Serial.println("Sensor nao encontrado !!");
    while (1) {}
  }
}
   
void loop() 
{   
   lcd.setCursor(0, 0);
   lcd.print("Temp. :  ");
   Serial.print("Temperatura : ");
   if ( bmp180.readTemperature() < 10)
   {
     lcd.print(" "); 
     lcd.print(bmp180.readTemperature());
     Serial.print(bmp180.readTemperature());
     Serial.println(" C");
   }
   else
   {
     lcd.print(bmp180.readTemperature(),1);
     Serial.print(bmp180.readTemperature(),1);
     Serial.println(" C");
   }
   lcd.print(" ");
   lcd.print((char)223); 
   lcd.print("C   ");
       
   if (mostrador == 0)
   {
     lcd.setCursor(0, 1);
     lcd.print("                ");
     lcd.setCursor(0, 1);
     lcd.print("Altit.: ");
     Serial.print("Altitude : ");
     lcd.print(bmp180.readAltitude());
     Serial.print(bmp180.readAltitude());
     Serial.println(" m");
     lcd.print(" m");  
    }
   if (mostrador == 1)
   {
     lcd.setCursor(0, 1);
     lcd.print("                ");
     lcd.setCursor(0, 1);
     lcd.print("Press.: ");
     Serial.print("Pressao : ");
     lcd.print(bmp180.readPressure());  
     Serial.print(bmp180.readPressure());  
     Serial.println(" Pa");
     lcd.print(" Pa");
   }
    
   delay(3000);
   mostrador = !mostrador;
}
