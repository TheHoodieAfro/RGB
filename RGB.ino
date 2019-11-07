#include <SoftwareSerial.h>

SoftwareSerial BTserial(10, 11); // RX | TX

int sensorPin = 0;
int sensorValue = 0;

int redInput= 11;
int greenInput = 10;
int blueInput = 9;

void setup() {

  BTserial.begin(9600);
  
  pinMode(redInput, OUTPUT);
  pinMode(greenInput, OUTPUT);
  pinMode(blueInput, OUTPUT);
  
}

void loop() {

  sensorValue = analogRead(sensorPin);

  if(sensorValue <= 20){
    RGB(0, 0, 255);
  }else if(sensorValue > 20 && sensorValue <= 34){
    RGB(255, 255, 0);
  }else {
    RGB(255, 0, 0);
  }
  
  BTserial.print(sensorValue);
  
  delay(1000);

}

void RGB(int r, int g, int b) {
  
  analogWrite(redInput, r);
  analogWrite(greenInput, g);
  analogWrite(blueInput, b);
  
}
