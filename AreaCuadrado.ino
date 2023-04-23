enum ESTADOS {
  PEDIR_LADO,
  ESPERAR_LADO,
  CALCULAR_AREA,
  IMPRIMIR_AREA,
  REINICIAR
};

int estado;

int lado;
String temporal;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(250);
  estado = 0;
}


void loop() {

  switch (estado) {
    case PEDIR_LADO:
      Serial.println("Dame el lado");
      estado++;
      break;
    case ESPERAR_LADO:
      if(Serial.available()>0){
        temporal = Serial.readString();
        lado = temporal.toInt();
        estado++;
        }
      break;
    case CALCULAR_AREA:
      lado = lado * lado;
      estado++;
      break;
    case IMPRIMIR_AREA:
      Serial.println("El área es: " + String(lado));
      estado++;
      break;
    case REINICIAR:
      estado = 0;
      break;
  }

  //Serial.println("Se repite la revisión de la máquina");

  delay(100);

}
