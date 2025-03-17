#include <WiFi.h>
#include <PubSubClient.h>
 
//WiFi Setup
const char *ssid = "wolfsscanze";
const char *password = "tierpitz";
const char *hostname = "niko";
IPAddress ip(192, 168, 0, 50); // sets static ip address
IPAddress gw(10, 0, 1, 1); // sets gateway
IPAddress sub(255, 255, 255, 0); // sets subnetmask
// esp system setup
const int serialBaud = 115200;
const int wifiConnectDelay = 500;
//wifi internal setup
WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {
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
}
void loop() {  
  // put your main code here, to run repeatedly:
}
