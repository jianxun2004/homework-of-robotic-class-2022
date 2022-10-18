/*
 * Name : TAN JIAN SHIUN
 * stdID : 2018001
 * HW : IR Remote
 *
 *0 FF6897
 *1 FF30CF
 *2 FF18E7
 *3 FF7A85
 *4 FF10EF
 *5 FF38C7
 *6 FF5AA5
 *7 FF42BD
 *8 FF4AB5
 *9 FF52AD
 */
 
#include "UKIT_Advance.h" //indlude library
#include "IRremote.h" //include IR function

long ir_item;
IRrecv irrecv(37);
decode_results results;

long KEY_OFF = 0xFFA25D;
long KEY_0 = 0xFF6897;
long KEY_1 = 0xFF30CF;
long KEY_2 = 0xFF18E7;
long KEY_3 = 0xFF7A85;
long KEY_4 = 0xFF10EF;
long KEY_5 = 0xFF38C7;
long KEY_6 = 0xFF5AA5;
long KEY_7 = 0xFF42BD;
long KEY_8 = 0xFF4AB5;
long KEY_9 = 0xFF52AD;
long KEY_pressing = 0xFFFFFFFF;
long longkey = 0;

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
    //按下按钮OFF
    if(results.value == KEY_OFF){
      setRgbledColor(0,0,0);
    }

  //按下按钮1
  if(results.value == KEY_1){
    setRgbledColor(255,0,0);
    longkey = KEY_1;
  }

  //按下按钮2
  if(results.value == KEY_2){
    setRgbledColor(0,255,0);
    longkey = KEY_2;
  }

  //按下按钮3
  if(results.value == KEY_3){
    setRgbledColor(0,0,255);
    longkey = KEY_3;
  }

  //按下按钮4
  if(results.value == KEY_4){
    setRgbledColor(255,0,0);
    delay(100);
    setRgbledColor(0,0,255);
    delay(100);
  }
  
  //按下按钮5
  if(results.value == KEY_5){
  }

  //长按按钮1
  if(results.value == KEY_pressing && longkey == KEY_1){
    setRgbledColor(255,0,255);
  }

  //长按按钮2
  if(results.value == KEY_pressing&& longkey == KEY_2){
    setRgbledColor(255,255,0);
  }

  //长按按钮3
  if(results.value == KEY_pressing&& longkey == KEY_2){
    setRgbledColor(255,255,255);
    delay(100);
    setRgbledColor(0,0,0);
    delay(100);
  }//若要行使循环需在loop{}范围
}
