void loopIrB() {
  //Serial.println(F("(s) loopIrB"));
  //irrecv.enableIRIn(); // Re-enable receiver
  if (irrecv.decode(&results)) {

    digitalWrite(STATUS_PIN, HIGH);
    Serial.println(F("--------------------------Orig Code Start"));
    Serial.println(F(""));

    
    storeCode(&results);
    Serial.println(F(""));
    Serial.println(F("--------------------------Orig Code End"));
    drawRawCodesToSerial();
   
    storeCodeModified(&results);
    drawRawCodesToSerial();
    
    irrecv.resume(); // resume receiver
    digitalWrite(STATUS_PIN, LOW);

  }

}

