#include <TridentTD_LineNotify.h>
#define BLYNK_TEMPLATE_ID           "TMPLdmGnBfK2"
#define BLYNK_DEVICE_NAME           "Change Password"
#define BLYNK_AUTH_TOKEN            "N9kpAFOTgbSTTaDGjYYLos_cDcZeWBCS"
#define SSID        "Earn something"
#define PASSWORD    "pqwsalmzx"
#define LINE_TOKEN  "bwzvpUkIGDi59q4Wky4ySq1G03hOs4u8dIXeBHgc1mE"
#include <SoftwareSerial.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Earn something";
char pass[] = "pqwsalmzx";
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
  Blynk.begin(auth, ssid, pass);
}
BLYNK_WRITE(V4)
{
  String password = param.asStr();
  
  NodeSerial.print(password);
  NodeSerial.print('\n');
  Serial.println(password);
}
void loop() {
  Blynk.run();
  if (NodeSerial.read() == '\n')
  {
    LINE.notify("*** ALARM ***");
    delay(2000);
  }
}
