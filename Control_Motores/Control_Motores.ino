//Declaraciones de los pines de los motores
int AIN_1 = 5;  //Motor A
int AIN_2 = 6;

int BIN_1 = 10; //Motor B
int BIN_2 = 9;

//Pulsos para controlar la velocidad de los Motores
 //MAXS = 250;  //PWM  <Valor máximo de los motores, Máxima velocidad>
 //MINS = 0;    //PWM  <Valor mínimo de los motores, Motor detenido>
void setup() {
  // put your setup code here, to run once:
 //Declaracion de los pines como salidas
    pinMode(AIN_1, OUTPUT);
    pinMode(AIN_2, OUTPUT);

    pinMode(BIN_1, OUTPUT);
    pinMode(BIN_2, OUTPUT);
  
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
        //Señal de salida hacia motores
        analogWrite(AIN_1,0);
        analogWrite(AIN_2,0);

        analogWrite(BIN_1,0);
        analogWrite(BIN_2,0);
}
