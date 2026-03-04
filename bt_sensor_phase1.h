#define DHTPIN 5
#define DHTTYPE DHT22

void loop();
void measureSensorData(float *temp, float *humidity);
void reportSensorData(float temp, float humidity);