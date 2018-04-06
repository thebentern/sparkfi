#include <ESP8266WebServer.h>
#include <WifiClient.h>

ESP8266WebServer server(80);

void setup() 
{
  Serial.begin(9600);
  Serial.setDebugOutput(true);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  
  initializeWifi();
  initializeServer();
}

void loop() 
{
  server.handleClient();
}