#include <ArduinoJson.h>
#include <DHT_U.h>
#include <DHT.h>
#include <SoftwareSerial.h>

#define registro 7
DHT dht(registro,DHT11);
SoftwareSerial s(5,6);
void setup() {
  s.begin(9600);
  dht.begin();
}
  

void loop(){
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  root["temp"] = temp;
  root["hum"] = hum;
  int data=50;
  if(s.available()>0)
  {
//   s.write(datos.c_str());
     root.printTo(s);
  }
  delay(5000);
}
