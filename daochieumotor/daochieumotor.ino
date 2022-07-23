
#define chanphat1 4 //trig1
#define chanthu1 2 //echo1
#define chanphat2 8 //trig2
#define chanthu2 7 //echo2
/*int relaydc=12;
int relay=11;*/
int thoigian1,khoangcach1,thoigian2,khoangcach2;
void setup(){
  Serial.begin(9600);
  pinMode(chanphat1, OUTPUT);
  pinMode(chanthu1, INPUT);
  
  pinMode(chanphat2, OUTPUT);
  pinMode(chanthu2, INPUT);
  /*pinMode(relaydc, OUTPUT);
  pinMode(relay, OUTPUT);*/
  pinMode(A0,OUTPUT);
 /* pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);*/
  digitalWrite(A0,HIGH);
  /*digitalWrite(A1,HIGH);
  digitalWrite(A2,LOW);*/
}
void loop(){
  
digitalWrite(chanphat1,HIGH);
delayMicroseconds(1000);
digitalWrite(chanphat2,HIGH);
delayMicroseconds(1000);

digitalWrite(chanphat1,LOW);
digitalWrite(chanphat2,LOW);
thoigian1=pulseIn(chanthu1,HIGH);
thoigian2=pulseIn(chanthu2,HIGH);
khoangcach1=0.0344*(thoigian1/2);
khoangcach2=0.0344*(thoigian2/2);
Serial.print("khoangcach1 ");
Serial.print(khoangcach1);
Serial.print("\n");

Serial.print("khoangcach2 ");
Serial.print(khoangcach2); 
Serial.print("\n");

/*if (khoangcach1<50)
{
  digitalWrite(relay,LOW); 
  Serial.print("motor đang xuống ");
  if (khoangcach2< 35) { //Gặp người
      digitalWrite(relay,HIGH); //kích nguồn dừng lại 
      Serial.print("motor đang dừng ");
      delay(40000); // tg đo đạc
      digitalWrite(relaydc,LOW);// đảo chiều
      Serial.print("đảo chiều ");
      digitalWrite(relay,LOW);// kích nguồn cho motor chạy lên
      Serial.print("motor đang lên ");
      delay(10000);
      digitalWrite(relay,HIGH);// ngừng chạy lên
         Serial.print("ngừng chạy lên ");
         digitalWrite(relaydc,HIGH);// tắt đảo chiều
         Serial.print("tắt đảo chiều ");
      }
}else {
  digitalWrite(relay,HIGH);// ngừng chạy lên
         Serial.print("ngừng chạy lên ");
         digitalWrite(relaydc,HIGH);// tắt đảo chiều
         Serial.print("tắt đảo chiều ");
   Serial.print("ko co ai");      
 }*/
}
 
