#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "FS.h"

#include "class/Logger.cpp"
#include "class/Connector.cpp"

ESP8266WebServer server(80);

Logger &logger = Logger::GetInstance();
Connector connector;

void handleRoot() {
    String s;
    bool ret;
    logger.clearLogs();
    int numberOfNetworks = WiFi.scanNetworks();
    logger.startLogging(numberOfNetworks);
        for (int i = 0; i < numberOfNetworks; i++) {
          String password = String(WiFi.encryptionType(i));
          if (password == "7") {
            ret = true;
          } else {
            ret = false;
          }
          String rssi = String(WiFi.RSSI(i));
          logger.addNewWifi(WiFi.SSID(i).c_str(), rssi.c_str(), ret);
        }
    logger.endLogging();
    s = logger.getLogs();
    server.send(200, "text/html", logger.prepareResponse((const char *) s.c_str()));
    logger.clearLogs();
}


void handlePing() {
  String res;
  bool connection = connector.ping();
  Serial.println(connection);
  if(connection == true) {
    res = "WiFi connected to Internet";
  }
  else {
    res = "WiFi not connected to Internet";
  }
  
  server.send(200, "text/html", res.c_str());
}


void setup() {
    const char *ssid = "WIFI networks scanner";
    const char *password = "";

    IPAddress localIp(192, 168, 1, 1);
    IPAddress gateway(192, 168, 1, 1);
    IPAddress subnet(255, 255, 255, 0);

    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    
    Serial.begin(9600);
    delay(100);
    Serial.println("START");
    Serial.println("Configuring access point...");

    WiFi.softAP(ssid, password);
    WiFi.softAPConfig(localIp, gateway, subnet);

    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
    server.on("/", handleRoot);
    server.on("/ping", handlePing);
    server.begin();
    Serial.println("HTTP server started");
}

void loop() {
    server.handleClient();
}
