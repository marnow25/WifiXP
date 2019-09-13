#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../Project/class/Logger.cpp"

using namespace std;

TEST_CASE("Logger test prepare response", "[prepareResponse]") {
    Logger& logger = Logger::GetInstance();
    char* log = (char *)"TEST";
    char* expectedAnswer = (char *) malloc(400);
    expectedAnswer =(char *)"<!DOCTYPE html>"
	"<script> function showHide(id)"
	"{var x = document.getElementById(id);"
	"if (x.style.display === \"none\")"
	"{  x.style.display = \"block\";}"
	"else {  x.style.display = \"none\";}}"
	"</script>"
	"<html>"
	"<body>"
	"<h1>WIFI Networks Scanner</h1>"
	"<div id=\"WIFI\">TEST</div>"
	"</body>"
	"</html>";
    char* logsFromServer = (char *) malloc(400);
	logsFromServer = (char*)logger.prepareResponse(log);
    //cout<<"expectedAnswer:"<< endl << expectedAnswer << endl;
	//cout<<"logsFromServer: "<< endl << logsFromServer << endl;
    REQUIRE(strcmp(expectedAnswer,logsFromServer) == 0);
}

TEST_CASE("Logger test start logging", "[startLogging]") {
    Logger& logger = Logger::GetInstance();
    char* expectedAnswer = (char *)"<div>Networks detected: 1"
	"<button onclick=\"showHide('0')\">Details</button>"
	"<div style=\"display:none\" id=\"0\">";
	//cout<<"expectedAnswer: "<< endl << expectedAnswer << endl;
    logger.startLogging(1);
	//cout<<"logsFromServer: "<< endl << logger.getLogs() << endl;
    REQUIRE(strcmp(expectedAnswer, logger.getLogs()) == 0);
}

TEST_CASE("Logger test add new WiFi", "[addNewWifi]") {
    Logger& logger = Logger::GetInstance();
    char* name = (char *)"WIFI_NAME";
    char* strength = (char *)"WIFI_STRENGTH";
    bool isOpen = true;
    char* expectedAnswer = (char *)"<div>Networks detected: 1"
	"<button onclick=\"showHide('0')\">Details</button>"
	"<div style=\"display:none\" id=\"0\">"
	"Network SSID: WIFI_NAME | Network signal strength: WIFI_STRENGTH | "
	"Not secured with password.<br>\n";
    logger.addNewWifi(name, strength, isOpen);
	//cout << "expectedAnswer: " << endl << expectedAnswer << endl;
	//cout << "logger.getLogs(): " << endl << logger.getLogs() << endl;
    REQUIRE(strcmp(expectedAnswer, logger.getLogs()) == 0);
}

TEST_CASE("Logger test end logging", "[endLogging]") {
    Logger& logger = Logger::GetInstance();
    char* expectedAnswer = (char *)"<div>Networks detected: 1"
	"<button onclick=\"showHide('0')\">Details</button>"
	"<div style=\"display:none\" id=\"0\">"
	"Network SSID: WIFI_NAME | Network signal strength: WIFI_STRENGTH | "
	"Not secured with password.<br>\n""</div></div>";
    logger.endLogging();
    //cout << "expectedAnswer: " << endl << expectedAnswer << endl;
	//cout << "logger.getLogs(): " << endl << logger.getLogs() << endl;
    REQUIRE(strcmp(expectedAnswer, logger.getLogs()) == 0);
}

TEST_CASE("Logger test clear logs", "[clearLogs]") {
    Logger& logger = Logger::GetInstance();
    logger.addNewWifi("WIFI_NAME", "WIFI_STRENGTH", true); //setup
    char* expectedAnswer = (char *)"";
    logger.clearLogs();
	//cout << "expectedAnswer: " << endl << expectedAnswer << endl;
	//cout << "logger.getLogs(): " << endl << logger.getLogs() << endl;
    REQUIRE(strcmp(expectedAnswer, logger.getLogs()) == 0);
}