#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include <page.h>

const char* ssid = "Pandey's Server";//server name here
const char* password = "12345678";//password here

ESP8266WebServer server(80);

void handleRoot() {
  String html = MAIN_page;
  server.send(200,"text/html",html);
}
void setup(void)
{
  Serial.begin(9600);
  Serial.println("");
  WiFi.mode(WIFI_AP);           
  WiFi.softAP(ssid, password);  //nodemcu acting as AP

  IPAddress myIP = WiFi.softAPIP(); 
  Serial.print("HotSpt IP:");
  Serial.println(myIP);
 
  server.on("/", handleRoot);

  server.begin();       
  Serial.println("HTTP server started");
}

void loop(void)
{
  server.handleClient();
}