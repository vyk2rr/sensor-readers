# Soil Monitoring System for ESP8266

### Overview

This project aims to provide a simple and efficient solution for monitoring and logging soil moisture, temperature, and humidity levels using an ESP8266 microcontroller. The sensor data is sent to a server via HTTP POST requests, allowing for easy integration with data logging and visualization tools.

### Understanding the Code

This code is designed to run on an ESP8266 microcontroller and is meant to read data from two sensors, a DHT11 temperature and humidity sensor, and a soil moisture sensor. It then sends the readings to a server using HTTP POST requests. The code is divided into several classes, which I'll break down below.

1. **`HW507Service`**: This class is responsible for reading data from the DHT11 temperature and humidity sensor.
2. **`MoistureReaderService`**: This class is responsible for reading data from the soil moisture sensor.
3. **`TCPService`**: This class is responsible for establishing and maintaining a TCP connection to the server.
4. **`Dht11HttpService`**: This class is responsible for sending the DHT11 sensor readings to the server using HTTP POST requests.
5. **`MoistureHttpService`**: This class is responsible for sending the soil moisture sensor readings to the server using HTTP POST requests.
6. **`WiFiService`**: This class is responsible for connecting the ESP8266 to a Wi-Fi network.

In the **`setup()`** function of the main file, the Wi-Fi connection is established by creating an instance of the `WiFiService` class. In the **`loop()`** function, the following steps are performed:

1. A **`MoistureReaderService`** object is created, and the soil moisture reading is taken.
2. A **`TCPService`** object is created, which establishes a connection to the server.
3. If the connection to the server is successful, a **`MoistureHttpService`** object is created, and the soil moisture reading is sent to the server using an HTTP POST request.
4. The result of the HTTP POST request is printed to the serial monitor.
5. The program waits for 45 minutes (2700000 milliseconds) before taking the next reading.

The code also includes commented-out sections related to the DHT11 sensor, which are not currently being used.

To fully understand this code, you should familiarize yourself with the following concepts:

1. The ESP8266 microcontroller and the Arduino programming environment.
2. The DHT11 temperature and humidity sensor, and how it works.
3. The soil moisture sensor, and how it works.
4. The basics of TCP and HTTP, and how HTTP POST requests are used to send data to a server.
5. The ArduinoJson library, which is used to create JSON payloads for the HTTP POST requests.

With a grasp of these concepts, you'll have a better understanding of how this code works and how the various components interact.
