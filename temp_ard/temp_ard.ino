#include <ArduinoJson.h>
#include <SoftwareSerial.h>

SoftwareSerial s(5,6);
#include "DHT.h"
#define DHTPIN 7     
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  s.begin(115200);
  dht.begin();
}
StaticJsonBuffer<1000> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();
void loop() {
 
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if(isnan(h) || isnan(t)) {
    return;
  }
  
  root["temp"] = t;
  root["hum"] = h;
 
if(s.available()>0)
{
 root.printTo(s);
}
}
