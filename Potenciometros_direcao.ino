int potX = A0;
int potY = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int valorX = analogRead(potX);
  int valorY = analogRead(potY);
  
  int limiarX = 512;
  int limiarY = 512;

  Serial.print("Eixo X: ");
  Serial.print(valorX);
  Serial.print("  ");
  Serial.print("Eixo Y: ");
  Serial.println(valorY);

  if(valorX > limiarX){
    Serial.print("Para direita  ");
  } else if (valorX < limiarX){
    Serial.print("Para esquerda  ");
  }

  if(valorY > limiarY){
    Serial.print("Para baixo  ");
  } else if (valorY < limiarY){
    Serial.print("Para cima  ");
  }

  delay(500);
}
