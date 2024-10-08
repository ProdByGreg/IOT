#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define BUZZER_PIN 6   // Pino do buzzer
#define PIR_PIN 2      // Pino do sensor PIR

MFRC522 mfrc522(SS_PIN, RST_PIN);

const String authorizedUIDs[] = {"96 26 D0 F7"}; // Array de UIDs autorizados
bool motionDetected = false; // Estado do movimento
bool alarmActive = false;    // Estado do alarme

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  
  Serial.println("Sistema de Alarme Inicializado");
}

void loop() {
  // Verifica o sensor PIR
  if (digitalRead(PIR_PIN) == HIGH) {
    motionDetected = true;
    if (!alarmActive) {
      alarmActive = true;
      tone(BUZZER_PIN, 1000); // Ativa o buzzer
      Serial.println("Movimento Detectado! Alarme Ativado!");
    }
  }

  // Verifica se o alarme deve ser desativado com o cartão RFID
  if (motionDetected && alarmActive) {
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      String content = "";
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        content.concat(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        content.concat(String(mfrc522.uid.uidByte[i], HEX));
      }
      content.toUpperCase();
      bool authorized = false;
      
      for (const String &uid : authorizedUIDs) {
        if (content.substring(1) == uid) {
          authorized = true;
          break;
        }
      }

      if (authorized) {
        alarmActive = false;
        noTone(BUZZER_PIN); // Desativa o buzzer
        Serial.println("Acesso Autorizado! Alarme Desativado.");
      } else {
        Serial.println("Acesso Negado!");
      }
    }
  }

  // Reseta o estado do movimento se não houver mais movimento
  if (digitalRead(PIR_PIN) == LOW) {
    motionDetected = false;
  }

  delay(100); // Pequeno atraso
}

