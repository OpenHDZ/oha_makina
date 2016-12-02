/*Open Hardware Algerie

Sujet : Realisation d'un robot detecteur d'obstacles

Designer: Aidi Nour el Islem (OHA)

ce code source est sous licence Gpl v2

outils nécessaire : - une carte arduino
                    - deux moteurs a courant continu
                    - un L293D (H-Bridge)
                    - un module ultrasonic HC-SR04
                    - une allimentation de 9v ( ou batterie)
                    - une breadboard
                    - quelques jumper wirers
                    

Mapping des connectics HC-SR04 --> Arduino 

 _____________ ___________ 
|    HC-SR04  |  Arduino  | 
--------------------------
|     VCC     |   5v      |
|     GND     |   GND     |
|     Tring   |   10      |
|     Echo    |   9       |
 -------------------------

Mapping des connectics L293D --> Arduino et L293D --> Power suply (9v) et L293D --> Dc Motors

Remarque!: le GND de la batterie doit être relier au GND de l'arduino pour que tout le circuit soit sur le même référentiel
 _____________ ___________ ____________ _____________ _____________
|    L293D    |  Arduino  |  Power 9V  | DC Motors 1 | DC Motors 2 |
-------------------------------------------------------------------
|     1       |   5(PWM)  |    //      |    //       |    //       |
|     2       |   2       |    //      |    //       |    //       |
|     3       |   //      |    //      |    (+)      |    //       |
|     4       |   GND     |    GND     |    //       |    //       |
|     5       |   GND     |    GND     |    //       |    //       |
|     6       |   //      |    //      |    (-)      |    //       |
|     7       |   4       |    //      |    //       |    //       |
|     8       |   //      |    (+)     |    //       |    //       |
|     9       |   6(PWM)  |    //      |    //       |    //       |
|     10      |   7       |    //      |    //       |    //       |
|     11      |   //      |    //      |    //       |    (-)      |
|     12      |   GND     |    GND     |    //       |    //       |
|     13      |   GND     |    GND     |    //       |    //       |
|     14      |   //      |    //      |    //       |    (+)      |
|     15      |   8       |    //      |    //       |    //       |
|     16      |   5V      |    //      |    //       |    //       |
--------------------------------------------------------------------


*/

//code:

//Moteur 1

int motor1_pwm = 5 ;
int motor1_nord = 2 ;
int motor1_sud = 4 ;

// Moteur 2

int motor2_pwm = 6 ;
int motor2_nord = 7 ;
int motor2_sud = 8 ;

// Vitesse des moteurs

int vit=230;

int dist;

//Partie Capteur Ultrasonic SR-04

#define echoPin 9 // Echo Pin
#define trigPin 10 // Trigger Pin

int maxDist = 100; // Limite maxi de mesure
int minDist = 5; // Limite Mini de mesure
long temps, distance; // Temps necessaire pour calculer la distance ; distance


void setup(){
  
// Moteur

  pinMode(motor1_pwm, OUTPUT);
  pinMode(motor1_nord, OUTPUT);
  pinMode(motor1_sud, OUTPUT);
  
  pinMode(motor2_pwm, OUTPUT);
  pinMode(motor2_nord, OUTPUT);
  pinMode(motor2_sud, OUTPUT);
  
//CapteurUltrasonic
  
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);

}

void loop(){
  
 dist= sonic();
 control(dist);
  


}

int sonic(){
  
  digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(2); 
 
 digitalWrite(trigPin, LOW);
 temps = pulseIn(echoPin, HIGH);
 
 
 distance = temps/58.2;
 
 return distance;

}

void motor1_control(int speed, boolean reverse){

  digitalWrite(motor1_nord, !reverse);
  digitalWrite(motor1_sud, reverse);
  analogWrite(motor1_pwm, speed);
  
}

void motor2_control(int speed, boolean reverse){

  digitalWrite(motor2_nord, !reverse);
  digitalWrite(motor2_sud, reverse);
  analogWrite(motor2_pwm, speed);
  
}
void control(int dist){
  
  if (dist >= 10) {
    
  motor1_control(vit*0.978, true);
  motor2_control(vit,true);
  
  } 
  
  else {
  
  motor1_control(0, true);
  motor2_control(0,true);
  delay(500);
  
  motor1_control(vit, false);
  motor2_control(vit,false);
  delay(1000);
  
  motor1_control(vit, false);
  motor2_control(0,false);
  delay(2000);
  
  
  
  
  
  }

}
