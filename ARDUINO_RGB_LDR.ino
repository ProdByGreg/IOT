int ldr = 0;
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);}
void loop() {
  ldr = analogRead(A0);
  Serial.print("LDR: ");
  Serial.println(ldr);
  if (ldr < 310){
  analogWrite(3, 255);
  analogWrite(4, 0);
  analogWrite(5, 0);
  Serial.println("Vermelho");
  delay(100);
  analogWrite(3, 0);
  analogWrite(4, 255);
  analogWrite(5, 0);
  Serial.println("Azul");
  delay(100);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, 255);
  Serial.println("Verde");
  delay(100);
  analogWrite(3, 100);
  analogWrite(4, 150);
  analogWrite(5, 50);
  Serial.println("Lilas");
  delay(100);
  analogWrite(3, 0);
  analogWrite(4, 250);
  analogWrite(5, 150);
  Serial.println("Marinho");
  delay(100);
  analogWrite(3, 100);
  analogWrite(4, 50);
  analogWrite(5, 200);
  Serial.println("Esverdeado");
  delay(100);
}else
  analogWrite(3, 255);
  analogWrite(4, 255);
  analogWrite(5, 255);
  Serial.println("Branco");
  delay(100);}
