#include "Singleton.cpp"
#include <cstring>
using namespace std;

class Logger : public Singleton<Logger> {

private:
    string log;
    int counter = 0;

public:
    const char *prepareResponse(const char *);
    void addNewWifi(const char *, const char *, bool);
    void startLogging(int);
    void endLogging();
    const char *getLogs();
    void clearLogs();
    int getCounter();
};

const char *Logger::prepareResponse(const char *s) {
    std::string str(s);
    string response = "<!DOCTYPE html>"
	"<script> function showHide(id)"
	"{var x = document.getElementById(id);"
	"if (x.style.display === \"none\")"
	"{  x.style.display = \"block\";}"
	"else {  x.style.display = \"none\";}}"
	"</script>"
	"<html>"
	"<body>"
	"<h1>WIFI Networks Scanner</h1>"
	"<div id=\"WIFI\">";
    response = response + s + "</div> </body> </html>";
    return response.c_str();
}

void Logger::startLogging(int number) {
    char numberString[32];
    char counterString[32];
    sprintf(numberString, "%d", number);
    log += "<div>Networks detected: ";
    log += numberString;
    log += "<button onclick=\"showHide('";
    sprintf(counterString, "%d", counter);
    log += counterString;
    log += "')\">Details</button>";
    log += "<div style=\"display:none\" id=\"";
    log += counterString;
    log += "\">";
    counter = counter + 1;
};

void Logger::addNewWifi(const char *name, const char *strength, bool isOpen) {
    std::string str(name);
    log += "Network SSID: ";
    log += name;
    log += " | Network signal strength: ";
    log += strength;
    if (isOpen) {
        log += " | Network not secured with password.";
    }
	else {
		log += " | Secured with password.";
	}
    log += "<br>\n";
};

void Logger::endLogging() {
    log += "</div></div>";
};

const char *Logger::getLogs() {
    return log.c_str();
};

void Logger::clearLogs() {
    log = "";
};

int Logger::getCounter() {
    return counter;
}