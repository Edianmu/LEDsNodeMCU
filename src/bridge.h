#include <Arduino.h>

void connectWiFi();
void subsConnection();
void callback(String topic, byte* message, unsigned int length);
void loopConnection();