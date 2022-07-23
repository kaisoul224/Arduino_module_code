#include <FirebaseArduino.h>


void setup() {
  WiFi.disconnect();
  WiFi.begin("VNPT_TT","nhatquang1412");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(222);
}
  
FireBase.begin("temperture-87e40-default-rtdb.firebaseio.com");
void loop() {
Firebase.setString("/QuocAnh","khung");
delay(500);
}
