#include <DHT.h>
class HW507Service {
  public: 
  struct Reading {
    String humidity;
    String temperature;
    String hic;
  };

  int DHT11_PIN;

  HW507Service() {}
  HW507Service(int dht11_pin) {
    DHT11_PIN = dht11_pin;
  }

  Reading getReading() {
    DHT dht(DHT11_PIN, DHT11);
    dht.begin();

    delay(2000);

    // Reading temperature or humidity takes about 250 milliseconds!
    float humidity = dht.readHumidity();
    float temperature_celcius = dht.readTemperature();

    // Check if any reads failed and exit early (to try again).
    if (isnan(humidity) || isnan(temperature_celcius)) {
      Serial.println("ERROR: Failed to read from DHT sensor!");
      return Reading {
        humidity: "error",
        temperature: "error",
        hic: "error"
      };
    }

    // Compute heat index in Celsius (isFahreheit = false)
    float hic = dht.computeHeatIndex(temperature_celcius, humidity, false);

    Serial.println("Humidity: " + String(humidity) + "%");
    Serial.println("Temperature: " + String(temperature_celcius) + String("°C"));
    Serial.print("Heat index: " + String(hic));

    Reading reading;

    reading.humidity = String(humidity);
    reading.temperature = String(temperature_celcius);
    reading.hic = String(hic);

    return reading;
  }
};