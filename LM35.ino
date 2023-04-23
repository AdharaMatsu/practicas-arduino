int LM35 = A0;

void setup() {
  Serial.begin(9600);
  
}

float valor;
void loop() {
  valor = analogRead(LM35);  // 0 - 1023

  valor = valor * 5.0 * 100.0 / 1023.0;
  //valor  = .48 * valor;

  Serial.println(String(valor) + "°C.");
  
  delay(250);
}
