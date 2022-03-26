int i_data = 134;
float f_data = 345.52;
int pirPin = 4;
int pirStat = 0;
int x[] = {0,0};
int buzzer = 5;
#include <SoftwareSerial.h>
SoftwareSerial UnoSerial(3, 2); // RX | TX
void setup()
{
  pinMode(pirPin, INPUT);
  pinMode(3, INPUT);
  pinMode(2, OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  UnoSerial.begin(57600);
}
void loop() {
  pirStat = digitalRead(pirPin);
  Serial.print(i_data);
  Serial.print("\t");
  Serial.println(f_data);
  x[0] = x[1];
  x[1] = pirStat;
  if ((x[0] == 0) && (x[1] == 1)) {
  UnoSerial.print(i_data);
  UnoSerial.print(" ");
  UnoSerial.print(f_data);
  UnoSerial.print("\n");
  tone(buzzer,1000);
  }
  if (pirStat == HIGH) {
    tone(buzzer,1000);
  }
  else {
    noTone(buzzer);
  }
 }
  