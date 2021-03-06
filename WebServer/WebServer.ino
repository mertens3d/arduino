#include <ir_Lego_PF_BitStreamEncoder.h>
#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>

#include <SPI.h>
#include <Ethernet.h>


/*
  Web Server

  A simple web server that shows the value of the analog input pins.
  using an Arduino Wiznet Ethernet shield.

  Circuit:
  * Ethernet shield attached to pins 10, 11, 12, 13
  * Analog inputs attached to pins A0 through A5 (optional)

  created 18 Dec 2009
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe

  */

int queryCharArCurrentMaxIdx = 0;
const int queryCharArrayMaxChar = 400;
char queryCharArray[queryCharArrayMaxChar];




int codeLen; // The length of the code
int codeType = -1; // The type of code
int queryNumGroups = 0;

bool NoClientMessageSent = false;

int RECV_PIN = 6;//11;
int STATUS_PIN_B = 8;
int STATUS_PIN = 13;
int toggle = 0; // The RC5/6 toggle state
unsigned int rawCodes[RAWBUF]; // The durations if raw
unsigned long int codeValue; // The code value if not raw
int queryNumberGroupMaxIdx = 0;

IRrecv irrecv(RECV_PIN);
IRsend irsend;
decode_results results;

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 130);
EthernetServer server(80);

void setup() {
    Serial.begin(9600);
    setupEthernet();
    setupIr();
}
void loop() {
   //loopIrB();
   loopWeb();
}
