#include <Arduino.h>
#include "Engine.h"               // Inclure le code pour les moteurs
  Engine motorino(185);

#include "ultrasonic.h"           // Inclure le code pour les capteurs
  UltraSonic ultraSonic;
  float Dist = ultraSonic.getDist();
  int dist_right=0;
  int dist_left=0;
  int dist_devant=0;
  int dist_uno=0;
  int dist_due=0;
  int state =0;                   // Utile pour afficher les états pendant les test

#include <Servo.h>                // Inclusion de la librairie Servo
  Servo myservo;                  // J'ai déclarer la variable de typer Servo

void setup()                      // Fonction exécutée à l'initialisation de la carte
{
  Serial.begin(9600);             // Définir la vitesse de communication
  myservo.attach(3);              // La variable est donc ataché au pin 3
  myservo.write(0);               // Placement du Servo
  dist_uno = ultraSonic.getDist();// 2éme parcours, faire demi tour
  delay(650);                     // Durée de fonctionnement
  motorino.pivR();                // Tourner à droite
  delay(980);
  motorino.stop();                // S'arretter
 
}

void loop()                       // Fonction exécutée en boucle infinie
{
  Dist = ultraSonic.getDist();    // Lecture de distance
   Serial.println(Dist);          // Afficher sur le moniteur Serie (utile pour les test)

   myservo.write(65);             // Placement du Servo à 65
    delay(150);
   dist_devant = Dist;

   if (dist_devant<=350)          // Si la distance est inferieur ou égale à 350 (donné grace au capteur)
   {
    motorino.back();              // J'ai mis un leger retour pour bien frener le robot, le stop étais pas suffisant et baisser la puissance etais pas une solution envisageable
    delay(100);
    motorino.stop();              // S'arretter
      delay(100);
    myservo.write(-45);           // Placement du Servo à -45
      delay(500);
    dist_right = ultraSonic.getDist();  // Récuperer les donné du capteur
        Serial.print("Right-Dist = ");  // Afficher sur le moniteur Serie (utile pour les test)
        Serial.println(dist_right);     // Afficher sur le moniteur Serie en unité (utile pour les test)
      delay(500);

   myservo.write(60);             // Placement du Servo à -60
      delay(500);
    dist_devant = ultraSonic.getDist(); // Récuperer les donné du capteur
        Serial.print("Devant-Dist = "); // Afficher sur le moniteur Serie (utile pour les test)
        Serial.println(dist_devant);    // Afficher sur le moniteur Serie en unité (utile pour les test)
      delay(500);
      
    myservo.write(140);           // Placement du Servo à -60
      delay(500); 
    dist_left = ultraSonic.getDist();   // Récuperer les donné du capteur
        Serial.print("lDist=");
        Serial.println(dist_left);
      delay(500);
        state=1;                  // Les états indiquent les partie de programmation
        Serial.println(state);
        myservo.write(60);
      delay(100); 
        

   }

        {
           motorino.go();         
           state=5;               // Faire avancer et afficher le 5éme état, utile seulement pour les test
           Serial.println(state);

         }
   
   if (dist_right>dist_left)              // Si la distance de droite est supérieur à la distance de gauche, alors tourner à droite
   {
    motorino.pivR();
    delay(350);
    state=2;                              // Afficher le 2éme état, c'est-à-dire tourner à droite
    dist_right=0;
    dist_left=0;
    Serial.println(state);   //test validé
   }
      else (dist_right<dist_left);         // Sinon tourner à gauche
          {
           motorino.pivL();
           delay(400);
           state=3;                        // Afficher le 3éme état, c'est-à-dire tourner à gauche
           dist_right=0;
           dist_left=0;
           Serial.println(state);  //test validé

         }
            
}
