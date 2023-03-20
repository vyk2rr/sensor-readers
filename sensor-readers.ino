#include "services/ESP8266WiFiService.h"
#include "services/ESP8266TCPService.h"

#include "services/DHTHW507Service.h"
#include "http-helper/Dht11HttpService.h"

#include "services/MoistureReaderService.h"
#include "http-helper/MoistureHttpService.h"

#define DHT11_PIN 14
char* ssid = "";
char* password = "";
char* host = "192.168.1.239";
uint16_t port = 3000;

HW507Service hW507Service;

void setup() {
  Serial.begin(115200);

// HW507Service hW507Service(DHT11_PIN);
 WiFiService wiFiService(ssid, password);
}

void loop() {
   MoistureReaderService moistureReader(0);
   MoistureReaderService::Reading moisture_reading = moistureReader.getReading();
   Serial.println("moisture: " + moisture_reading.moisture);

  //  HW507Service::Reading dht11_reading = hW507Service.getReading(); 
  //  Serial.println("dht11_reading: " + dht11_reading.humidity);

  TCPService tcp_service(host, port);
  if (tcp_service.isConnected()){
    //  Dht11HttpService dht11_http_service(tcp_service.client, host, port);
    // int response_http_code = dht11_http_service.post_reading("/dht11s", dht11_reading);
    // if (response_http_code > 0) {
    //   String http_code = String(response_http_code);
    //   String response = String(dht11_http_service.post_response());
    //   Serial.println("Dht11HttpService posted payload(http status: " + http_code + ") with response: " + response);
    // } else {
    //   Serial.printf("[HTTP] POST... failed, error: %s\n", dht11_http_service.error_to_string());
    // }

    MoistureHttpService moisture_http_service(tcp_service.client, host, port);
    int response_http_code = moisture_http_service.post_reading("/api/moisture", moisture_reading);
    if (response_http_code > 0) {
        String http_code = String(response_http_code);
        String response = String(moisture_http_service.post_response());
        Serial.println("MoistureHttpService posted payload(http status: " + http_code + ") with response: " + response);
      } else {
        Serial.printf("[HTTP] POST... failed, error: %s\n", moisture_http_service.error_to_string());
      }
    }

    delay(6000 * 45); // wait 45 minutes for next reading
}
