int leds[3] = {11, 12, 13};
int i;

void setup() {
  for (i = 0; i<3; i++){
     pinMode(leds[i],OUTPUT);
    }
}

int j = 0;
void loop() {
  seleccion(j);
  j++;
  j = j%3;
}

void seleccion(int j){
    for (i = 0; i<3; i++){
     digitalWrite(leds[i],0);
    }
    digitalWrite(leds[j],1);
    delay(1000);
  }
