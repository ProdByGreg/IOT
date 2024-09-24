#include<LiquidCrystal.h>
const int sensor = A0;
float temperaturaC = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
 pinMode(A0, INPUT);
 lcd.begin(16, 2); 
}

void loop()
{
  float vsensor = analogRead(sensor);
  
  float tensao = (vsensor*(5.0/1023.0));
  
  temperaturaC = (tensao*100);
  
  Serial.print("Valor do sensor: ");       
  Serial. print(vsensor); 
  
  lcd.setCursor(1,0);  
  lcd.print("Temperatura:"); 
  lcd.setCursor(4,1);           
  lcd.print(temperaturaC);    
  }
