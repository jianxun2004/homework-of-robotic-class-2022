/*
 * Name :Tan Jian Shiun
 * StdID:18001
 *    HW:03Inrared
 */

#include "UKIT_Advance.h" //indlude library
#include "IRremote.h" //include IR function【.h是格式,类似.txt,其中为16进位制】

long ir_item;
IRrecv irrecv_37(37);  //接收红外线
decode_results results_37;  //decode【解码】,encode【编码】

void setup() {
  Initialization();//initial ukit control board 初始化
  irrecv_37.enableIRIn(); //句点后是指令
}

void loop() {
  if(irrecv_37.decode(&results_37)){
    ir_item = results_37.value;
    String type = "UNKNOWN";
    String typelist[14] = {"UNKNOWM","NEC","SONY","RC5","RC6","DISH","SHARP","PANASONIC","JVC","SANYO","MISTUBISHI","SAMSUNG","LG","WYNTHER"} ;
    
    if(results_37.decode_type >= 1 && results_37.decode_type <= 13){
      type = typelist[results_37.decode_type];
    }

    Serial.print("IR type:");
    Serial.print(type);
    Serial.print("\t");  //tab
    Serial.println(ir_item,HEX);

    irrecv_37.resume();   //循环待机
  }

  else{
  }
}
