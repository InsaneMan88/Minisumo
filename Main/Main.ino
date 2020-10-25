//DISPARADOR
//int GO = 14;

//QTR
//int Qtr1;
//int Qtr2;

//VALORES
int vve = 100;   // Velocidad de la vuelta (en rueda exterior)
int vvi = 100;
int vel_R = 150;   // Velocidad de ambos motores ()
int delayvuelta = (0);


//ULTRASONICOS
//1
int echo3 = 2;     // ***** YA SE CAMBIARON LOS PINES PLEBE *****
int trig3 = 3;

//2
int echo2 = 7;
int trig2 = 8;

//3
int echo1 = 11;
int trig1 = 12;

long duration1; // Tiempo que tarda la señal en regresar.(Valor medido por el sensor) 
int distance1; // Distancia ya calculada.

long duration2;
int distance2;

long duration3;
int distance3;


//MOTORES
int AIN_1 = 5;  //Motor A
int AIN_2 = 6;

int BIN_1 = 10; //Motor B
int BIN_2 = 9;

int MAXS = 250;  //PWM  <Valor máximo de los motores, Máxima velocidad>
int MINS = 0;    //PWM  <Valor mínimo de los motores, Motor detenido>


void setup() {                                     //ABRE SETUP
  
  //delay(5000);

//pinMode(GO,INPUT);

  //ULTRASONICOS
  pinMode (trig1, OUTPUT);
  pinMode (echo1, INPUT);

  pinMode (trig2, OUTPUT);
  pinMode (echo2, INPUT);

  pinMode (trig3, OUTPUT);
  pinMode (echo3, INPUT);

  //MOTORES
    pinMode(AIN_1, OUTPUT);
    pinMode(AIN_2, OUTPUT);

    pinMode(BIN_1, OUTPUT);
    pinMode(BIN_2, OUTPUT);
  
    Serial.begin(9600);
    
}                                                  //CIERRA SETUP


void loop() {                                      //ABRE LOOP

//if(digitalRead(GO)==HIGH)                          //ABRE CICLO GO
//{
/*
  //QTR
  Qtr1 = analogRead(A1);
  float voltage1 = Qtr1 * (5.0/1023.0);
  Serial.print(voltage1);
  Serial.println("");

  Qtr2 = analogRead(A2);
  float voltage2 = Qtr2 * (5.0/1023.0);
  Serial.print(voltage2);
  Serial.println("");
  */

 //ULTRASONICO 1
 digitalWrite(trig1, LOW);
 delayMicroseconds(2);
 
 digitalWrite(trig1,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig1,LOW);

 duration1 = pulseIn(echo1, HIGH);
 distance1 = duration1*0.0343/2;
 
 Serial.print(distance1);
 Serial.print("\t");


 //ULTRASONICO 2
 digitalWrite(trig2, LOW);
 delayMicroseconds(2);
 
 digitalWrite(trig2,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig2,LOW);

 duration2 = pulseIn(echo2, HIGH);
 distance2 = duration2*0.0343/2;

 Serial.print(distance2);
 Serial.print("\t");


 //ULTRASONICO 3
 digitalWrite(trig3, LOW);
 delayMicroseconds(2);
 
 digitalWrite(trig3,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig3,LOW);

 duration3 = pulseIn(echo3, HIGH);
 distance3 = duration3*0.0343/2;
 
 Serial.print(distance3);
 Serial.print("\t");
 Serial.print("\t");
 Serial.println("");


  //   <-----------------   CONTROL DE MOTORES


        analogWrite(AIN_1,0);
        analogWrite(AIN_2,0);

        analogWrite(BIN_1,0);
        analogWrite(BIN_2,0);

/*                                      //CONTROL DE MOTORES CON QTR
  //QTR (motores)
  if(voltage1 < 2.5)
        {  
        analogWrite(AIN_1,0);
        analogWrite(AIN_2,70);
        
        analogWrite(BIN_1,0);
        analogWrite(BIN_2,40);
        delay(500);
        }

if (voltage2 < 2.5)
        {
        analogWrite(AIN_1,0);
        analogWrite(AIN_2,40);
        
        analogWrite(BIN_1,0);
        analogWrite(BIN_2,70);
        delay(500);
        }
 */
 
 //ULTRASONICOS (motores)
     if (distance3 < 50)
    {
        analogWrite(AIN_1,vve);
        analogWrite(AIN_2,0);   //kk i

        analogWrite(BIN_1, vve);
        analogWrite(BIN_2, 0);

        //delay(delayvuelta);
      }

    
     if (distance1 < 50)
    {
       
        analogWrite(AIN_1,0);
        analogWrite(AIN_2,vve);
        
        analogWrite(BIN_1,0);
        analogWrite(BIN_2,vve);

        //delay(delayvuelta);
      }

      
      if (distance2 <50)
     {  
        analogWrite(AIN_1,0);
        analogWrite(AIN_2,vel_R);

        analogWrite(BIN_1,vel_R);
        analogWrite(BIN_2,0); 
       }


//}                                 //CIERRA DISPARADOR
/*
else {
        analogWrite(AIN_1,0);
        analogWrite(AIN_2,0);
        analogWrite(BIN_1,0);
        analogWrite(BIN_2,0);
        }

*/
}                                                  //CIERRA LOOP
