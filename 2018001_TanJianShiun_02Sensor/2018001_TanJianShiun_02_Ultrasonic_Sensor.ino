/*
 * Name :Tan Jian Shiun
 * Student ID:18001
 * Homework: 02 Ultrasonic Sensor
 */
 
#include "UKIT_Advance.h"
void setup() {
  Initialization();
  Serial.begin(9600);
}

void loop() {
  setUltrasonicRgbled(1,275,245,173);

  if(readInfraredDistance(1)<20){
    setRgbledColor(255,0,255);
  }
  else if(readInfraredDistance(1)>20 && readInfraredDistance(1)<30){
    setRgbledColor(255,255,0);
  }
  else{
    setRgbledColor(255,0,0);
  }
  
  Serial.print("Distance:");
  Serial.print("\t");  
  Serial.println(readInfraredDistance(1));  

}
