#include <Arduino.h>
#include <AltSoftSerial.h>

AltSoftSerial hm10Serial;
String data = "";

void setup() {
  Serial.begin(115200);
  hm10Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  randomSeed(analogRead(A1));
}

void loop() {
  // check if there is data from HM10
  if (hm10Serial.available()) {
    data = hm10Serial.read();

    Serial.print(F("Data Received: "));
    Serial.println(data);
  }

  if (Serial.available()) {
    data = String(random(1024));

    Serial.print(F(">Data Sent: "));
    Serial.println(data);
  }

  delay(500);
}