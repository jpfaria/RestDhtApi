#include "Arduino.h"
#include "RestDhtApi.h"
#include "WebServer.h"
#include "DHT.h"

RestDhtApi::RestDhtApi(WebServer &server) {
	server.addCommand("dht", &RestDhtApi::dht);
}

void RestDhtApi::dht(WebServer &server, WebServer::ConnectionType type,
		char *url_tail, bool tail_complete) {
	URLPARAM_RESULT rc;
	char name[32];
	char value[32];

	//server.httpSuccess("application/json");
	server.httpSuccess();

	if (type != WebServer::GET)
		return;

	if (strlen(url_tail)) {

		DHT dht;

		while (strlen(url_tail)) {

			rc = server.nextURLparam(&url_tail, name, 32, value, 32);

			String param = String(name);

			if (param == "pin") {

				String vl = value;
				int v = atoi(vl.c_str());

				dht.setup(v);

				double hum = dht.getHumidity();
				double tempC = dht.getTemperature();
				double tempF = dht.toFahrenheit(tempC);

				Serial.println(v);
				Serial.println(tempC);
				Serial.println(tempF);
				Serial.println(hum);

			}

		}
	}
}
