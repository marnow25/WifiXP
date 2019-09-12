//mocking for tests
#include <string>
class MPing{
    public:
    bool ping(std::string x){return true;};
};

void delay(int ms){}
//std::this_thread::sleep_for(std::chrono::milliseconds(ms));

class MWiFi{
    public:
    void begin(std::string, std::string){}
    std::string SSID(int id){return "okk";}
    int status(){return 1;}
    void disconnect(){};
};
MPing Ping;
MWiFi WiFi;
#define WL_CONNECTED 1
