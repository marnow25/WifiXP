#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "FS.h"

#include "class/Logger.cpp"
#include "class/Connector.cpp"
#include "class/IConnect.cpp"
#include "class/IPSplitter.cpp"

ESP8266WebServer server(80);

Logger &logger = Logger::GetInstance();
Connector connector;

void handleRoot() {
    String s;
    logger.clearLogs();
    int numberOfNetworks = WiFi.scanNetworks();
    logger.startLogging(numberOfNetworks);
        for (int i = 0; i < numberOfNetworks; i++) {
          bool ret = false;
          String rssi = String(WiFi.RSSI(i));
          logger.addNewWifi(WiFi.SSID(i).c_str(), rssi.c_str(), ret);
        }
    logger.endLogging();
    s = logger.getLogs();
    server.send(200, "text/html", logger.prepareResponse((const char *) s.c_str()));
    logger.clearLogs();
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
    Serial.println("START");
    Serial.println("Configuring access point...");

    WiFi.softAP(ssid, password);
    WiFi.softAPConfig(localIp, gateway, subnet);

    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
    server.on("/", handleRoot);
    server.begin();
    Serial.println("HTTP server started");
}

void loop() {
    server.handleClient();
    for (int i = 0; i < 10; i++) {
        delay(1000);
        server.handleClient();
    }
}
