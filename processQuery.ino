
bool checkForPeriodHit(char oneChar) {
  if (oneChar == '.') {
    if (queryNumberGroupMaxIdx < 1000) {
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
    unsigned long newValue = rawCodes[queryNumberGroupMaxIdx];
    //Serial.println("A previous newValue " + String(newValue));
    newValue = newValue * 10;
    //Serial.println("B newValue " + String(newValue));
    newValue = newValue + inInt;
    //Serial.println("C newValue " + String(newValue));
    rawCodes[queryNumberGroupMaxIdx] = newValue;

    return true;
  }
  return false;
}

void convertCurrentRequestToCharArray() {
  //Serial.print(F("(s) convertCurrentRequestToCharArray queryCharArCurrentMaxIdx: "));
  //Serial.println(queryCharArCurrentMaxIdx);
  queryNumberGroupMaxIdx = 0;

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
      Serial.println(String(queryNumberGroupMaxIdx) + " " + String(rawCodes[queryNumberGroupMaxIdx]));
      queryNumberGroupMaxIdx ++;
    }
  }
  //last one
  Serial.println(String(queryNumberGroupMaxIdx) + " " + String(rawCodes[queryNumberGroupMaxIdx]));
  //Serial.println("(e) convertCurrentRequestToCharArray");
}



