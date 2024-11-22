#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

// WiFi credentials
const char* ssid = "YourWiFiSSID";  // Replace with your WiFi SSID
const char* password = "YourWiFiPassword";  // Replace with your WiFi password

// MQTT Broker IP
const char* mqttBroker = "192.168.x.x";  // Replace with your MQTT broker's IP address

// MQTT topics
const char* temperatureTopic = "home/room/temperature";
const char* lampTopic = "home/room/lamp";

// DHT11 configuration
#define DHTPIN 23  // GPIO pin connected to the DHT11 sensor
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// LED pin
const int ledPin = 2; // GPIO2 (D4 on some ESP boards)

// MQTT client setup
WiFiClient espClient;
PubSubClient client(espClient);

// Function to connect to WiFi
void connectWiFi() {
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected. IP Address: " + WiFi.localIP().toString());
}

// Function to connect to MQTT broker
void connectMQTT() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT broker...");
    if (client.connect("ESP32Client")) {  // Client ID
      Serial.println("Connected!");
      client.subscribe(lampTopic);  // Subscribe to the lamp topic
    } else {
      Serial.println("Failed. Retrying...");
      delay(5000);
    }
  }
}

// Callback function for received messages
void mqttCallback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  if (String(topic) == lampTopic) {
    if (message == "1") {
      digitalWrite(ledPin, HIGH); // Turn LED on
      Serial.println("LED ON");
    } else if (message == "0") {
      digitalWrite(ledPin, LOW); // Turn LED off
      Serial.println("LED OFF");
    }
  }
}

// Setup function
void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  dht.begin();
  connectWiFi();
  client.setServer(mqttBroker, 1883);
  client.setCallback(mqttCallback);
}

// Loop function
void loop() {
  if (!client.connected()) {
    connectMQTT(); // Ensure MQTT connection
  }
  client.loop();

  float temperature = dht.readTemperature();
  if (!isnan(temperature)) {
    String tempPayload = String(temperature, 2);  // Format temperature
    client.publish(temperatureTopic, tempPayload.c_str()); // Publish temperature
    Serial.println("Temperature: " + tempPayload);
  }

  delay(2000);  // Wait 2 seconds
}
