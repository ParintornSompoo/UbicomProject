#include <TridentTD_LineNotify.h>
#define SSID        "Earn something"
#define PASSWORD    "pqwsalmzx"
#define LINE_TOKEN  "bwzvpUkIGDi59q4Wky4ySq1G03hOs4u8dIXeBHgc1mE"
#include <SoftwareSerial.h>
SoftwareSerial NodeSerial(D2, D3); // RX | TX
void setup() {
  pinMode(D2, INPUT);
  pinMode(D3, OUTPUT);
  Serial.begin(9600);
  NodeSerial.begin(57600);
  Serial.println();
  Serial.println(LINE.getVersion());
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while(WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(400); }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP()); 
  LINE.setToken(LINE_TOKEN);
}
void loop() {
  if (NodeSerial.read() == '\n')
  {
    LINE.notify("*** ALARM ***");
    delay(2000);
  }
}
