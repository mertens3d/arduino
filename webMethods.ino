
char readClient(EthernetClient client){
    char c = ' ';
    if (client.available()) {
        c = client.read();
    }
    return c;
}



void loopWeb(){
    // listen for incoming clients
    EthernetClient client = server.available();

    if (client) {
        Serial.println("new client");
        // an http request ends with a blank line
        initForNewSetOfRaw();
        readRequest(client);
        convertCurrentRequestToRawCode();

        // give the web browser time to receive the data
        delay(1);


        drawHtml(client);

        // close the connection:
        client.stop();
        Serial.println("client disconnected");
    }
}
void drawHtml(EthernetClient client){
    Serial.println("drawHtml " + String(codeLen));
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");  // the connection will be closed after completion of the response
    //client.println("Refresh: 5");  // refresh the page automatically every 5 sec
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<body>");

    for (int idx = 0; idx < codeLen; ++idx){
        //client.println(String(rawCodes[idx]) + "<br />");
        Serial.println(String(rawCodes[idx]));
        client.println(String(rawCodes[idx]));
    }
    client.println("done<br />");
    client.println("</body>");
    client.println("</html>");

    sendCode(1);

}
