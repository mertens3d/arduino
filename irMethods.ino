// Stores the code for later playback
// Most of this code is just logging



void storeCodeModified(decode_results *results) {
  Serial.println(F(""));
  Serial.println(F("----------------------------------------------storeCodeModified"));
  codeLen = results->rawlen - 1;

  // To store raw codes:
  // Drop first value (gap)
  // Convert from ticks to microseconds
  // Tweak marks shorter, and spaces longer to cancel out IR receiver distortion
  Serial.println("");
  for (int i = 1; i < codeLen; i++) {
    if (i % 2) {
      // Mark
      rawCodes[i - 1] = results->rawbuf[i] * USECPERTICK - MARK_EXCESS;
      Serial.print(F(".m")); //M
    }
    else {
      // Space
      rawCodes[i - 1] = results->rawbuf[i] * USECPERTICK + MARK_EXCESS;
      Serial.print(F(".s")); //S
    }
    Serial.print(rawCodes[i - 1], DEC);
  }

}


