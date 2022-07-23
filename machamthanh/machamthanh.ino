// am thanh
#define chanphat 8
#define chanthu 7
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(11, 12); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
int thoigian,khoangcach;
void setup(){
  Serial.begin(9600);
  pinMode(chanphat, OUTPUT);
  pinMode(chanthu, INPUT);
  mySoftwareSerial.begin(9600);
  if (!myDFPlayer.begin(mySoftwareSerial, true, false)) {  while(true){delay(0); }   }
  myDFPlayer.volume(30);
}
void loop(){
  
digitalWrite(chanphat,HIGH);
delayMicroseconds(1000);
digitalWrite(chanphat,LOW);
thoigian=pulseIn(chanthu,HIGH);
khoangcach=0.0344*(thoigian/2);
Serial.print(khoangcach);
Serial.println("cm");
if(khoangcach<20)
{ 
   myDFPlayer.play(1); delay(4000); //delay(500);
   //myDFPlayer.play(2); delay(4000); delay(500);
   //myDFPlayer.play(3); delay(4000);   
}                                                                                                                                                                                                                                                                       
delay(500);
}
