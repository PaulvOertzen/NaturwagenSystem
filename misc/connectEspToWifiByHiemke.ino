#include <WiFi.h>
const char* ssid = "hiemke"; 
const char* password = "gehscheissen";

void setup() {
    // put your setup code here, to run once:
  Serial.begin(115200); 
  WiFi.begin(ssid, password);
  int nCntCnter = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
    nCntCnter = nCntCnter + 1;
    if ( nCntCnter > 10 ) {
      ESP.restart();
    }
  }
   Serial.println(WiFi.status());
    Serial.println(WiFi.localIP());
  Serial.println("Connected...");
}

void loop() {
  
  // put your main code here, to run repeatedly:


}
