int LDR = A0;

void setup() {
    Serial.begin(9600);
}

int valor;
void loop() {
  valor = analogRead(LDR);
  Serial.println(valor);

  delay(1000);
}
