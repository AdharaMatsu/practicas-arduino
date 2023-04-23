int leds[3] = {11, 12, 13};
int i;

void setup() {
  for (i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
  }

  Serial.begin(9600);  //baudios
  Serial.setTimeout(100); //ms
}

int j;
String v;
void loop() {

  if (Serial.available() > 0) {//Comprueba si existe información en el buffer
    
    v = Serial.readString();
    //Realiza una lectura de todos los
    //caracteres que le sean posible hasta
    //terminar el tiempo indicado en
    //el parametro "timeout".
    //por defecto este dura 1seg.

    j = v.toInt();
    seleccion(j);
  }
  delay(100);
}

void seleccion(int j) {
  for (i = 0; i < 3; i++) {
    digitalWrite(leds[i], 0);
  }
  digitalWrite(leds[j], 1);
  delay(1000);
}
