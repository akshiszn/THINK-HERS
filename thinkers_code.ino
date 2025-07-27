#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "shanthanik";
const char* password = "password123";

WebServer server(80);
const int relayPins[4] = {5, 18, 19, 21};

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 4; i++) {
    pinMode(relayPins[i], OUTPUT);
    digitalWrite(relayPins[i], LOW);
  }

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.println("\nConnected: " + WiFi.localIP().toString());

  // API endpoint instead of HTML
  server.on("/control", handleControl);
  server.begin();
}

void loop() {
  server.handleClient();
}

void handleControl() {
  if (server.hasArg("relay") && server.hasArg("state")) {
    int r = server.arg("relay").toInt();
    String state = server.arg("state");

    if (r >= 1 && r <= 4) {
      digitalWrite(relayPins[r - 1], state == "on" ? HIGH : LOW);
       } else {
       server.send(204, "text/plain", "");
    }
  } 
}