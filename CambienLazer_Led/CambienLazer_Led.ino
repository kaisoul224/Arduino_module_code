#include <ComponentObject.h>
#include <RangeSensor.h>
#include <SparkFun_VL53L1X.h>
#include <vl53l1x_class.h>
#include <vl53l1_error_codes.h>
#include <Wire.h>
#include "SparkFun_VL53L1X.h" 
#define SHUTDOWN_PIN 2
#define INTERRUPT_PIN 3
int led= 12; // Khai bao chan phat cho led
SFEVL53L1X distanceSensor;

void setup(void)
{
  Wire.begin();
   // Cam bien khoang cach lazer
  Serial.begin(115200);
  Serial.println("VL53L1X Qwiic Test");

  if (distanceSensor.begin() != 0) 
  {
    Serial.println("Sensor failed to begin. Please check wiring. Freezing...");
    while (1)
      ;
  }
  Serial.println("Sensor online!");
  //===================================================================
  pinMode(led, OUTPUT);// Khai bao chan phat cho led
}

void loop(void)
{
  distanceSensor.startRanging(); //Write configuration bytes to initiate measurement
  while (!distanceSensor.checkForDataReady())
  {
    delay(1);
  }
  int distance = distanceSensor.getDistance(); //Get the result of the measurement from the sensor
  distanceSensor.clearInterrupt();
  distanceSensor.stopRanging();
  // Khoang cach tinh bang mm
  Serial.print("Distance(mm): ");
  Serial.print(distance);
  if(distance>0 && distance<1000) // Neu khoang cach >0 va <1m thi nhay role
  {
    digitalWrite(led,HIGH); // led bat dau sang
    delay(10000); // led sang trong 10s
    digitalWrite(led,LOW); // Sau 10s led tat
    delay(500); // doi 0,5s sau moi dc chay tiep --> de chong spam :v
  }
}
