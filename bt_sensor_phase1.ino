#include "BluetoothSerial.h"
#include "DHT.h"

#define DHTPIN 5
#define DHTTYPE DHT22

BluetoothSerial SerialBT;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Helvetinkone");
  dht.begin();
  Serial.println("Helvetinkone up and running!");
}

void loop() {
  float temp, humidity;
  measureSensorData(&temp, &humidity);
  reportSensorData(temp, humidity);
  delay(10000);
}

void measureSensorData(float *temp, float *humidity){
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("No sensor data available!");
    return;
  }

  *temp = t;
  *humidity = h;
}

void reportSensorData(float temp, float humidity){
  Serial.print("Ilmankosteus: "); Serial.print(temp); Serial.println("%  ");
  Serial.print("Lämpötila: "); Serial.print(humidity); Serial.println("°C");

  SerialBT.print("Ilmankosteus: ");  SerialBT.print(humidity); SerialBT.println("%  ");
  SerialBT.print("Lämpötila: ");  SerialBT.print(temp); SerialBT.println("°C");
}
