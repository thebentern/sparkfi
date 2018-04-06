#include <ESP8266WebServer.h>

void initializeServer() 
{
  server.on("/", handleRoot);
  server.on("/spark", handleSpark);  
  server.onNotFound(handleNotFound);
  server.begin();

  Serial.println("Web server started");
}

void handleRoot()
{
  logRequest("200 - Index");
  server.send(200, "text/html", getHtml());
}

void handleSpark() 
{
  logRequest("200 - Spark");
  for (int i = 0; i < server.args(); i++ ) 
  {
    Serial.print(server.argName(i));
    Serial.println(server.arg(i));      
  }
  Serial.println(server.arg('channels'));
  sendOK();
}

void handleNotFound() 
{
  logRequest("404 - Not found");
  server.send(404, "text/plain", "404 Not found");
}

void sendOK()
{
  server.sendHeader("Connection", "close");
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", "OK\r\n");
}

void logRequest(String message) 
{
  Serial.println(message);
  
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
  digitalWrite(LED_BUILTIN, HIGH);
}