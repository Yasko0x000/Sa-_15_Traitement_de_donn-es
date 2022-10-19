#include <Arduino.h>

#define ABS 115
class Engine{
  private:
  //définit les pin de controle
    int in1=6;
    int in2=7;
    int in3=8;
    int in4=9;
    
  //définit les pin d'output
  int ENA=5;
  int ENB=11;

  //définit la vitesse
  int velocity;
  
  public: //cette partie va définir les mouvements
    Engine(int s){
      velocity=195;
      pinMode(in1, OUTPUT);
      pinMode(in2, OUTPUT);
      pinMode(in3, OUTPUT);
      pinMode(in4, OUTPUT);
      pinMode(ENA, OUTPUT);
      pinMode(ENB, OUTPUT);
    }
    void back(){
      analogWrite(ENA, velocity);
      analogWrite(ENB, velocity);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      //Serial.println("Le robot recule...");
    }
     void right(){
      analogWrite(ENA, 0);
      analogWrite(ENB, velocity);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      //Serial.println("Le robot tourne a droit...");
    }
    void stop(){
      digitalWrite(ENA, LOW);
      digitalWrite(ENB, LOW);
      //Serial.println("arret.");
    }

    void left(){
      analogWrite(ENA, velocity);
      analogWrite(ENB, 0);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      //Serial.println("Le robot a gauche ...");
    }

    void go(){
      analogWrite(ENA, velocity);
      analogWrite(ENB, velocity);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      //Serial.println("Le robot avance...");
    }

   void pivR(){
      analogWrite(ENA, velocity);
      analogWrite(ENB, velocity);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      
    }

  void pivL(){
      analogWrite(ENA, velocity);
      analogWrite(ENB, velocity);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      
    }





};
