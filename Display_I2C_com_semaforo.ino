#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define ENDERECO  0x27 // Endereço do Display I2C
#define COLUNAS   16
#define LINHAS    2

LiquidCrystal_I2C lcd(ENDERECO, COLUNAS, LINHAS);

const int ledVermelho = 2;
const int ledVerde = 3;
const int ledAmarelo = 4;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);}

void loop() {
  digitalWrite(ledVermelho, HIGH);
  lcd.clear();
  lcd.print("Vermelho");
  delay(2000);
  digitalWrite(ledVermelho, LOW);

  digitalWrite(ledVerde, HIGH);
  lcd.clear();
  lcd.print("Verde");
  delay(3000);
  digitalWrite(ledVerde, LOW);
  
  digitalWrite(ledAmarelo, HIGH);
  lcd.clear();
  lcd.print("Amarelo");
  delay(1000);
  digitalWrite(ledAmarelo, LOW);}
