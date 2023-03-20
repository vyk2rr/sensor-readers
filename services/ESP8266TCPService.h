#include <ESP8266HTTPClient.h> 

class TCPService {
  public:
  WiFiClient client;

  TCPService(char* host, uint16_t port) {
    Serial.println("creating client instance for " + String(host) + ":" + String(port));
    while (!client.connect(host, port)) {
      Serial.println("ERROR: TCPService::WiFiClient.client failed to create connect (" + String(host) + ":" + String(port) + ") instance (waiting 10 seconds)");
      delay(10000);
    }
  }

  bool isConnected() {
    return client.connected();
  }
};
