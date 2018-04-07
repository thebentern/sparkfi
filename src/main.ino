#include <ESP8266WebServer.h>
#include <WifiClient.h>

// Wemos D1 Mini pin mappings
// A poor man's dictionary, because everybody is broke in low level C++
const int PIN_MAPPINGS[] = { 0, D1, D2, D3, D4, D5, D6, D7, D8 };

ESP8266WebServer server(80);

void setup() 
{
  Serial.begin(9600);
  Serial.setDebugOutput(true);
  initializePinOutputs();
  deactivatePins();
  
  initializeWifi();
  initializeServer();
}

void loop() 
{
  server.handleClient();
}

void initializePinOutputs()
{
  pinMode(LED_BUILTIN, OUTPUT);

  for (int i = 1; i < 9; i++ ) 
  {
    pinMode(PIN_MAPPINGS[i], OUTPUT);
  }
}

void deactivatePins()
{
  digitalWrite(LED_BUILTIN, HIGH);
  
  for (int i = 1; i < 9; i++ ) 
  {
    digitalWrite(PIN_MAPPINGS[i], HIGH);
  }
}