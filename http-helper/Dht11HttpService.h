#include <ArduinoJson.h>

class Dht11HttpService {
  public:
  HTTPClient http;
  WiFiClient CLIENT;
  char* HOST;
  uint16_t PORT;

  Dht11HttpService(WiFiClient client, char* host, uint16_t port) {
    CLIENT = client;
    HOST = host;
    PORT = port;
  }

  int response_http_code;
  int post_reading(char* path,  HW507Service::Reading params) {
    DynamicJsonDocument jsonDoc(260);

    jsonDoc["temperature"] = params.temperature; // "31.4"
    jsonDoc["humidity"] = params.humidity; // "42.0"
    jsonDoc["heat_index"] = params.hic; // "42.0"

    http.begin(CLIENT, "http://" + String(HOST) + ":" + String(PORT) + String(path)); 
    http.addHeader("Content-Type", "application/json");

    Serial.println("posting payload: " + jsonDoc.as<String>());
    response_http_code = http.POST(jsonDoc.as<String>());
    Serial.println("response_http_code: " + String(response_http_code));

    return response_http_code;
  }

  String post_response() {
    if (response_http_code == HTTP_CODE_OK) {
      return http.getString();
    } else {
      return "";
    }
  }

  String error_to_string() {
    if (response_http_code > 0) {
      return http.errorToString(response_http_code).c_str();
    }
  }
};