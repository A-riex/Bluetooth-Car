#include <SoftwareSerial.h>

int tx = 1;
int rx = 0;
char inSerial[16];

void setup() {
  Serial.begin(9600);
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

}

void loop() {
  
  int i = 0;
  delay(500);
  if (Serial.available() > 0 ) {
    while (Serial.available() > 0) {
      inSerial[i] = Serial.read();
      i++;
    }
    inSerial[i] = '\0';
    Check_protocol(inSerial);
  }
}



void Check_protocol(char inStr[]) {

 //--------------------------------------------------------Forward------------------ 
Serial.println(inStr);

if (!strcmp(inStr, "Forward")) {
Serial.print ("F-255");
analogWrite(5,255);
analogWrite(6,0);
analogWrite(9,0);
analogWrite(10,0);

}
//-------------------------------------------------------Stop----------------------

if (!strcmp(inStr, "Stop")) {
  
analogWrite(5,0);
analogWrite(6,0);
analogWrite(9,0);
analogWrite(10,0);

}

//-----------------------------------------------------------------reverse------------------
if (!strcmp(inStr, "Rev")) {
//Serial.print ("B_255");
analogWrite(6,255);
analogWrite(5,0);
analogWrite(9,0);
analogWrite(10,0);

}


//-----------------------------------------------------------------------------Right---
if (!strcmp(inStr, "Right")) {
//Serial.print ("R 255");
analogWrite(5,255);
analogWrite(6,0);
analogWrite(9,0);
analogWrite(10,255);
}
//---------------------------------------------------------Left-------------------------
if (!strcmp(inStr, "Left")) {
Serial.print ("L 255");
analogWrite(5,255);
analogWrite(6,0);
analogWrite(9,255);
analogWrite(10,0);

}
//----------------------------------------------


}
