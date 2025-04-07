int LDRM = 32; // Analoger Pin als LDR Eingang
int LDRS = 33;
int LDRW = 34;
int LDRN = 35;
int LDRO = 36;

#include <WiFi.h>
#include <PubSubClient.h>
//WiFi Setup
const char *ssid = "wolfsscanze";
const char *password = "tierpitz";
const char *hostname = "niko";
IPAddress ip(192, 168, 0, 50); // sets static ip address
IPAddress gw(10, 0, 1, 1); // sets gateway
IPAddress sub(255, 255, 255, 0); // sets subnetmask
// MQTT Broker Setup
const char *mqtt_broker = "broker.emqx.io";
const char *topic = "emqx/esp32";
const char *mqtt_username = "emqx";
const char *mqtt_password = "public";
const int mqtt_port = 1883;
 
// esp system setup
const int serialBaud = 115200;
const int wifiConnectDelay = 500;
//wifi internal setup
WiFiClient espClient;
PubSubClient client(espClient);

int sensorWertM = 0; // Variable für den Sensorwert mit 0 als Startwert
int sensorWertS =0;
int sensorWertW =0;
int sensorWertN =0;
int sensorWertO =0;

void setup(){
    // serial setup
    Serial.begin(serialBaud);
    //WiFi CONNECTION
    WiFi.config(ip, gw, sub); // sonfigs wifi
    WiFi.hostname(hostname); // sets hostname
    WiFi.begin(ssid, password); // connects to wifi
    int nCntCnter = 0; // for counting how manny tries to connect
    while (WiFi.status() != WL_CONNECTED) { // tries to connect while not connected
        delay(wifiConnectDelay); // delays
        Serial.println("Connecting to WiFi.."); // user feedback
        nCntCnter = nCntCnter + 1; // counts tries to connect
        if ( nCntCnter > 30 ) { // if more than 30 times failed to connect
            ESP.restart(); //restart
        }
    }
    // if wifi connection is succsessfull -> User feedback
    Serial.println(WiFi.status());
    Serial.println(WiFi.localIP());
    Serial.println("Connected...");
    Serial.print("IP address:\t");
    IPAddress myIP = WiFi.localIP();
    Serial.println(myIP);
    // MQTT connection
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
    //pinMode (2, OUTPUT);
    analogReadResolution(12);
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
void loop(){
    //digitalWrite(2, HIGH);
    sensorWertM =analogRead(LDRM);
    sensorWertS =analogRead(LDRS);
    sensorWertW =analogRead(LDRW);
    sensorWertN =analogRead(LDRN);
    sensorWertO =analogRead(LDRO);
    //
    Serial.println("Mitte: " + sensorWertM);
    Serial.println("Sueden: " + sensorWertS);
    Serial.println("West: " + sensorWertW);
    Serial.println("Norden: " + sensorWertN);
    Serial.println("Osten: " + sensorWertO);
    //Serial.println(sensorWertR);
    //Serial.println("Schützengraben"); //Ausgabe am Serial-Monitor.
    //Serial.println(sensorWertM); //Ausgabe am Serial-Monitor.
    
    client.publish("test/espAnalogPhotoresist", "mitte:"+sensorWertM)
    client.publish("test/espAnalogPhotoresist", "Sued:"+sensorWertS)
    client.publish("test/espAnalogPhotoresist", "west:"+sensorWertW)
    client.publish("test/espAnalogPhotoresist", "nord:"+sensorWertN)
    client.publish("test/espAnalogPhotoresist", "east:"+sensorWertO)

    delay(500);
}