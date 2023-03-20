#include <ESP8266WiFi.h> 
class WiFiService {
  public: 
  WiFiService(char* ssid, char* password) {
    WiFi.mode(WIFI_STA);

    Serial.print("Connecting to ssid: " + String(ssid));

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(2000);
    }

    Serial.println("WiFi connected!");
    Serial.println("WiFi.localIP(): ");
    Serial.print(WiFi.localIP());
    Serial.println("");
  }
};