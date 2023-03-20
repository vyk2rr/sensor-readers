class MoistureReaderService {
  public: 
  struct Reading {
    String moisture; // a string from 0 to 100 plus the % symbol (e.g., "10%")
    String analog_read;  // 0 - 1024 
  };

  int MOISTURE_PIN;

  MoistureReaderService() {}
  MoistureReaderService(int moisture_pin) {
    MOISTURE_PIN = moisture_pin;
  }

  Reading getReading() {
    // 3 readings to activate sensor
    int analog_read = analogRead(MOISTURE_PIN); // 1st
    delay(250);
    analog_read = analogRead(MOISTURE_PIN); // 2nd
    delay(250);
    analog_read = analogRead(MOISTURE_PIN); // 3rd
    delay(250);
    analog_read = analogRead(MOISTURE_PIN); // 4th (final value)

    String moisture = String(analog_read * 100 / 1024) + "%";

    Reading reading;
    reading.moisture = moisture;
    reading.analog_read = String(analog_read);

    return reading;
  }
};