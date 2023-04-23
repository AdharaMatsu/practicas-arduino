int pulsador = 7;
int led = 13;

void setup() {
  pinMode(pulsador, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  
  Serial.begin(9600);
}

int valor;
void loop() {
  valor = digitalRead(pulsador); //1 =  cuando no esta presionado   0 = presionado

//buscamos prender el led cuando se presiona... como lo realizamos? 
  digitalWrite(led, !valor);  
  
  
  Serial.println("Valor: " + String(valor));
  delay(100);
}
