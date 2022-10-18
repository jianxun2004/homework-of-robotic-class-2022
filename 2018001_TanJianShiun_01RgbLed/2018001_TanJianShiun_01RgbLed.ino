/*
 * Name :Tan Jian Shiun
 * Student ID:18001
 * 

 */
#include "UKIT_Advance.h"

void setup() {
  Initialization();
}

void loop() {
  button1.Update();
  if(button1.clicks == 1){
    setRgbledColor(0,0,0);//(R,G,B,)
    delay(1000);//Flash reh 1000ms
  }
  
  }
 
  else if(button1.clicks == -1){
    setRgbledColor(0,0,255);   
    delay(1000);
    setRgbledColor(0,255,0);   
    delay(1000);
  }

  else{
    setRgbledColor(249，205，173);
  }
  //tone(131,3000);
  //noTone(38);
  //delay(1000);
}
