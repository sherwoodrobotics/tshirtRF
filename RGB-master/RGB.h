//Created by Kyle DuFrene, June 12, 2018

#ifndef RGB_h
#define RGB_h

#include "Arduino.h"

class RGB
{
  public:
    RGB(int red, int green, int blue);
    void setColor(boolean redSetting, boolean greenSetting, boolean blueSetting);
  private:
    int _red;
    int _green;
    int _blue;
};

#endif
