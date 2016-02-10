
char readClient(EthernetClient client) {
  char c = ' ';
  if (client.available()) {
    c = client.read();
  }
  return c;
}

void debugShowQueryData() {
  Serial.println(F("(s) debugShowQueryData - queryCharArCurrentMaxIdx: " ));
  Serial.println (queryCharArCurrentMaxIdx);

  for (int idx = 0; idx <= queryCharArray[queryCharArCurrentMaxIdx]; idx++) {
    Serial.print(queryCharArray[idx]);
  }
  Serial.println();
  Serial.println(F("(e) debugShowQueryData"));

}


void drawHtml(EthernetClient client) {
  Serial.println("drawHtml " + String(codeLen));
  client.println(F("HTTP/1.1 200 OK"));
  client.println(F("Content-Type: text/html"));
  client.println(F("Connection: close"));  // the connection will be closed after completion of the response
  //client.println("Refresh: 5");  // refresh the page automatically every 5 sec
  client.println();
  client.println(F("<!DOCTYPE HTML>"));
  client.println(F("<html>"));
  client.println(F("<body>"));

  client.println(F("<div>"));
  for (int idxJ = 0; idxJ <= queryCharArCurrentMaxIdx; ++idxJ) {
    client.print(String(queryCharArray[idxJ]));
  }
  client.println(F("</div>"));


  client.println(F("<div>"));
  client.println(F("irRawCodesAr"));
  client.println(F("<br />"));
  for (int idx = 0; idx <= ifRawCodesArMaxIdx; ++idx) {
    client.print(String(irRawCodesAr[idx]));
    client.print(F("."));
  }
  client.println(F("</div>"));
  client.println(F("done<br />"));
  client.println(F("</body>"));
  client.println(F("</html>"));



}
