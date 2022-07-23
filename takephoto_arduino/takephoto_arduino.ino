
#define chanphat 8 //trig
#define chanthu 7 //echo
int take=12;
int thoigian,khoangcach;
void setup(){
  Serial.begin(9600);
  pinMode(chanphat, OUTPUT);
  pinMode(chanthu, INPUT);
  pinMode(take, OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  digitalWrite(A0,LOW);
  digitalWrite(A1,LOW);
  digitalWrite(A2,HIGH);
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
  digitalWrite(take,HIGH);
} else digitalWrite(take,LOW);
}
