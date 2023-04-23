//Declaración de Variables
//byte int short<long float double
//boolean bool char String
//->>>  int float

int nombreVar;
int var2 = 5;

byte n;

void setup() {
  // put your setup code here, to run once:
 n = 0;
 Serial.begin(9600);  //Inicializar la comunicación serial a través del módulo UART
 //baudios
 
}

void loop() {
  // put your main code here, to run repeatedly:
 n++;
 Serial.println(n);
 delay(10); //detiene la ejecución del ciclo por el tiempo en milisegundos indicado como argumento.
}
