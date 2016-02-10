void sendCode(int repeat) {
  digitalWrite(STATUS_PIN, HIGH);
  digitalWrite(STATUS_PIN_B, HIGH);

   codeLen = irRawCodesArMaxIdx -1;
   
   Serial.println(irRawCodesArMaxIdx);
  for (int idx = 0; idx < repeat; idx++) {


    Serial.println(F("Sending"));


    // (codeType == UNKNOWN /* i.e. raw */) {
    // Assume 38 KHz
    irsend.sendRaw(irRawCodesAr, codeLen, 38);
    Serial.println("Sent raw");// + irRawCodesAr);


    delay(50); // Wait a bit between retransmissions

  }
  digitalWrite(STATUS_PIN, LOW);
  digitalWrite(STATUS_PIN_B, LOW);
}

//8850.4500.500.650.450.1800.450.650.450.1750.500.1750.450.1800.450.1850.350.700.450.1750.500.650.400.1800.450.700.400.700.400.750.400.650.450.1800.450.700.400.1800.400.1800.450.1800.450.1850.400.650.450.650.450.650.450.1800.450.650.450.650.450.700.400.700.450.1750.450.1800.450.1800.450
//I think I need to convert the code from the query string back into irRawCodesAr
//Troubleshooting
//To make it easier to debug problems with IR communication, I have optional debugging code in the library. Add #define DEBUG to the beginning of your code to enable debugging output on the serial console. You will need to delete the .o files and/or restart the IDE to force recompilation.
//https://learn.sparkfun.com/tutorials/ir-communication
//http://www.righto.com/2009/07/secrets-of-arduino-pwm.html
//http://lirc-remotes.sourceforge.net/remotes-table.html
//http://www.righto.com/search?q=infrared
