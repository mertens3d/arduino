void drawRawCodesToSerial() {
  Serial.print (F("Debug rawCodes length: "));
  Serial.println (codeLen);
  for (int idx = 0; idx < codeLen; ++idx) {
    Serial.print( rawCodes[idx], DEC);
    Serial.print(F("."));
  }
}

