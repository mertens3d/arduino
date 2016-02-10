
char requesCharLen = 0;



void readRequest(EthernetClient client){
    Serial.println("(s) readRequest");
    char charMinus1 = ' ';
    char charMinus2 = ' ';
    boolean startReadHit = false;
    boolean endReadHit = false;
    currentRequestMaxIdx = 0;

    while (client.connected() == true && endReadHit == false && currentRequestMaxIdx < maxChar) {
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
            Serial.println("end of line hit");
            break;
        }
        if (startReadHit){
            //Serial.println("hit - " + String(currentChar));
            requestCharAr[currentRequestMaxIdx] = currentChar;
        }
        else{
            //Serial.println("minus chars " + String(charMinus2) + String(charMinus1));
            charMinus2 = charMinus1;
            charMinus1 = currentChar;
        }
        currentRequestMaxIdx++;
        
    }
    Serial.println("(e) readRequest");
}