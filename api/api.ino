#include <ESP8266WiFi.h>
const char* ssid = "";
const char* password = "";
char server[] = "heroku-flas.herokuapp.com";
String user = "pedro";
String pass = "cualquiera";
WiFiClient client;
void setup() {
  delay(10);
  Serial.begin(9600);

  WiFi.begin(ssid, password);

  Serial.print("Conectando");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println(".");
  }

  Serial.print("Conexion exitosa, Tu ip es:");
  Serial.println(WiFi.localIP());
}

void loop() {
  if(!client.connect(server, 80)){
    Serial.println("Falla en la conexion");
  }
  else{
    String data = "user=gera&password=12345"; 
    if(client.connect(server, 80)){
        client.println("POST /arduino HTTP/1.1");
        client.println("Host: heroku-flas.herokuapp.com");
        client.println("User-Agent: ESP8266WiFi/1.1");
        client.println("Content-Type: application/x-www-form-urlencoded");
        client.print("Content-Length: ");
        client.print(data.length());
        Serial.println(data.length());
        client.print("\n\n");
        client.print(data);
        Serial.println("Datos guardados");
    }
  }
    client.stop();
    delay(2000);

  /*
  if(WiFi.status() == WL_CONNECTED){
    HTTPClient http;
    WiFiClient client;
    String data = "?user=" + user + "&password=" + pass;
    http.begin(wifiClient,"https://heroku-flas.herokuapp.com/user");
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    int codigo = http.POST(data);

    if(codigo > 0){
      Serial.println("Codigo HTTP:" + String(codigo));
      if(codigo == 200){
        String cuerpo = http.getString();
        Serial.println("El servidor respondio");
        Serial.println(cuerpo);
      }
    }
    else{
       Serial.println("Error Enviando el codigo");
       
    }

    http.end();

  }
  else{
    Serial.println("Error en la conexion WIFI");
  }
  delay(2000);
  */
  
}
