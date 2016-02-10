void processOneClient(EthernetClient client) {
  Serial.println(F("new client"));
  // an http request ends with a blank line
  readRequest(client);
  //debugShowQueryData();
  //Serial.println(F("------------------------------------"));
  convertCurrentRequestToCharArray();
  drawHtml(client);
  // give the web browser time to receive the data
  delay(1);
}
