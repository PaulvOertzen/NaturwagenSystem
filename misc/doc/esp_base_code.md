# usage
A starting point that provides some basic WiFi functionality and (mabe in the future) MQTT.
# Design
## variables to be set
Contains variables wich need to be set for mqtt and wifi to reference them.
## callback
Is a function that is triggered by a incomming mqtt signal and sets the values "latestTopic" and "latestPayload" to the values providet in the recieved MQTT message.
## ConnectToWifi
Waits until WiFi is connected and when it is, prints some debug information over serial.
## ConnectToMqtt
While not connected to given MQTT network, tries to connect and prints debug information while doing so. 
## controll
Cheacks for active WiFi and MQTT connection and if one of them is not given, either does nothing, resttarts the ESp or sends a error message over mqtt (this option is for poential future use and is a dumb idea at the current moment). 
## setup
Sets, as we know, the defaults etc and starts serial and WiFi connection, as well as MQTT.
## loop
Runns the controll to warn the system of potential problems.
Usage speciffic code sha'll be placed here.
## sendMQTTMessage
IS NOT IMPLEMENTED YET
should send a MQTT message with given parameters. Please feel free to implement.
