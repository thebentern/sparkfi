#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#define SSID      "SparkFi"
#define PASSWORD  "spark"

void initializeWifi() 
{
  WiFi.begin(SSID, PASSWORD);

  while(WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.println(""); 
    Serial.printf("Attempting to connect to %s...", SSID);
  }
  Serial.println(""); 
  Serial.println("Connected to "); 
  Serial.println(SSID);
  Serial.println("With IP address ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("SparkFi")) 
  {
    Serial.println("mDNS broadcasting name SparkFi");
  }
  else 
  {
    Serial.println("mDNS broadcast failed");
  }
}
