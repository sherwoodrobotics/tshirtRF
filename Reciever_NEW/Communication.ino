void readMessages() 
{
  while (Serial.available()>0 /*&& !ended*/){
    //Read the incoming byte
    counter = 0;
    incomingByte = Serial.read();
    //Start the message when the '<' symbol is received
    if(incomingByte == '<')
    {
     started = true;
     index = 0;
     msg[index] = '\0'; // Throw away any incomplete packet
   }
   //End the message when the '>' symbol is received
   else if(incomingByte == '>')
   {
     ended = true;
     break; // Done reading - exit from while loop!
   }
   //Read the message!
   else
   {
     if(index < 10) // Make sure there is room
     {
       msg[index] = incomingByte; // Add char to array
       index++;
       msg[index] = '\0'; // Add NULL to end
     }
   }
}
}

void serialUnavailable() {
  counter ++;
  if (counter > 2500)
  {
  msg[0] = '0';
  msg[1] = '9';
  msg[2] = '0';
  msg[3] = '0';
  msg[4] = '9';
  msg[5] = '0';
  msg[6] = '0';
  msg[7] = '9';
  
  counter = 0;
  started = true;
  ended = true;
  }
}

