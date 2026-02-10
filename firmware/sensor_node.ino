// Firmware for environmental sensing using ESP32
// Intended for integration with an edge-based monitoring system

#include <DHT.h>

#define SENSOR_PIN 4
#define SENSOR_TYPE DHT22

DHT sensor(SENSOR_PIN, SENSOR_TYPE);

void setup() {
  Serial.begin(115200);
  sensor.begin();
}

void loop() {
  float temperatureValue = sensor.readTemperature();
  float humidityValue = sensor.readHumidity();

  if (isnan(temperatureValue) || isnan(humidityValue)) {
    Serial.println("Sensor data unavailable");
    delay(3000);
    return;
  }

  Serial.print("Temperature Reading: ");
  Serial.print(temperatureValue);
  Serial.print(" C | Humidity Reading: ");
  Serial.print(humidityValue);
  Serial.println(" %");

  delay(6000); // controlled sampling interval
}
