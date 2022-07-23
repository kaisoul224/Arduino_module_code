
#include <ESP8266WiFi.h>

const char* ssid     = "Đức Óc Chó";       //tên host wifi muốn truy cập

const char* password = "12345789";            //pass wifi muốn truy cập

WiFiServer server(80);                        //Mặc định port luôn là 80

void setup()

{

  Serial.begin(9600);

  delay(10);

  pinMode(2,OUTPUT);

  Serial.print("Connecting to ");

  Serial.println(ssid); 

  WiFi.begin(ssid, password); 

  while (WiFi.status() != WL_CONNECTED)

  {

    delay(300);

    Serial.print("*");

    digitalWrite(2,!digitalRead(2));   

  }

  Serial.println(" ");

  Serial.println("WiFi connected. IP address: "); 

  Serial.println(WiFi.localIP());

  server.begin(); 

}

void loop()

{

  WiFiClient client = server.available();

  if(!client)

    return;

  while(!client.available())

    delay(1);

  String request = client.readStringUntil('\r');

  Serial.println(request);

  client.flush();

  delay(1);

}
