int butonstate = 0;
void setup(){
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
pinMode(10, INPUT);
}
void loop(){
butonstate = digitalRead(10);
  if (butonstate == HIGH){
    
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
delay(15000);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
delay(0);

digitalWrite(6, HIGH);
delay(3000);
digitalWrite(6, LOW);
delay(0);

int contador = 0;
digitalWrite(5, HIGH);
digitalWrite(9, HIGH);
delay(20000);
while(contador<=5){
digitalWrite(9, LOW);
digitalWrite(8, HIGH);
delay(500);
digitalWrite(8, LOW);
delay(500);
contador++;}
    
digitalWrite(5, LOW);
delay(0);
} else {
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
delay(1000);
}}