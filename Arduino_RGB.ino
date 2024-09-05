void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);}

void loop() {
  analogWrite(3, 200);
  analogWrite(4, 0);
  analogWrite(5, 0);
  Serial.println("Vermelho");
  delay(500);
  analogWrite(3, 0);
  analogWrite(4, 200);
  analogWrite(5, 0);
  Serial.println("Azul");
  delay(500);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, 200);
  Serial.println("Verde");
  delay(500);}
