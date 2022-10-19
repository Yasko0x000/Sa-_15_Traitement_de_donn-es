#include <Arduino.h>

class  UltraSonic  {
  private :
  const  int  echo = A4;  //  port  for  reading
  const  int  trig = A5;  //  port  for  writing
  
  public :

  UltraSonic ()  {
  pinMode ( echo , INPUT) ;
  pinMode ( trig , OUTPUT) ;
  }

  float  getDist ()  {
    digitalWrite ( trig , LOW) ;
    delayMicroseconds (2) ;
    digitalWrite ( trig , HIGH) ;
    delayMicroseconds (20) ;
    digitalWrite ( trig , LOW) ;
    float  d = pulseIn ( echo , HIGH);
    d/=5.8f;
    return d ;
  }
};
