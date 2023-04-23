int sensor = 7;  
 
void setup() { 
  Serial.begin (9600);  
  pinMode(sensor, INPUT); 
}

int estado; 
void loop() {
  estado = digitalRead(sensor); //0 o  1    
  Serial.println("Estado:" + String(estado)); 
  
  delay(100); 
}
