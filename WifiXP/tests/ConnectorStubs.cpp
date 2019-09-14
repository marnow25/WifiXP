//stubbing for acceptance tests
#include <string>
#include <unistd.h>
#include <iostream>

#define WL_CONNECTED 1 // if is connected
#define WIFI_STA 1 //wifi mode 

class StubPing{ //ping stubbing
    public:
    bool ping(const char* x){
		if ( x == (const char*)"www.google.com"){
			return true;}
		else {
			return false;};
	};
};

class StubWiFi{ //wifi setup stubbing
	private:
		int m = 1;
		bool dis;
		int net_id;
		std::string begin_ind = "ok";
		std::string begin_options = "";
		std::string ssid = "WiFi Networks Scanner";
		std::string password = "";
		bool compareStatus[3] = {};
		
    public:
		void mode(int m) { 
			if(this->m == m) {
				this->compareStatus[0] = 1;
			} else {
				this->compareStatus[0] = 0;
			}
		};
		void disconnect() { 
			this->dis = true;
		};
		void softAP(std::string ssid, std::string password) {
			if (this->ssid == ssid && this->password == password) {
				this->compareStatus[1] = 1;
			} else {
				this->compareStatus[1] = 0;
			}
		};
		std::string SSID(int id){return "ok";}
		void begin(std::string begin_ind, std::string begin_options) {
			if (this->begin_ind == begin_ind && this->begin_options == begin_options) {
				this->compareStatus[2] = 1;
			} else {
				this->compareStatus[2] = 0;
			}
		}; 
		int status(){
			for(int x = 0; x < 3; x++) {
				// std::cout << "CompareStatus:"<<x<<" " << this->compareStatus[x]<< "\n";
				if ( this->compareStatus[x] == 0 && this->dis == true ){
					return 0;
				}
			}
			return 1;
		}
	
};

void delay(int ms) {
	usleep(ms*1000);
};

StubPing Ping;
StubWiFi WiFi;

