enum maquina{
  estado1,
  estado2,
  estado3
  };
int estado;


int led1 = 10;
int led2 = 11;
int led3 = 12;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  estado = 0;
}


void loop() {

  digitalWrite(led1, 0);
  digitalWrite(led2, 0);
  digitalWrite(led3, 0);
  
  switch(estado){
    case estado1:
    digitalWrite(led1, 1);
    break;
    case estado2:
    digitalWrite(led2, 1);
    break;
    case estado3:
    digitalWrite(led3, 1);
    break;
    }

    estado += 1;
    estado = estado%3;

    delay(250);
}
