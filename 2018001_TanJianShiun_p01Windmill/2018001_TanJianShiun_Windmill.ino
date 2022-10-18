/* * Name : TAN JIAN SHIUN
 * stdID : 2018001
 * HW : Windmill
 */

#include "UKIT_Advance.h"
#include "IRremote.h"

int fanmode = 0; 
int fanSpeed = 0;

void setup() {
  Initialization();
}

void loop() {
  button1.Update();
  if(button1.clicks == 1){
    fanmode++;
    if(fanmode>=4){
      fanmode = 0;
    }
  }

  switch(fanmode){
    case 0:
    // 亮红灯，表示已通电
    setRgbledColor(255,0,0);
    setMotorStop(1);
    break;

    case 1:
    //  开始转动，转速=46（慢速）
    fanSpeed = 46;
    setMotorTurn(1,fanSpeed);  
    break;

    case 2:
    // 加速转动，转速 = 92（中速）
    fanSpeed = 92;
    setMotorTurn(1,fanSpeed); 
    break;

    case 3:
    // 加快转速，转速=140（快速）
    fanSpeed = 140;
    setMotorTurn(1,fanSpeed); 
    break;
  }

// 长按，停止转动
  if(button1.clicks == -1){
    setMotorStop(1);
  }


  Serial.print("fanmode = ");
  Serial.println(fanmode);
  Serial.print("fanSpeed = ");
  Serial.println(fanSpeed);
}
