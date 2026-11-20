```cpp
#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

// WiFi Credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

// Relay Pin
#define RELAY D1

// Create KiwisIoT Object
KiwisIoT kiwisiot(ssid, pass, topic);

// Relay Control Function
void onControl(String ch, String val) {

  Serial.print("Channel: ");
  Serial.println(ch);

  Serial.print("Received Value: ");
  Serial.println(val);

  // Relay Control - Channel 1
  if (ch == "1") {

    if (val == "1") {
      digitalWrite(RELAY, LOW);
      Serial.println("RELAY ON");
    }

    else if (val == "0") {
      digitalWrite(RELAY, HIGH);
      Serial.println("RELAY OFF");
    }
  }
}

void setup() {

  Serial.begin(115200);

  // Configure Relay Pin
  pinMode(RELAY, OUTPUT);

  // Keep Relay OFF Initially
  digitalWrite(RELAY, HIGH);

  // Initialize KiwisIoT
  kiwisiot.begin();

  // Receive Cloud Commands
  kiwisiot.onReceive(onControl);

  Serial.println("ESP8266 IoT Relay Control Started");
}

void loop() {

  // Maintain Cloud Communication
  kiwisiot.run();
}
```
