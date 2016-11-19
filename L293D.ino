/*Open Hardware Algerie

Sujet : commande de deux MCC a l'aide d'un Hacheur de H-Bridge L293D

Deceloppeur: Aidi Nour el Islem (OHA)

Ce code source est sous licence Gpl v2

Outils nécessaire : - une carte arduino
                    - deux moteurs a courant continu
                    - un L293D (H-Bridge)
                    - une allimentation de 9v ( ou batterie)
                    - une breadboard
                    - quelques jumper wirers
                    
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

// Code :

// Pin affecter au Moteur 1

int motor1_pwm = 5 ;
int motor1_nord = 2 ;
int motor1_sud = 4 ;

// pin affecter au Moteur 2

int motor2_pwm = 6 ;
int motor2_nord = 7 ;
int motor2_sud = 8 ;

void setup(){
  
  // configuration des pins de l'arduino en mode input ou output

  pinMode(motor1_pwm, OUTPUT);
  pinMode(motor1_nord, OUTPUT);
  pinMode(motor1_sud, OUTPUT);
  
  pinMode(motor2_pwm, OUTPUT);
  pinMode(motor2_nord, OUTPUT);
  pinMode(motor2_sud, OUTPUT);
  

}

void loop(){
  
  //rotation des 2 moteurs dans le même sense et attente de 2 secondes
  
  motor1_control(155, false);
  motor2_control(155,false);
  delay(2000);
  
  //arrêt des 2 moteurs durant 2 secondes
  
  motor1_control(0, false);
  motor2_control(0,false);
  delay(2000);
  
  //inverssion
  
  motor1_control(155, true);
  motor2_control(155,true);
  delay(2000);
  
  //arrêt
  
  motor1_control(0, false);
  motor2_control(0,false);
  delay(2000);
  
  // rotation des deux moteurs dans des senses inverse
  
  motor1_control(155, false);
  motor2_control(155, true);
  delay(2000);
  
  // arrêt
  
  motor1_control(0, false);
  motor2_control(0,false);
  delay(2000);
  
  //inverssion 
  
  motor1_control(155, true);
  motor2_control(155,false);
  delay(2000);
  
  // arrêt
  
  motor1_control(0, false);
  motor2_control(0,false);
  delay(2000);


}

//Fonction de control moteur 1


void motor1_control(int speed, boolean reverse){

  digitalWrite(motor1_nord, reverse);
  digitalWrite(motor1_sud, !reverse);
  analogWrite(motor1_pwm, speed);
  
}

//fonction de control moteur 2

void motor2_control(int speed, boolean reverse){

  digitalWrite(motor2_nord, reverse);
  digitalWrite(motor2_sud, !reverse);
  analogWrite(motor2_pwm, speed);
  
}


