#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <SPI.h>
#include <MFRC522.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define LM35_PIN A1
#define LDR_PIN A0
#define BUZZER_PIN 3
#define TTP224_PIN_1 4
#define TTP224_PIN_2 5
#define TTP224_PIN_3 6
#define TTP224_PIN_4 7
#define SS_PIN 10
#define RST_PIN 9

Adafruit_SH1106 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1, -1);
MFRC522 rfid(SS_PIN, RST_PIN);

bool accessGranted = false;
bool isCelsius = true;
bool isLargeFont = true;
int brightnessThreshold = 200;
int buzzerState = LOW;

void setup() {
    Serial.begin(9600);
    Serial.println("Iniciando o sistema...");
    
    display.begin(SH1106_I2C_ADDRESS, -1);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(TTP224_PIN_1, INPUT);
    pinMode(TTP224_PIN_2, INPUT);
    pinMode(TTP224_PIN_3, INPUT);
    pinMode(TTP224_PIN_4, INPUT);
    
    SPI.begin();
    rfid.PCD_Init();
    
    display.clearDisplay();
    Serial.println("Sistema iniciado.");
}

void loop() {
    Serial.println("Loop executando...");
    checkRFID();
    
    if (accessGranted) {
        monitorEnvironment();
    }
}

void checkRFID() {
    if (!rfid.PICC_IsNewCardPresent()) {
        return;
    }

    if (!rfid.PICC_ReadCardSerial()) {
        return;
    }

    byte allowedUID[] = {0x66, 0x62, 0x25, 0xF8};

    bool isValidUID = true;
    for (int i = 0; i < 4; i++) {
        if (rfid.uid.uidByte[i] != allowedUID[i]) {
            isValidUID = false;
            break;
        }
    }

    if (isValidUID) {
        display.clearDisplay();
        display.setCursor(0, 0);
        display.print("Acesso Liberado");
        display.display();
        Serial.println("Acesso liberado.");
        delay(2000);
        accessGranted = true;
    } else {
        display.clearDisplay();
        display.setCursor(0, 0);
        display.print("Acesso Negado");
        display.display();
        Serial.println("Acesso negado.");
        delay(2000);
        accessGranted = false;
    }

    rfid.PICC_HaltA();
}

void monitorEnvironment() {
    float temperature = readLM35Temperature();
    int luminosity = analogRead(LDR_PIN);
    
    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.print(" | Luminosidade: ");
    Serial.println(luminosity);
    
    if (luminosity < brightnessThreshold) {
        buzzerState = !buzzerState;
        digitalWrite(BUZZER_PIN, buzzerState);
        display.clearDisplay();
        display.setTextSize(isLargeFont ? 2 : 1);
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.print("Temp: ");
        display.print(isCelsius ? temperature : (temperature + 273.15));
        display.print(isCelsius ? " C" : " K");
        display.display();
        delay(500);
    } else {
        digitalWrite(BUZZER_PIN, LOW);
        display.clearDisplay();
        display.setTextSize(isLargeFont ? 2 : 1);
        display.setCursor(0, 0);
        display.print("Temp: ");
        display.print(isCelsius ? temperature : (temperature + 273.15));
        display.print(isCelsius ? " C" : " K");
        display.display();
    }
    
    navigateSettings();
}

float readLM35Temperature() {
    int rawValue = analogRead(LM35_PIN);
    float voltage = (rawValue * 5.0) / 1024.0;
    return voltage * 100;
}

void navigateSettings() {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Clique 1: Config.");
    display.print("Clique 2: Retornar");
    display.display();

    if (digitalRead(TTP224_PIN_1) == HIGH) {
        settingsMenu();
    }
    if (digitalRead(TTP224_PIN_2) == HIGH) {
        accessGranted = false;
    }
}

void settingsMenu() {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Opção 1: Mudar Fonte");
    display.print("Opção 2: Mudar Unidade");
    display.display();

    if (digitalRead(TTP224_PIN_3) == HIGH) {
        isLargeFont = !isLargeFont;
        Serial.print("Fonte grande: ");
        Serial.println(isLargeFont ? "Ativada" : "Desativada");
        delay(500);
    }
    if (digitalRead(TTP224_PIN_4) == HIGH) {
        isCelsius = !isCelsius; 
        Serial.print("Unidade Celsius: ");
        Serial.println(isCelsius ? "Ativada" : "Desativada");
        delay(500);
    }
}
