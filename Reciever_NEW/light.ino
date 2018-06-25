void light(int option) {
    if (previousLights != option) {
    firstTime = true;
  }
      switch (option) {
  case 1: 
  previousLights = 1;
  if (firstTime) {
    elapsedTime = 0;
    firstTime = false;
  }
    if (first && ((elapsedTime - previousTime) > 1)) {
      previousTime = elapsedTime;
      first = crossFade(orange);
      if (!first) {
        Serial.println("Moving to second");
        second = true;
        firstStep = true;
      }
    }
    else if (second && ((elapsedTime - previousTime) > 1)) {
      previousTime = elapsedTime;
      second = crossFade(green);
      if (!second) {
        Serial.println("Moving to third");
        third = true;
        firstStep = true;
      }
    } else if (third && ((elapsedTime - previousTime) > 1)) {
      previousTime = elapsedTime;
      third = crossFade(blue);
      if (!third) {
        Serial.println("Moving to fourth");
        fourth = true;
        firstStep = true;
      }
    } else if (fourth && ((elapsedTime - previousTime) > 1)) {
      previousTime = elapsedTime;
      fourth = crossFade(red);
      if (!fourth) {
        Serial.println("Moving to fifth");
        fifth = true;
        firstStep = true;
      }
    } else if (fifth && ((elapsedTime - previousTime) > 1)) {
      previousTime = elapsedTime;
      fifth = crossFade(purple);
      if (!fifth) {
        Serial.println("Moving to sixth");
        sixth = true;
        firstStep = true;
      }
    } else if (sixth && ((elapsedTime - previousTime) > 1)) {
      previousTime = elapsedTime;
      sixth = crossFade(yellow);
      if (!sixth) {
        Serial.println("Moving to seventh");
        seventh = true;
        firstStep = true;
      }
    } else if (seventh && ((elapsedTime - previousTime) > 1)) {
      previousTime = elapsedTime;
      seventh = crossFade(white);
      if (!seventh) {
        Serial.println("Moving to eighth");
        eighth = true;
        firstStep = true;
      }
    } else if (eighth && ((elapsedTime - previousTime) > 1)) {
      previousTime = elapsedTime;
      eighth = crossFade(pink);
      if (!eighth) {
        Serial.println("Going back to one");
        first = true;
        firstStep = true;
        elapsedTime = 0;
      }
    }
    
    
    break;


    
 case 2: //random color changes every 1/2 second
previousLights = 1;
  if (firstTime) {
    elapsedTime = 0;
    firstTime = false;
  }
  if (elapsedTime > 500) {
    randNumber = random(12);
      switch (randNumber) {
        case 0: 
        setColorArray(black);
        break;
        case 1:
        setColorArray(white);
        break;
        case 2:
        setColorArray(red);
        break;
        case 3:
        setColorArray(green);
        break;
        case 4:
        setColorArray(blue);
        break;
        case 5:
        setColorArray(yellow);
        break;
        case 6:
        setColorArray(dimWhite);
        break;
        case 7:
        setColorArray(pink);
        break;
        case 8:
        setColorArray(lightPink);
        break;
        case 9:
        setColorArray(purple);
        break;
        case 10:
        setColorArray(orange);
        break;
        case 11:
        setColorArray(lightBlue);
        break;
        default:
        break;
       }
     elapsedTime = 0; 
  } 

    
    break;


    
 case 3:
    
    break;


    
 case 4:
    break;
 case 5:
    
    break;
 case 6:
    
    break;
 case 7:
    
    break;
 case 8:
    
    break;
 case 9: // Flashing red -- error
 previousLights = 1;
 if (firstTime) {
    elapsedTime = 0;
    firstTime = false;
  }
    if (elapsedTime < 250) {
      setColorArray(red);
      //Serial.println("on!");
    } else if (elapsedTime < 500) {
      setColorArray(black);
      //Serial.println("off!");
    } else {
      elapsedTime = 0;
    }
    break;
  default:
    break;
      }  

}
