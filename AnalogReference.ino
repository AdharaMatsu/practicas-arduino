int POT = A0;

void setup() {
  Serial.begin(9600);
  
  analogReference(EXTERNAL);
}

int valor;
void loop() {
  valor = analogRead(POT);
  Serial.println(valor);

  delay(250);
}
