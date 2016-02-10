void loopIrB() {
  //Serial.println(F("(s) loopIrB"));
  //irrecv.enableIRIn(); // Re-enable receiver
  if (irrecv.decode(&results)) {
    Serial.println("dddd");
    digitalWrite(STATUS_PIN, HIGH);
    storeCode(&results);
    irrecv.resume(); // resume receiver
    digitalWrite(STATUS_PIN, LOW);

  }

}

