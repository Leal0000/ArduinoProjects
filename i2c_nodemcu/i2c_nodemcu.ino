#include <ArduinoJson.h>
#include <SoftwareSerial.h>
 
SoftwareSerial s(12,14);
String  data;
void setup() {
s.begin(9600);
Serial.begin(9600);
}
 
void loop() {
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(s);
  /*s.write("s");
  if (s.available()>0)
  {
    data=s.read();
    Serial.println(data);
  }*/
   if (root != JsonObject::invalid())
  {
      Serial.println("JSON received and parsed");
      root.prettyPrintTo(Serial);
      Serial.println("");
      Serial.print("Temperature ");
      float data1=root["temp"];
      Serial.println(data1);
      Serial.print("Humidity    ");
      float data2=root["hum"];
      Serial.println(data2);
      Serial.print("Heat-index  ");
      Serial.println("");
      Serial.println("---------------------xxxxx--------------------");
      Serial.println("");
  }
  //Print the data in the serial monitor

  //if(s.available() > 0){
       
//}
  
}
