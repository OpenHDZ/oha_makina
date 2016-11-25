/*Open Hardware Algerie

Sujet : acquisition de l’information distance a l’aide d’un HC-SR04

Designer: Aidi Nour el Islem (OHA)

ce code source est sous licence Gpl v2

outils nécessaire : - une carte arduino
                             - un module ultrasonic HC-SR04
                             - une breadboard
                             - quelques jumper wirers
                    
Mapping des connectics HC-SR04 --> Arduino 

Remarque!: l’utilisation de l’écran LCD est optionnel sur ce fichier le code source est éditer pou un affichage par la liaison série de votre arduino
 _____________ ___________ 
|    HC-SR04  |  Arduino  | 
--------------------------
|     VCC     |   5v      |
|     GND     |   GND     |
|     Tring   |   8       |
|     Echo    |   7       |
 -------------------------
*/

// Code :

#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin

int maxDist = 100; // Limite maxi de mesure
int minDist = 5; // Limite Mini de mesure
long temps, distance; // Temps necessaire pour calculer la distance ; distance




void setup(){
 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 
 Serial.begin(9600);
  
  
  
}

void loop() {
 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(2); 
 
 digitalWrite(trigPin, LOW);
 temps = pulseIn(echoPin, HIGH);
 
 
 distance = temps/58.2;
 
 lcd.setCursor(11, 3);
 
 
 if (distance >= maxDist || distance <= minDist){
 
 Serial.print("-1");
 
 }
 
   
   else{
 Serial.print(distance);
   }
 
 }
 
 delay(400);
 
 
 
}


