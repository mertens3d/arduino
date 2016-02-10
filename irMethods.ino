// Stores the code for later playback
// Most of this code is just logging

int rawCodeArMaxIdx = 0;

void storeCode(decode_results *results) {

    codeType = UNKNOWN;// results->decode_type;
    //  int count = results->rawlen;
    if (codeType == UNKNOWN) {
        Serial.println("Received unknown code, saving as raw");
        codeLen = results->rawlen - 1;
        // To store raw codes:
        // Drop first value (gap)
        // Convert from ticks to microseconds
        // Tweak marks shorter, and spaces longer to cancel out IR receiver distortion
        for (int i = 1; i <= codeLen; i++) {
            if (i % 2) {
                // Mark
                rawCodes[i - 1] = results->rawbuf[i] * USECPERTICK - MARK_EXCESS;
                Serial.print(" m");
            }
            else {
                // Space
                rawCodes[i - 1] = results->rawbuf[i] * USECPERTICK + MARK_EXCESS;
                Serial.print(" s");
            }
            Serial.print(rawCodes[i - 1], DEC);
        }
        Serial.println("");
    }

    Serial.println(results->value);
    Serial.println(results->value, HEX);
    codeValue = results->value;
    codeLen = results->bits;

}

void convertCurrentRequestToRawCode(){
    Serial.println("(s) convertCurrentRequestToRawCode");
    rawCodeArMaxIdx = 0;

    for (int idx = 0; idx < currentRequestMaxIdx; idx++)
    {
        char oneChar = requestCharAr[idx];
        Serial.print(oneChar);
        if (oneChar == '.'){
            rawCodeArMaxIdx++;
            codeLen += 1;
            return;
        }

        if (isDigit(oneChar)) {
            // convert the incoming byte to a char
            // and add it to the string:
            int inInt = oneChar - 0;
            rawCodes[rawCodeArMaxIdx] = (rawCodes[rawCodeArMaxIdx] * 10) + inInt;
            Serial.println(oneChar + " -> " + String(rawCodes[rawCodeArMaxIdx]));
        }
    }
    Serial.println("(e) convertCurrentRequestToRawCode");
}

void initForNewSetOfRaw(){
    rawCodeArMaxIdx = 0;
}

void loopIrB() {
    int buttonState = digitalRead(BUTTON_PIN);
    // Serial.println("buttonState = " + String(buttonState));
    if (lastButtonState == HIGH && buttonState == LOW) {
        Serial.println("Released");
        irrecv.enableIRIn(); // Re-enable receiver
    }
    if (buttonState) {
        Serial.println("Pressed b, sending");
        digitalWrite(STATUS_PIN, HIGH);

        sendCode(lastButtonState == buttonState);
        digitalWrite(STATUS_PIN, LOW);
        delay(50); // Wait a bit between retransmissions
    }

    else if (irrecv.decode(&results)) {

        digitalWrite(STATUS_PIN, HIGH);
        storeCode(&results);
        irrecv.resume(); // resume receiver
        digitalWrite(STATUS_PIN, LOW);

    }
    lastButtonState = buttonState;
    Serial.println("(e) loopIrB");
}



void sendCode(int repeat) {


    // (codeType == UNKNOWN /* i.e. raw */) {
    // Assume 38 KHz
    irsend.sendRaw(rawCodes, codeLen, 38);
    // Serial.println("Sent raw" + rawCodes);
    // }
}

