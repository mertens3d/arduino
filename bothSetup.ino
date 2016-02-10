
void setupEthernet(){
    // start the Ethernet connection and the server:
    Ethernet.begin(mac, ip);
    server.begin();
    Serial.print("server is at ");
    Serial.println(Ethernet.localIP());
}
void setupIr()
{
    // Serial.println("RAWBUF = " + RAWBUF);
    irrecv.enableIRIn(); // Start the receiver
    pinMode(BUTTON_PIN, INPUT);
    pinMode(STATUS_PIN, OUTPUT);
}