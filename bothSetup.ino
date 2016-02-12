
void setupEthernet() {
  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}
void setupIr()
{
  // Serial.println("RAWBUF = " + RAWBUF);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(STATUS_PIN, OUTPUT);
  pinMode(STATUS_PIN_B, OUTPUT);
}

void resetWebVariables() {
  Serial.println(F("resetWebVariables "));
  queryNumberGroups = 0;
  queryCharArCurrentMaxIdx = 0;

  for (int idx = 0; idx <= queryCharArrayMaxChar; idx ++) {
    queryCharArray[idx] = 0;
  }
  for (int idxJ = 0; idxJ <= RAWBUF; idxJ ++) {
    rawCodes[idxJ] = 0;
  }

}

