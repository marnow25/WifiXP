#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../Project/class/Logger.cpp"

using namespace std;

TEST_CASE("Logger test prepare response", "[prepareResponse]") {
    Logger& logger = Logger::GetInstance();
    char* log = (char *)"TEST";
    char* expectedAnswer = (char *) malloc(400);
    expectedAnswer =(char *)"<!DOCTYPE html> <script> function showHide(id) {var x = document.getElementById(id);if (x.style.display === \"none\") {  x.style.display = \"block\";} else {  x.style.display = \"none\";}}</script>  <html> <body> <h1>WiFi Searcher</h1> <div id=\"wifi\">TEST</div> </body> </html>";
    const char* logsFromServer = logger.prepareResponse(log);
    // cout<< expectedAnswer << endl << logsFromServer;
    REQUIRE(strcmp(expectedAnswer,logsFromServer) == 1);
}

TEST_CASE("Logger test start logging", "[startLogging]") {
    Logger& logger = Logger::GetInstance();
    char* expectedAnswer = (char *)"<div>Number of networks detected: 1<button onclick=\"showHide('0')\">Details</button><div style=\"display:none\" id=\"0\">";
    logger.startLogging(1);
    REQUIRE(strcmp(expectedAnswer, logger.getLogs()) == 0);
}

TEST_CASE("Logger test add new WiFi", "[addNewWifi]") {
    Logger& logger = Logger::GetInstance();
    char* name = (char *)"WIFI_NAME";
    char* strength = (char *)"WIFI_STRENGTH";
    bool isOpen = true;
    char* expectedAnswer = (char *)"<div>Number of networks detected: 1<button onclick=\"showHide('0')\">Details</button><div style=\"display:none\" id=\"0\">Network name: WIFI_NAME |Signal strength: WIFI_STRENGTH |Network not secured with password<br>\n";
    logger.addNewWifi(name, strength, isOpen);
    REQUIRE(strcmp(expectedAnswer, logger.getLogs()) == 0);
}

TEST_CASE("Logger test end logging", "[endLogging]") {
    Logger& logger = Logger::GetInstance();
    char* expectedAnswer = (char *)"<div>Number of networks detected: 1<button onclick=\"showHide('0')\">Details</button><div style=\"display:none\" id=\"0\">Network name: WIFI_NAME |Signal strength: WIFI_STRENGTH |Network not secured with password<br>\n""</div></div>";
    logger.endLogging();
    //cout<< expectedAnswer << endl << logger.getLogs();
    REQUIRE(strcmp(expectedAnswer, logger.getLogs()) == 0);
}

TEST_CASE("Logger test clear logs", "[clearLogs]") {
    Logger& logger = Logger::GetInstance();
    logger.addNewWifi("WIFI_NAME", "WIFI_STRENGTH", true); //setup
    char* expectedAnswer = (char *)"";
    logger.clearLogs();
    REQUIRE(strcmp(expectedAnswer, logger.getLogs()) == 0);
}