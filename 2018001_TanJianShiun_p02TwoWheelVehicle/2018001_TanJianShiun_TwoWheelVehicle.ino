/* * Name : TAN JIAN SHIUN
 * stdID : 2018001
 * HW : TwoWheelVehicle
 */

#include "UKIT_Advance.h"
#include "IRremote.h"

long ir_item;
decode_results results;
IRrecv irrecv(37);  //接收红外线

long KEY_Power = 0xFFA25D;
long KEY_0 = 0xFF6897;
long KEY_1 = 0xFF30CF;
long KEY_2 = 0xFF18E7;;
long KEY_4 = 0xFF10EF;
long KEY_6 = 0xFF5AA5;
long KEY_8 = 0xFF4AB5;
long KEY_pressing = 0xFFFFFFFF;
long longkey = 0;

int speed = 80;

void setup() {
  Initialization();
  irrecv.enableIRIn();
}

void loop() {
  if(irrecv.decode(&results)){
    Serial.println(results.value,HEX); //检查收到的信号
    Serial.println(); //空行
    irrecv.resume(); //等待下一个红外线信号
  }
    //按下按钮电源键
    if(results.value == KEY_Power){
      setRgbledColor(0,0,0);
    }

  //按下按钮1
  if(results.value == KEY_1){
    Stop();
    longkey = KEY_1;
  }

  //按下按钮2
  if(results.value == KEY_2){
    MoveForward();
    longkey = KEY_2;
  }

  //按下按钮4
  if(results.value == KEY_4){
    TurnLeft();
  }
  
  //按下按钮6
  if(results.value == KEY_6){
    TurnRight();
  }

  //按下按钮8
  if(results.value == KEY_8){
    MoveReverse();
  }

  //长按按钮1
  if(results.value == KEY_pressing && longkey == KEY_1){
    setRgbledColor(255,0,255);
  }

  //长按按钮2
  if(results.value == KEY_pressing&& longkey == KEY_2){
    setRgbledColor(255,255,0);
  }//若要行使循环需在loop{}范围
}



//功能设置
void MoveForward(){
    setMotorTurnAdj(1,+140,0xffff);
    setMotorTurnAdj(2,-140,0xffff);
}
void MoveReverse(){
    setMotorTurnAdj(1,-140,0xffff);
    setMotorTurnAdj(2,+140,0xffff);
}
void TurnLeft(){
    setMotorTurnAdj(1,+20,0xffff);
    setMotorTurnAdj(2,-140,0xffff); 
}
void TurnRight(){
    setMotorTurnAdj(1,+140,0xffff);
    setMotorTurnAdj(2,-20,0xffff);
}
void Stop(){
    setMotorTurnAdj(1,0,0xffff);
    setMotorTurnAdj(2,0,0xffff);
}
