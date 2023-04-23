#include <Servo.h>

Servo serv;

void setup() {
 
  serv.attach(12);
    
}


void loop() {

  //sg90 
  serv.write(0); 
  delay(1000);

  serv.write(180);
  delay(1000);
  
  
}
