void setup(){
  Serial.begin(9600);}
void loop(){
  for(int digitalInput=0; digitalInput<255; digitalInput++){
  Serial.print("Digital input:");
  Serial.println(digitalInput);
  analogWrite(11, digitalInput);
  analogWrite(9, digitalInput);
  analogWrite(6, digitalInput);}}