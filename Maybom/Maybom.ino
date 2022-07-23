
#define chanphat 8
#define chanthu 7
int nuoc=11;
int xaphong=12;
int maysay=A5; 


int thoigian,khoangcach;
void setup(){
   pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  Serial.begin(9600);
  pinMode(chanphat, OUTPUT);
  pinMode(chanthu, INPUT);
  pinMode(nuoc, OUTPUT);
  pinMode(xaphong, OUTPUT);
  pinMode(maysay, OUTPUT);
  digitalWrite(A0,HIGH);
  digitalWrite(A1,LOW);
  
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
  digitalWrite(nuoc,HIGH);
  delay(2000);
  digitalWrite(nuoc,LOW);
  delay(1000);
 digitalWrite(xaphong,HIGH);
  delay(750);
  digitalWrite(xaphong,LOW);
  delay(5000);
  digitalWrite(nuoc,HIGH);
  delay(5000);
  digitalWrite(nuoc,LOW);
  delay(1000);
  digitalWrite(maysay,HIGH);
  delay(2000);
  digitalWrite(maysay,LOW);
  delay(1000);
  
 }
}
