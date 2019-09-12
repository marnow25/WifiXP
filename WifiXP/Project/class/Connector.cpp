#ifndef _CONNECTOR_CPP_
#define _CONNECTOR_CPP_

#include "IConnect.cpp"


#if !defined(_ATEST_)
#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>

#else
#include "../../tests/ConnectorMocks.cpp"

#endif

class Connector: public IConnect{
    public:
        bool ping(){
            bool ret = Ping.ping("www.google.com");
            if (ret) {
                return true;
            }
            return false;
        }
        bool network_connectable(int net_id){
            WiFi.begin(WiFi.SSID(net_id), "");
            delay(3000);
            for(int j = 0; j<5; j++) {
            if (WiFi.status () == WL_CONNECTED) {
                bool ret = ping();
                WiFi.disconnect();
                return ret;

            }
            delay(200);
        }
        return false;
        }
};

#endif
