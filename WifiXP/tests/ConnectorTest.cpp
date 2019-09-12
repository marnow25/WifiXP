#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Project/class/Connector.cpp"


TEST_CASE( "Connector test connection", "[network_connectable]" ) {
    Connector conn;
    REQUIRE( conn.network_connectable(1) == true );
}

TEST_CASE( "Connector test ping", "[ping]" ) {
    Connector conn;
    REQUIRE( conn.ping() == true );
}