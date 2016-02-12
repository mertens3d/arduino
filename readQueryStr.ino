
char requesCharLen = 0;



void readRequest(EthernetClient client){
    Serial.println(F("(s) readRequest"));
    char charMinus1 = ' ';
    char charMinus2 = ' ';
    boolean startReadHit = false;
    boolean endReadHit = false;
    queryCharArCurrentMaxIdx = 0;
 

    Serial.println(F("(s) This is what is being read in"));
    
    while (client.connected() == true && endReadHit == false && queryCharArCurrentMaxIdx < queryCharArrayMaxChar) {
        char currentChar = readClient(client);
     

        if (startReadHit == false && charMinus2 == 'i' && charMinus1 == 'r' && currentChar == '='){
            //Serial.println("startReadHit !!!!!!!!!!!!!!!!");
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
            //Serial.println("minus chars " + String(charMinus2) + String(charMinus1));
            charMinus2 = charMinus1;
            charMinus1 = currentChar;
        }
        
        
    }
    Serial.println(F("(e) readRequest"));
}
