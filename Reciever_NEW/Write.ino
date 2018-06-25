void drive(String powerR, String powerL) {
  rightSpeed = powerR.toInt();
  leftSpeed = powerL.toInt();
  right_motor.write(rightSpeed);
  left_motor.write(leftSpeed);
}

void launch(int number) {
  switch (number) {
    case 0:
    break;
  case 1:
    digitalWrite(cannon1, HIGH);
    digitalWrite(light1, HIGH);
    delay(50);
    digitalWrite(cannon1, LOW);
    digitalWrite(light1, LOW);
    break;
 case 2:
    digitalWrite(cannon2, HIGH);
    digitalWrite(light2, HIGH);
    delay(50);
    digitalWrite(cannon2, LOW);
    digitalWrite(light2, LOW);
    break;
 case 3:
    digitalWrite(cannon3, HIGH);
    digitalWrite(light3, HIGH);
    delay(50);
    digitalWrite(cannon3, LOW);
    digitalWrite(light3, LOW);
    break;
  default:
    break;
  }  
}

void setColorArray(int colorArray[3]) {
  analogWrite(red_pin, colorArray[0]);
  analogWrite(green_pin, colorArray[1]);
  analogWrite(blue_pin, colorArray[2]);
  
}

