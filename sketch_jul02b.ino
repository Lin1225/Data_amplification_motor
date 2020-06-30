
#include <DynamixelSerial1.h>
String str;
DynamixelClass Dxl(Serial);
 
void setup() {
  Serial.begin(1000000);
  Dxl.begin(1000000, 2);
  delay(1000);
}
 
void loop() {
  ;
  if (Serial.available()) {
    // 讀取傳入的字串直到"\n"結尾
    str = Serial.readStringUntil('\n');
 
    if (str == "move") {           // 若字串值是 "LED_ON" 開燈
      Dxl.ledStatus(1, ON);
      //Dxl.moveRW(1,1000);             //360分成2000

      Dxl.turn(1, RIGTH, 100);
      delay(1000);
      // 回應訊息

      Dxl.ledStatus(1, OFF);
      //Serial.println("moved"); // 回應訊息給電腦
    } else if (str == "kkk") {
      Dxl.turn(1, RIGTH, 0);
        Dxl.ledStatus(1, OFF);
    }
  }
}
