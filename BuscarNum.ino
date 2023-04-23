int arreglo[100];
int j;
int i;
int pc;

void setup() {

  randomSeed(analogRead(A0));

  for (j = 0; j < 100; j++) {
    arreglo[j] = random(1001);
  }

  //la computadora escogera un número
  pc = arreglo[random(100)];  //

  Serial.begin(9600);
  Serial.setTimeout(250);
}

int vidas = 5;
int numUsu = -1;

enum ESTADOS {
  PEDIR,
  ADIVINAR,
  COMPROBAR
};

int estado = 0;

void loop() {
  switch (estado) {
    case PEDIR:
      Serial.println("Ingresa el número que crees que es de la computadora?");
      burbuja();
      //DESPLEGAR AYUDA
      break;
    case ADIVINAR:
      if(Serial.available()>0){
        numUsu = Serial.readString().toInt();
        }
      break;
    case COMPROBAR:
    if (numUsu == pc){
      //GANO EL JUGADOR
      }
      else {
        vidas--; 
        //COMPROBAR SI AUN QUEDAN VIDAs
        }
      break;


      //swAP
  }
}


void burbuja() {
  int aux;
  for (i = 0; i < 100; i++) {
    for (j = i + 1; j < 100; j++) {
      if (arreglo[i] < arreglo[j]) { //
        //swap
        aux = arreglo[i];
        arreglo[i] = arreglo[j];
        arreglo[j] = aux;
      }
    }
  }
}
