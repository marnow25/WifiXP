#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <cstring>
#include "../Project/class/Connector.cpp"

TEST_CASE( "Connector stubbing for ping testing", "[ping]" ) {
	Connector connect;
	bool response = connect.ping();
    REQUIRE( response == true );
}

TEST_CASE( "Connector stubbing for connection", "[network_connectable]" ) {
	Connector connect;
	bool conectionAcceptable = connect.network_connectable(1);
    REQUIRE( conectionAcceptable == true );
}
