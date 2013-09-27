#ifndef RestDhtApi_h
#define RestDhtApi_h

#include "Arduino.h"
#include "WebServer.h"
#include "DHT.h"

class RestDhtApi
{
  public:
    RestDhtApi(WebServer &server);
    static void dht(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete);
};

#endif
