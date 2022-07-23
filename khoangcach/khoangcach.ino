
#define chanphat 8 //trig
#define chanthu 7 //echo
int say=9;
int thoigian,khoangcach;
void setup(){
  Serial.begin(9600);
  pinMode(chanphat, OUTPUT);
  pinMode(chanthu, INPUT);
  pinMode(say , OUTPUT);
}
void loop(){
digitalWrite(chanphat,HIGH);
delayMicroseconds(1000);
digitalWrite(chanphat,LOW);
thoigian=pulseIn(chanthu,HIGH);
khoangcach=0.0344*(thoigian/2);
Serial.print(khoangcach);
Serial.println("cm");
if(khoangcach<10)
{
  digitalWrite(say ,HIGH);
} else {
  delay(1000);
  digitalWrite(say ,LOW);}
}
