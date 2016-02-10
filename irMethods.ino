// Stores the code for later playback
// Most of this code is just logging



void storeCode(decode_results *results) {

  codeType = UNKNOWN;// results->decode_type;
  //  int count = results->rawlen;
  if (codeType == UNKNOWN) {
    Serial.println(F("Received unknown code, saving as raw"));
    codeLen = results->rawlen - 1;
    // To store raw codes:
    // Drop first value (gap)
    // Convert from ticks to microseconds
    // Tweak marks shorter, and spaces longer to cancel out IR receiver distortion
    Serial.println("");
    for (int i = 1; i <= codeLen; i++) {
      if (i % 2) {
        // Mark
        irRawCodesAr[i - 1] = results->rawbuf[i] * USECPERTICK - MARK_EXCESS;
        Serial.print(F(".")); //M
      }
      else {
        // Space
        irRawCodesAr[i - 1] = results->rawbuf[i] * USECPERTICK + MARK_EXCESS;
        Serial.print(F(".")); //S
      }
      Serial.print(irRawCodesAr[i - 1], DEC);
    }
    Serial.println("");
    Serial.println("");
  }

  Serial.println(results->value);
  Serial.println(results->value, HEX);
  codeValue = results->value;
  codeLen = results->bits;
  Serial.println("codeLen " + codeLen);
}
bool checkForPeriodHit(char oneChar) {
  if (oneChar == '.') {
    if (irRawCodesArMaxIdx < 1000) {
      //Serial.println(F("period hit"));

    }
    return true;
  }
  return false;
}
bool checkForCharHit(char oneChar) {
  if (isDigit(oneChar)) {
    //Serial.print(F("input "));
    //Serial.println (String(oneChar));// + Stri
    // convert the incoming byte to a char
    // and add it to the string:
    unsigned long inInt = 0;
    inInt = atoi(&oneChar); //-44
    //Serial.println("Converted to int " + itoa(&inInt));
    unsigned long newValue = irRawCodesAr[irRawCodesArMaxIdx];
    //Serial.println("A previous newValue " + String(newValue));
    newValue = newValue * 10;
    //Serial.println("B newValue " + String(newValue));
    newValue = newValue + inInt;
    //Serial.println("C newValue " + String(newValue));
    irRawCodesAr[irRawCodesArMaxIdx] = newValue;
    //Serial.println(String(irRawCodesAr[irRawCodesArMaxIdx]) + " ");// + String(irRawCodesAr[irRawCodesArMaxIdx]));
    return true;
  }
  return false;
}

void convertCurrentRequestToCharArray() {
  //Serial.print(F("(s) convertCurrentRequestToCharArray queryCharArCurrentMaxIdx: "));
  //Serial.println(queryCharArCurrentMaxIdx);
  irRawCodesArMaxIdx = 0;

  for (int idx = 0; idx < queryCharArCurrentMaxIdx; idx++)
  {
    char oneChar = queryCharArray[idx];
    //Serial.print(oneChar);
    if (checkForPeriodHit(oneChar) == false) {
      bool isChar = checkForCharHit(oneChar);
      if (isChar == false) {
        break; //for loop
      }
    } else {
      irRawCodesArMaxIdx ++;
    }


  }
  //Serial.println("(e) convertCurrentRequestToCharArray");
}





