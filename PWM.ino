int POT = A0;

int PWM = 11;

void setup() {
  Serial.begin(9600);
  
}

int valor;
void loop() {
  valor = analogRead(POT);  // 0 - 1023
  Serial.println(valor);

  valor = valor/4;
  
  analogWrite(PWM,valor);  // 0 - 255
  
  delay(250);
}

//TAREA 1.- INVESTIGAR PULL UP EN ELECTRONICA (FORMA DE CONECTAR PUSH BUTTONS)
