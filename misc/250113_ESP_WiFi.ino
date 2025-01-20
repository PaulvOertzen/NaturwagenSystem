#include <WiFi.h>
#include <PubSubClient.h>

//WiFi Setup
const char *ssid = "hiemke"; 
const char *password = "gehscheissen";

// MQTT Broker
const char *mqtt_broker = "broker.emqx.io";
const char *topic = "emqx/esp32";
const char *mqtt_username = "emqx";
const char *mqtt_password = "public";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {

//WiFi CONNECTION
  Serial.begin(115200); 
  WiFi.hostname("HiemkeEsp");
  WiFi.begin(ssid, password);
  int nCntCnter = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
    nCntCnter = nCntCnter + 1;
    if ( nCntCnter > 30 ) {
      ESP.restart();
    }
  }
    Serial.println(WiFi.status());
    Serial.println(WiFi.localIP());
    Serial.println("Connected...");
    Serial.print("IP address:\t");
    IPAddress myIP = WiFi.localIP();
    Serial.println(myIP);

//MQTT connection

  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  while (!client.connected()) {
  String client_id = "esp32-client-";
    client_id += String(WiFi.macAddress());
    Serial.printf("The client %s connects to the public MQTT broker\n", client_id.c_str());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
        Serial.println("Public EMQX MQTT broker connected");
    } else {
        Serial.print("failed with state ");
        Serial.print(client.state());
        delay(2000);
    }
}

}
void callback(char *topic, byte *payload, unsigned int length) {
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message:");
    for (int i = 0; i < length; i++) {
        Serial.print((char) payload[i]);
    }
    Serial.println();
    Serial.println("-----------------------");
}

void loop() {
  
  // put your main code here, to run repeatedly:


}
