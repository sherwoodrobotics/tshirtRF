// Created by Kyle DuFrene, June 12, 2018

#include <Arduino.h>
#include <Servo.h>
#include <elapsedMillis.h>

elapsedMillis elapsedTime;
Servo right_motor;
Servo left_motor;

// Constants -- pin locations
const int red_pin = 5;
const int green_pin = 11;
const int blue_pin = 6;
const int cannon1 = 4;
const int cannon2 = 3;
const int cannon3 = 2;
const int light1 = 7;
const int light2 = 8;
const int light3 = 12;
const int rightMotorPin = A0;
const int leftMotorPin = A1;
//const int tx = 1; //These connect to XBee. May currently be switched, also don't really matter if written in code
//const int rx = 0;


//Message variables
int counter = 0;
bool started = false; //True: Message is started
bool ended   = false; //True: Message is finished 
char incomingByte ; //Variable to store the incoming byte
char msg[10];    //Message - array from 0 to 10
byte index;     //Index of array
String str;


//Drive variables
int rightSpeed = 90;
int leftSpeed = 90;



//Light variables
boolean firstTime = true;
boolean firstStep = true;
boolean first = true;
boolean second = false;
boolean third = false;
boolean fourth = false;
boolean fifth = false;
boolean sixth = false;
boolean seventh = false;
boolean eighth = false;
int i = 0;
int previousTime;
long randNumber;
int lightSetting = 0;


// Light combinations
int black[3]  = { 0, 0, 0 };
int white[3]  = { 255, 200, 50 };
int red[3]    = { 255, 0, 0 };
int green[3]  = { 0, 255, 0 };
int blue[3]   = { 0, 0, 255 };
int yellow[3] = { 255, 200, 0 };
int dimWhite[3] = { 200, 100, 25 };
int pink[3] = { 255, 0, 10 };
int lightPink[3] = { 255, 10, 10 };
int purple[3] = { 255, 0, 255 };
int orange[3] = { 255, 40, 0 };
int lightBlue[3] = { 255, 255, 255};


int R;
int G;
int B;
int stepR;
int stepG; 
int stepB;
int redVal = black[0]; // Set initial color
int greenVal = black[1]; 
int blueVal = black[2];
int prevRed = redVal; // Initialize color variables
int prevGreen = greenVal;
int prevBlue = blueVal;
int previousLights = 0;




void setup() {

  //Start the serial communication
  Serial.begin(57600); //Baud rate same as is on xBee module
  right_motor.attach(rightMotorPin);
  left_motor.attach(leftMotorPin);
  right_motor.write(90);
  left_motor.write(90);
  pinMode(cannon1, OUTPUT);
  pinMode(cannon2, OUTPUT);
  pinMode(cannon3, OUTPUT);
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(light3, OUTPUT);
  pinMode(red_pin, OUTPUT);   // sets the pins as output
  pinMode(green_pin, OUTPUT);   
  pinMode(blue_pin, OUTPUT);
  digitalWrite(cannon1, LOW);
  digitalWrite(cannon2, LOW);
  digitalWrite(cannon3, LOW);
  digitalWrite(light1, LOW);
  digitalWrite(light2, LOW);
  digitalWrite(light3, LOW);
  
  
}

void loop() {

//analogWrite(green_pin, 255);
  if (Serial.available() == 0) 
  {
  serialUnavailable();
  } else
  {
  readMessages();
  }

 

  if(started && ended)
  {
   
     str = msg;
     //lightSetting = msg[7].toInt();
   drive(str.substring(0, 3),str.substring(3, 6));
   //Serial.println(str);
   
    launch((str.substring(6, 7)).toInt());
   
   

   index = 0;
   msg[index] = '\0';
   started = false;
   ended = false;

 }
    light((str.substring(7, 8)).toInt()); //(str.substring(7, 8)).toInt()
    //Serial.println(str);
}
