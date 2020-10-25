//Sensores Ultrasonicos

//Declaracion de los pines para Echo y Trigger
int echo = 2;     
int trig = 3;

long duracion; //Tiempo que tarda la señal en regresar.
int distancia; //Distancia ya Calculada
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
  
//Declaracion de Entradas y Salidas
pinMode(trig, OUTPUT); //Se declara la variable "trig" como señal de salida
pinMode(echo, INPUT); //Se declara la variable "echo" como señal de entrada
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(trig, LOW); //Se asegura que la señal este en LOW
 delayMicroseconds(2); //Tiempo de espera
 
 digitalWrite(trig,HIGH); //Se manda la señal de salida en trig
 delayMicroseconds(10); //Tiempo de espera en Microsegundos
 digitalWrite(trig,LOW); //Se deja de mandar señal de salida en trig

//Durante determinado tiempo se espera lectura de entrada
 duracion = pulseIn(echo, HIGH); //Se almacena la señal de entrada en "duracion" 
 distancia = duracion*0.0343/2; //Se realiza el calculo para determinar la distancia y se almacena en "distancia"
 
 Serial.print(distancia); //Se imprime el valor medido. 
 Serial.print("\t");
}
