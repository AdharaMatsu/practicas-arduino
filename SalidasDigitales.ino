// Se realizan a través de la instrucción: digitalWrite
//Esta requiere de dos argumentos:  1: pin digital a operar  2: valor -> HIGH   LOW
int pin = 12;  //MEGA  [0 - 53], a excepción del 0 y 1 cuando se usa comunicación serial

void setup() {
  // put your setup code here, to run once:
 //Se requiere establecer el modo de trabajo del pin...
 pinMode(pin, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(pin, 1);  //HIGH    ... 5v    50mA 
 delay(1000);  //Detiene la ejecución del programa la cantidad en ms indicada como argumento
 digitalWrite(pin, 0); //LOW
 delay(1000);
 
}
