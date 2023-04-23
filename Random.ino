float numero_rnd;


void setup() {
  Serial.begin(9600);
  Serial.setTimeout(250);

  //randomSeed(5);

  randomSeed(analogRead(A0));
  
}


String s;
int i;
void loop() {
  if(Serial.available()>0){
      s = Serial.readString();    

      for(i = 0; i<10; i++){
          //numero_rnd = random(n);  //  [0 - n]

          // numero_rnd = random(1, 11); // [n - m] 
          // Serial.println(numero_rnd);          

           numero_rnd = random(1, 101)/100.0; // [n - m] 
           Serial.println(numero_rnd);          
        }
      Serial.println();
    }

//PROGRAMA: piedra , papel , tijera de la pc con el usuario. 

}
