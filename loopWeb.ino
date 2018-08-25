void loopWeb() {

	// listen for incoming clients----
	EthernetClient client = server.available();




	// avoid printing this as it just fills up the terminal window
	//Serial.println("LoopWeb");
	//Serial.println(client.status());

	if (client) {
		resetWebVariables();
		processOneClient(client);
		// close the connection:
		//it looks like we need to wait a little to make sure the connection closes
		delay(200);
		//client.flush();

		
		client.stop();
		//SendIRCode();

		Serial.println(F("client disconnected"));
		
		NoClientMessageSent = false;
	}
	else {
		if (NoClientMessageSent == false) {
			Serial.println(F("No Client"));
			NoClientMessageSent = true;
		}
	}
}
