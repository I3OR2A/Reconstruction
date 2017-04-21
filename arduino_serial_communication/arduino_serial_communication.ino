#include <Wire.h>
#include <SoftwareSerial.h>
#include <Stepper.h>
#define STEPS 200  //定義步進馬達每圈的步數

//steps:代表馬達轉完一圈需要多少步數。如果馬達上有標示每步的度數，
//將360除以這個角度，就可以得到所需要的步數(例如：360/3.6=100)。(int)

Stepper stepper(STEPS, 7, 6, 5, 4);
SoftwareSerial I2CBT(10, 11); // //定義Arduino PIN10及PIN11分別為RX及TX腳位
int LED = 13;

void setup()
{
  // The setting for testing the serial communcation with usb connected
  Serial.begin(19200);
  pinMode(LED, OUTPUT); 

  // The setting for bluetooth
  // I2CBT.begin(9600);

  // The setting for the stepper motor
  stepper.setSpeed(140);     // 將馬達的速度設定成140RPM 最大  150~160
}

void loop()
{
  // For testing the serial communcation
  if(Serial.available() > 0){
      char c = Serial.read();
      if(c = '1'){
         // digitalWrite(LED, HIGH);
        Serial.print("HIGH."); 
      }
      else if(c = '0'){
        // digitalWrite(LED, LOW);
        Serial.print("LOW."); 
      }
   }

  // For testing the bluetooth communication
  /*
  byte cmmd[20];
  int insize;
  if ((insize=(I2CBT.available()))>0){  //read message from bluetooth
      Serial.print("input size = "); 
      Serial.println(insize);
    for (int i=0; i<insize; i++){
      Serial.print(cmmd[i]=char(I2CBT.read()));
      Serial.print("\n"); 
    }
  }
  switch (cmmd[0]) { //根據所收到訊號執行對應動作,讀取第一個字元  
    case 97: //'a'     
      digitalWrite(LED,HIGH);
      break;  

    case 98://'b'
      digitalWrite(LED,LOW);
      break;
  } 
  */
  
  // For testing the stepper motor funtion
  /*
  stepper.step(100);//正半圈
  delay(1000);
  stepper.step(-100);//反半圈
  delay(1000);
  stepper.step(200);//正1圈
  delay(1000);
  stepper.step(-200);//反1圈
  delay(1000);
  stepper.step(300);//正1圈半
  delay(1000);
  stepper.step(-300);//反1圈半
  delay(1000);
  stepper.step(1600);//正8圈
  delay(1000);
  stepper.step(-1600);//反8圈
  delay(1000);
  */
}

