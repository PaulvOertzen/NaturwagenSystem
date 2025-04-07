int LDRR = 33; // Analoger Pin als LDR Eingang
int LDRM = 32;
//int LED = 13; // LED-Pin
int sensorWertR = 0; // Variable für den Sensorwert mit 0 als Startwert
int sensorWertM =0;
void setup()
{
Serial.begin(115200);
delay(1000);
//pinMode (2, OUTPUT);
analogReadResolution(12);
}
 
void loop()
{
//digitalWrite(2, HIGH);
sensorWertR =analogRead(LDRR);
sensorWertM =analogRead(LDRM);
 //
Serial.println("Räächts");
Serial.println(sensorWertR);
Serial.println("Schützengraben"); //Ausgabe am Serial-Monitor.
Serial.println(sensorWertM); //Ausgabe am Serial-Monitor.
delay(500);
}
