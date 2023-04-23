//PROYECTO 1 UNIDAD 1
/*
 * CONSISTIRÁ EN LA CREACIÓN DE UNA MATRIZ DE TRANSICIÓN DE ESTADOS PARA N ESTADOS.
 * 
 * DONDE N SEA MAYOR O IGUAL A 3.
 * 
 * SE DEBERÁ AJUSTAR EL PROGRAMA PARA: 
 *        CALCULAR EL Px DESEADO POR EL USUARIO...
 *        
 *        A ESE Px se le APLICARÁ "RULETA" PARA LA SELECCIÓN DE UN ESTADO
 *        
 *        EL USUARIO VISUALIZARÁ LA SELECCIÓN CON BASE EN EL ACCIONADO DE UN LED.
 *        
 *        
 * LA ENTREGA REQUIERE SE REALICE DOCUMENTACIÓN QUE JUSTIFIQUE EL ACOMODO DE LA MATRIZ DE TRANSICIÓN, ASÍ, COMO
 *  DE TODO EL PROGRAMA PARA DAR UNA SOLUCIÓN AL PROBLEMA A TRATAR.
 *  
 *  AÑADIR CAPTURAS DE PANTALLA, EXPLICACIÓN CON IMAGENES SI ES POSIBLE Y FRAGMENTOS DEL CÓDIGO 
 *  
 *  
 *  ADEMÁS DE LA DOCUMENTACIÓN SE ENTREGARÁ EL CÓDIGO FUENTE COMPLETO UTILIZADO. 
 */

float T[3][3] = {{0.2, 0.4, 0.4},
                 {0.1, 0.6, 0.3},
                 {0.4, 0.5, 0.1}
};

float P0[1][3] = {
  {0.3, 0.6, 0.1}
};

int i, j, k;


int led_estado1 = 10;
int led_estado2 = 11;
int led_estado3 = 12;

enum estado {
  ESTADO_1, //0
  ESTADO_2, //1
  ESTADO_3  //2
};

int estado_sel;
float u;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(250);

  pinMode(led_estado1, OUTPUT);
  pinMode(led_estado2, OUTPUT);
  pinMode(led_estado3, OUTPUT);
}


String s;
void loop() {
  if (Serial.available() > 0) {
    s = Serial.readString();
    mult();

    //Tarea.. Investigar caracteres de escape  en Arduino
    //  Serial.println(sizeof(T)/4);
    //  Serial.println(sizeof(T[0])/4);


    /*
      Serial.println();
      for (i = 0; i < (sizeof(T)/4) / (sizeof(T[0])/4); i++) {
        for (j = 0; j < sizeof(T[0])/4; j++) {
            //Serial.print( String(T[i][j]) +  '\t');
            //Serial.print( String(T[i][j]) +  '\x009');
            Serial.print( String(T[i][j]) + "   ");

          }
          Serial.println();
      }

    */

    //Programa: Adaptar el código para conseguir el Px que nos pida el usuario  <<-----


    digitalWrite(led_estado1, 0);
    digitalWrite(led_estado2, 0);
    digitalWrite(led_estado3, 0);

    switch (estado_sel) {
      case ESTADO_1:
        digitalWrite(led_estado1, 1);
        break;
      case ESTADO_2:
        digitalWrite(led_estado2, 1);
        break;
      case ESTADO_3:
        digitalWrite(led_estado3, 1);
        break;
    }

  }


}


//             3x3          1x3
void mult() {
  float C[1][3];
  for (i = 0; i < (sizeof(T) / 4) / (sizeof(T[0]) / 4); i++) {
    for (j = 0; j < sizeof(P0[0]) / 4; j++) {
      for (k = 0; k < (sizeof(T) / 4) / (sizeof(T[0]) / 4); k++) {
        // aquí se multiplica la matriz
        C[i][j] += T[i][k] * P0[k][j];
      }
    }
  }


  Serial.println();
  for (i = 0; i < (sizeof(C) / 4) / (sizeof(C[0]) / 4); i++) {
    for (j = 0; j < sizeof(C[0]) / 4; j++) {
      Serial.print( String(C[i][j]) + "   ");
    }
    Serial.println();
  }

  ///////////////////////////////////
  //SELECCION DEL ESTADO:
  u = random(0, 100)/100.0;
  Serial.println("u:");
  Serial.println(u);
  Serial.println();

  for (i = 0; i < (sizeof(C) / 4) / (sizeof(C[0]) / 4); i++) {
    for (j = 0; j < sizeof(C[0]) / 4; j++) {
      u -= C[i][j];
      if (u<=0){
          estado_sel = j;
          break;
        }
    }
  }
  //////////////////////////////////

}


//EJERCIO: HACER UN MÉTODO PARA LA MULTIPLICACIÓN DE MATRICES


//TARES: INVESTIGAR LA FORMA DE TRABAJAR CON ARREGLOS Y MATRICES EN ARDUINO
