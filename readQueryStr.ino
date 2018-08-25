
char requesCharLen = 0;



String readRequest(EthernetClient client){
	Serial.println(F("(s) readRequest"));
	char charMinus1 = ' ';
	char charMinus2 = ' ';
	boolean  queryStringStarted = false;
	boolean startReadHit = false;
	boolean endReadHit = false;
	queryCharArCurrentMaxIdx = 0;
	String irQueryValue = "none";

	Serial.println(F("(s) This is what is being read in"));
	Serial.println(F("client.connected() ?"));
	Serial.println(client.connected());
	

	if (client.connected()) {

		String req = client.readStringUntil('\n');
		Serial.println("yup --> " + req);
		client.flush();


		if (req.indexOf("?") > 0) {
			int irIndex = req.indexOf("ir=");
			if (irIndex > 0) {
				irQueryValue = req.substring(irIndex);
			}

			int httpIndex = irQueryValue.indexOf(" HTTP/1.1");
			if (httpIndex > 0) {
				irQueryValue = irQueryValue.substring(0,httpIndex );
			}

		}



	}

	while (false && client.connected() == true && endReadHit == false && queryCharArCurrentMaxIdx < queryCharArrayMaxChar) {
		
		

		
		
		
		char currentChar = readClient(client);
		
		Serial.println(F ("currentChar: "));
		Serial.println(String( currentChar));

		if (currentChar == '?') {
			queryStringStarted = true;
		}


		if (startReadHit == false && charMinus2 == 'i' && charMinus1 == 'r' && currentChar == '='){
			Serial.println(F("startReadHit !!!!!!!!!!!!!!!!"));
			startReadHit = true;
			continue;
		}

		if (startReadHit == true && currentChar == '&'){
			//Serial.println("endReadHit hit");
			endReadHit = true;
			break;
		}
		if (currentChar == '\n' && startReadHit == true){
			Serial.println(F("end of line hit"));
			break;
		}
		if (startReadHit){
			Serial.print(String(currentChar));
			queryCharArray[queryCharArCurrentMaxIdx] = currentChar;
			queryCharArCurrentMaxIdx += 1;
		}
		else{
			Serial.println("minus chars " + String(charMinus2) + String(charMinus1));
			charMinus2 = charMinus1;
			charMinus1 = currentChar;
		}
		
		
	}
	Serial.println(F("(e) readRequest"));

	return irQueryValue;
}
