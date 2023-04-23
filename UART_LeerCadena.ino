int leds[3] = {11, 12, 13};
//          Alejandro    Luis     Martin
int i;

void setup() {
  for (i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
  }

  Serial.begin(9600);  //baudios
  Serial.setTimeout(1000); //ms
}

String v;
//enum nombres {Alejandro, Luis, Martin};

void loop() {

  if (Serial.available() > 0) {//Comprueba si existe información en el buffer

    v = Serial.readString();

    //nombres temp = v;

    switch (v.charAt(0)) {
      case 'A':
        seleccion(0);
        break;
      case 'L':
        seleccion(1);
        break;
      case 'M':
        //default:
        seleccion(2);
        break;
    }


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
