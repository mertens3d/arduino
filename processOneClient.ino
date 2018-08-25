void processOneClient(EthernetClient client) {
  Serial.println(F("s) processOneClient"));
  // an http request ends with a blank line
  String irQueryValue = readRequest(client);
  //debugShowQueryData();
  //Serial.println(F("------------------------------------"));
  
  
  //convertCurrentRequestToCharArray();
  
  
  
  drawHtml(client, irQueryValue);
  // give the web browser time to receive the data
  delay(1);

  Serial.println(F("e) processOneClient"));
}
