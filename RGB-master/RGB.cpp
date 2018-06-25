/*
  RGB.cpp - Library for basic RGB LED stuff
  Created by Kyle DuFrene, June 12, 2018
*/

#include "Arduino.h"
#include "RGB.h"

RGB::RGB(int red, int green, int blue)
{
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  _red = red;
  _green = green;
  _blue = blue;
}

void RGB::setColor(boolean redSetting, boolean greenSetting, boolean blueSetting)
{
  if (redSetting) {
    digitalWrite(_red, HIGH);
  } else {
    digitalWrite(_red, LOW);
  }
  
  if (greenSetting) {
    digitalWrite(_green, HIGH);
  } else {
    digitalWrite(_green, LOW);
  }
  
    if (blueSetting) {
    digitalWrite(_blue, HIGH);
  } else {
    digitalWrite(_blue, LOW);
  }
}
