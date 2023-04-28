#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const int ledD0 = 16;
const int ledD1 = 4;
const int ledD2 = 2;
const int ledD3 = 12;

const char* mqttServer = "****"; //Server IP

WiFiClient espClient;
PubSubClient client(espClient);

void callback(String topic, byte* message, unsigned int length){

  Serial.print("Mensaje llegó en el topico: ");
  Serial.print(topic);
  Serial.print(". Mensaje: ");
  String messageTemp;

  for (int i = 0; i < length; i++)
  {

    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }

  Serial.println();

  if (topic == "LED/1")
  {

    Serial.print("Led Daniel ");

    if (messageTemp == "on")
    {
      digitalWrite(ledD0, HIGH);
      Serial.print("on");
    }

    else if (messageTemp == "off")
    {
      digitalWrite(ledD0, LOW);
      Serial.print("off");
    }
    Serial.println();
  }

  if (topic == "LED/2")
  {

    Serial.print("Led Edisson ");

    if (messageTemp == "on")
    {
      digitalWrite(ledD1, HIGH);
      Serial.print("on");
    }

    else if (messageTemp == "off")
    {
      digitalWrite(ledD1, LOW);
      Serial.print("off");
    }
    Serial.println();
  }

  if (topic == "LED/3")
  {

    Serial.print("Led Jorge ");

    if (messageTemp == "on")
    {
      digitalWrite(ledD2, HIGH);
      Serial.print("on");
    }

    else if (messageTemp == "off")
    {
      digitalWrite(ledD2, LOW);
      Serial.print("off");
    }
    Serial.println();
  }

  if (topic == "LED/4")
  {

    Serial.print("Led Valentina ");

    if (messageTemp == "on")
    {
      digitalWrite(ledD3, HIGH);
      Serial.print("on");
    }

    else if (messageTemp == "off")
    {
      digitalWrite(ledD3, LOW);
      Serial.print("off");
    }
    Serial.println();
  }
}

void subsConnection(){
     
  pinMode(ledD0, OUTPUT);
  pinMode(ledD1, OUTPUT);
  pinMode(ledD2, OUTPUT);
  pinMode(ledD3, OUTPUT);

  Serial.print("Conectando al servidor: ");
  Serial.println(mqttServer);
  client.setServer(mqttServer, 1883);
  client.setCallback(callback);
  
  Serial.print("Intentando establecer conexión MQTT... ");
  
  if (client.connect(mqttServer)){
    Serial.println("Conectado");
  }
  else{
    Serial.print("Error ");
    Serial.print(client.state());
    Serial.println("\nIntentando reconectar en 5 segundos");
    delay(5000);
  }
    client.subscribe("LED/1");
    client.subscribe("LED/2");
    client.subscribe("LED/3");
    client.subscribe("LED/4");
}

void loopConnection(){
  
    client.loop();
}