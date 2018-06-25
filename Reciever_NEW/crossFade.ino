boolean crossFade(int color[3]) {
  if (firstStep) 
  {
  R = (color[0]);
  G = (color[1]);
  B = (color[2]);
  stepR = calculateStep(prevRed, R);
  stepG = calculateStep(prevGreen, G); 
  stepB = calculateStep(prevBlue, B);
  }

  if (i <= 1020) {
    redVal = calculateVal(stepR, redVal, i);
    greenVal = calculateVal(stepG, greenVal, i);
    blueVal = calculateVal(stepB, blueVal, i);
    i++;
    if (i == 1020) {
      redVal = R;
      greenVal = G;
      blueVal = B;
    }
    analogWrite(red_pin, redVal);   // Write current values to LED pins
    analogWrite(green_pin, greenVal);      
    analogWrite(blue_pin, blueVal); 
    }
  firstStep = false;
  if (redVal == R && greenVal == G && blueVal == B) {
  prevRed = redVal; 
  prevGreen = greenVal; 
  prevBlue = blueVal;
  i=0;
    return false;
  } else {
    return true;
  }
}
