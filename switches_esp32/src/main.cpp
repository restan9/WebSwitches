#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid     = "ssid";
const char* password = "password";
const char* serverName = "serverName";

#define LED_1 26
#define LED_2 32
#define LED_3 25
#define LED_4 23
#define LED_5 12
#define LED_6 15

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void setup() {
  Serial.begin(115200);
  
  pinMode(LED_1, OUTPUT);     // Initialize the LED_1
  pinMode(LED_2, OUTPUT);     // Initialize the LED_2
  pinMode(LED_3, OUTPUT);     // Initialize the LED_3
  pinMode(LED_4, OUTPUT);     // Initialize the LED_4
  pinMode(LED_5, OUTPUT);     // Initialize the LED_5
  pinMode(LED_6, OUTPUT);     // Initialize the LED_6

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}


void loop() {
  //Check WiFi connection status
  if(WiFi.status()== WL_CONNECTED){
    HTTPClient http;
    http.begin(serverName);

    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    
    String httpResponseData = "";

    // Send HTTP GET request
    int httpResponseCode = http.GET();
    httpResponseData = http.getString();
    
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      Serial.println(httpResponseData);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }

    //Parse the string and change LED States
    String led_1_state = getValue(httpResponseData,';',0);
    String led_2_state = getValue(httpResponseData,';',1);
    String led_3_state = getValue(httpResponseData,';',2);
    String led_4_state = getValue(httpResponseData,';',3);
    String led_5_state = getValue(httpResponseData,';',4);
    String led_6_state = getValue(httpResponseData,';',5);
    Serial.println(led_1_state);
    Serial.println(led_2_state);
    Serial.println(led_3_state);
    Serial.println(led_4_state);
    Serial.println(led_5_state);
    Serial.println(led_6_state);
    
    if(led_1_state == "LED_1 is OFF"){
      digitalWrite(LED_1, LOW);}
    else {digitalWrite(LED_1, HIGH);}

    if(led_2_state == "LED_2 is OFF"){
      digitalWrite(LED_2, LOW);}
    else {digitalWrite(LED_2, HIGH);}
    
    if(led_3_state == "LED_3 is OFF"){
      digitalWrite(LED_3, LOW);}
    else {digitalWrite(LED_3, HIGH);}

    if(led_4_state == "LED_4 is OFF"){
      digitalWrite(LED_4, LOW);}
    else {digitalWrite(LED_4, HIGH);}

    if(led_5_state == "LED_5 is OFF"){
      digitalWrite(LED_5, LOW);}
    else {digitalWrite(LED_5, HIGH);}

    if(led_6_state == "LED_6 is OFF"){
      digitalWrite(LED_6, LOW);}
    else {digitalWrite(LED_6, HIGH);}

    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  //Send an HTTP GET request every 1 second
  delay(1000);
}