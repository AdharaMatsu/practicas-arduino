int POT = A0; //[0 1023]

String temp;

int arreglo[10];
int i;
int j;

int contador;

void setup() {
  Serial.begin(9600); //Inicializar el módulo de comunicación serial (UART)

  Serial.setTimeout(250); //

  i = 0;
  contador = 0;
}



float p;
int num_lecturas = 10;

void loop() {

  arreglo[i++] = analogRead(POT); //retorna el valor leido desde el pin analogico enviado como argumento
  i = i % num_lecturas;

  if (contador < num_lecturas) {
    contador++;
  }

  if (Serial.available() > 0) {
    temp = Serial.readString();

    if (temp == "A") {
      p = 0;
      for (j = 0; j < contador; j++) {
        p += arreglo[j];
      }
      p /= contador;

      Serial.println("Promedio: " + String(p));
    }
  }

delay(100);

}
