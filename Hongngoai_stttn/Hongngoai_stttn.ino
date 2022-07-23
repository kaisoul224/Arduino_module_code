int item;
int mathRandomInt(int min, int max) {
  if (min>max) {
    int temp = min;
    min= max;
    max = temp;
  }
  return min + (rand() % (max - min + 1)); 
}

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(12, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void setup() {
 pinMode(A0,INPUT);
 pinMode(A1,OUTPUT);
 pinMode(A2,OUTPUT);
 pinMode(13,OUTPUT);
 digitalWrite(A2,HIGH);
 digitalWrite(A1,LOW);
 Serial.begin(9600);
 mySoftwareSerial.begin(9600);
  if (!myDFPlayer.begin(mySoftwareSerial, true, false)) {  while(true){delay(0); }   }
  myDFPlayer.volume(30);
}

void loop() {
  
  Serial.print(analogRead(A0));
  delay(1000);
    
  if(analogRead(A0) < 250) {
    item = mathRandomInt(1,3);
    Serial.print(item);
    digitalWrite(13,HIGH); delay(10); 
    digitalWrite(13,LOW); 
    myDFPlayer.play(item); delay(6000);                                                                                                                                                                                                                                                                     
  }
  else
  digitalWrite(13,LOW);

}
