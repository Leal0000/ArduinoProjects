#include <DHT.h>
#include <DHT_U.h>

#define registro 05
DHT dht(registro,DHT11);



void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  

  Serial.print(String(temp));
  Serial.println("°");
  Serial.print(String(hum));
  Serial.println("%");
  delay(1000);

}
