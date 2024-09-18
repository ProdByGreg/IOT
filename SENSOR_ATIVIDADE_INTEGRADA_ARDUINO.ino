const int buzzer = 3;
const int button = 4;
const int Red = 10;
const int Green = 11;
const int Yellow = 12;
int cm = 0;
bool alarme = false;

long readUltrasonicDistance(int trigger, int echo){
  
    pinMode(trigger, OUTPUT);    digitalWrite(trigger, LOW);
    	delayMicroseconds(2);

    digitalWrite(trigger, HIGH);
    	delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    pinMode(echo, INPUT);

    return pulseIn(echo, HIGH) * 0.01723;}

	float leitortemperatura(){
    int sensor = analogRead(A0);
    float voltage = sensor * (5.0 / 1023.0);
    float temperatura = voltage * 100;
      
    return temperatura;}

void setup(){
  
    Serial.begin(9600);
  
    pinMode(Red, OUTPUT);
    pinMode(Yellow, OUTPUT);
    pinMode(Green, OUTPUT);
    pinMode(button, INPUT);

    digitalWrite(Red, LOW);
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, LOW);
    digitalWrite(buzzer, LOW);}

void loop(){
    cm = readUltrasonicDistance(5, 7);
    float temperatura = leitortemperatura();

    Serial.print("Distância: ");
    Serial.print(cm);
    Serial.print(" cm, Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");

    if (digitalRead(button) == LOW) {
      
        alarme = false;
      
        	digitalWrite(buzzer, LOW);
        	digitalWrite(Red, LOW);
        	digitalWrite(Yellow, LOW);
        	digitalWrite(Green, LOW);}

    if (cm < 20 && !alarme){
      
        alarme = true;

        	digitalWrite(Red, HIGH);
        	digitalWrite(Yellow, HIGH);
        	digitalWrite(Green, HIGH);
      
        		tone(buzzer, 440, 250);

        	delay(300);

        digitalWrite(Red, LOW);
        digitalWrite(Yellow, LOW);
        digitalWrite(Green, LOW);
  
      		delay(100);}}
