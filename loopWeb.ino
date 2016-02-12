void loopWeb() {

  // listen for incoming clients----
  EthernetClient client = server.available();

  if (client) {
    resetWebVariables();
    processOneClient(client);
    // close the connection:
    client.stop();

    Serial.println(F("------------------------------- Original way"));
    //sendCode(1);

    Serial.println(F("------------------------------- Modified way"));
    sendCodeModified(1);

    Serial.println(F("client disconnected"));
    //it looks like we need to wait a little to make sure the connection closes
    delay(2000);
    //client.flush();
  }
}
