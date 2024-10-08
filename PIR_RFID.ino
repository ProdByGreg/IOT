#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define BUZZER_PIN 6
#define PIR_PIN 2

MFRC522 mfrc522(SS_PIN, RST_PIN);

const String authorizedUIDs[] = {"96 26 D0 F7"};
bool motionDetected = false;
bool alarmActive = false;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  
  Serial.println("Sistema de Alarme Inicializado");}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH) {
    motionDetected = true;
    if (!alarmActive) {
      alarmActive = true;
      tone(BUZZER_PIN, 1000);
      Serial.println("Movimento Detectado! Alarme Ativado!");}}

  if (motionDetected && alarmActive) {
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      String content = "";
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        content.concat(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        content.concat(String(mfrc522.uid.uidByte[i], HEX));}
      content.toUpperCase();
      bool authorized = false;
      
      for (const String &uid : authorizedUIDs) {
        if (content.substring(1) == uid) {
          authorized = true;
          break;}}

      if (authorized) {
        alarmActive = false;
        noTone(BUZZER_PIN); // Desativa o buzzer
        Serial.println("Acesso Autorizado! Alarme Desativado.");
      } else {
        Serial.println("Acesso Negado!");}}}

  if (digitalRead(PIR_PIN) == LOW) {
    motionDetected = false;}

  delay(100);}