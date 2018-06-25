// Created by Kyle DuFrene, June 12, 2018

#include <RGB.h> //use setColor(boolean red, boolean green...
RGB led6(23, 25, 27);
RGB led5(29, 31, 33);
RGB led4(35, 37, 39);
RGB led3(41, 43, 45);
RGB led2(47, 49, 51);
RGB led1(53, 52, 50);
RGB led7(48, 46, 44);
RGB led8(42, 40, 38);

const int cannon1 = 30;
const int cannon2 = 28;
const int cannon3 = 26;
const int cannon4 = 32;
const int cannon5 = 34;
const int cannon6 = 36;
/*const int leftButton = 49;
const int rightButton = 50;*/
const int armPin = 24;
const int tx = 18;
const int rx = 19;
const int rightJoystick = 14;
const int leftJoystick = 15;
//boolean armed = false;
boolean launcher1 = false;
boolean launcher2 = false;
boolean launcher3 = false;
boolean launcher4 = false;
boolean launcher5 = false;
boolean launcher6 = false;
int prevArm = 1;
int armed = 1;
int prevl1 = 1;
int prevl2 = 1;
int prevl3 = 1;
int prevl4 = 1;
int prevl5 = 1;
int prevl6 = 1;

//char message[11] = {'<','0','9','0','0','9','0','0','0','0','>'};
String message = "<090090010>";
int rightSpeed = 90;
int leftSpeed = 90;
int launch = 0;
char lightSetting = '0';
String temp;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(74880);
  Serial1.begin(57600);
  pinMode(cannon1, INPUT_PULLUP);
  pinMode(cannon2, INPUT_PULLUP);
  pinMode(cannon3, INPUT_PULLUP);
  pinMode(cannon4, INPUT_PULLUP);
  pinMode(cannon5, INPUT_PULLUP);
  pinMode(cannon6, INPUT_PULLUP);
//  pinMode(leftButton, INPUT);
 // pinMode(rightButton, INPUT);
pinMode(armPin, INPUT_PULLUP);
led1.setColor(true, false, false);
led2.setColor(true, false, false);
led3.setColor(true, false, false);
led4.setColor(true, false, false);
led5.setColor(true, false, false);
led6.setColor(true, false, false);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  message = "";
  rightSpeed = analogRead(rightJoystick)*.175;
  temp = rightSpeed;
  if (rightSpeed < 100) {
    temp = "0" + (String)rightSpeed;
  }
  if (rightSpeed < 10) {
    temp = "0" + temp;
  }
  message = "<" + temp;

  leftSpeed = analogRead(leftJoystick)*.175;
   temp = leftSpeed;
  if (leftSpeed < 100) {
    temp = "0" + (String)leftSpeed;
  }
  if (leftSpeed < 10) {
    temp = "0" + temp;
  }
  message += temp;
  armed = digitalRead(armPin);
if (armed == 0) {

  if (digitalRead(cannon1) == 0 && prevl1 == 1) {
    launch = 1;
    prevl1 = 0;
    led1.setColor(false, true, false);
    
  } else if (digitalRead(cannon2) == 0 && prevl2 == 1) {
    launch = 2;
    prevl2 = 0;
    led2.setColor(false, true, false);
  } else if (digitalRead(cannon3) == 0 && prevl3 == 1) {
    launch = 3;
    prevl3 = 0;
    led3.setColor(false, true, false);
  } else if (digitalRead(cannon4) == 0/* && prevl4 == 1*/) {
    lightSetting = '1';
    prevl4 = 0;
    led4.setColor(false, true, false);
    led6.setColor(false, false, false);
    led5.setColor(false, false, false);
  } else if (digitalRead(cannon5) == 0/* && prevl5 == 1*/) {
    lightSetting = '2';
    prevl5 = 0;
    led5.setColor(false, true, false);
    led4.setColor(false, false, false);
    led6.setColor(false, false, false);
  } else if (digitalRead(cannon6) == 0/* && prevl6 == 1*/) {
    lightSetting = '9';
    prevl6 = 0;
    led6.setColor(false, true, false);
    led5.setColor(false, false, false);
    led4.setColor(false, false, false);
  }
  prevArm = 0;
}

if (prevArm != armed) {
  prevl1 = 1;
  prevl2 = 1;
  prevl3 = 1;
  prevl4 = 1;
  prevl5 = 1;
  prevl6 = 1;
  led1.setColor(true, false, false);
  led2.setColor(true, false, false);
  led3.setColor(true, false, false);
  led4.setColor(true, false, false);
  led5.setColor(true, false, false);
  led6.setColor(true, false, false);
  prevArm = 1;
}

  /*if (digitalRead(armPin) == HIGH) */message[7] = launch; 
  message += launch;
  launch = 0;
  message = message + lightSetting + "0>"; 
  //Serial.println(message); // For debugging
  Serial1.println(message);
  delay(10);
  
}
