enum ESTADOS {
PEDIR_ANIO,
ESPERAR_ANIO,
CALCULAR,
IMPRIMIR,
REINICIAR
};

int estado;
int num;
bool bis = false;
String temporal;

void setup() {
Serial.begin(9600);
Serial.setTimeout(250);
estado = 0;
}

void loop() {

 switch (estado) {
case PEDIR_ANIO:
Serial.println("Anio Bisiesto");
Serial.println("Dame el Anio");
estado++;
break;
case ESPERAR_ANIO:
if(Serial.available()>0){
temporal = Serial.readString();
num = temporal.toInt();
delay(500);
estado++;
}
break;
case CALCULAR:
if(num%400==0){
  bis=true;
  }
else if(num%100==0){
  bis=false;
  }
else if(num%4==0){
  bis=true;
  }
else{ bis = false;}
estado++;
break;
case IMPRIMIR:
if(bis==true){
Serial.println("");
Serial.println("El año " + String(num) + " es bisiesto");}
else{
Serial.println("");
Serial.println("El año " + String(num) + " no es bisiesto");}
estado++;
break;
case REINICIAR:
Serial.println("");
estado = 0;
break;
}
 //Serial.println("Se repite la revisión de la máquina");
 delay(100);
}
