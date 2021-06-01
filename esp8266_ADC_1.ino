#include "Arduino.h"

void setup() {
  Serial.begin(9600);
}
float HighestVoltage=15.55;
float DATA2=0;//暫存實際電壓
int ActualVoltage=0;//暫存電壓解析度

int LowestValue=7;//可測得解析度最低值校正
int HighestResolution=1024;//系統預設最高解析度

int ActualResolution=HighestResolution-LowestValue;//計算用實際解析度(無須修改)
void loop() {
  Serial.print("ADC Value: ");
  Serial.println(analogRead(A0));//打印出目前讀到的解析度

  ActualVoltage=analogRead(A0)-LowestValue;//最低可測解析度校正計算
  DATA2=HighestVoltage/ActualResolution*ActualVoltage;//實地電壓換算

  Serial.println(DATA2);

  delay(300);
}
