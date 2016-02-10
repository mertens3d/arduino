void sendCode(int repeat) {
  digitalWrite(STATUS_PIN, HIGH);
  digitalWrite(STATUS_PIN_B, HIGH);

   codeLen = ifRawCodesArMaxIdx -1;
   
   Serial.println(ifRawCodesArMaxIdx);
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
