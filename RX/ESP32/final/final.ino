#include <esp_now.h>
#include <WiFi.h>


char rec_val;


void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) 
{
  memcpy(&rec_val, incomingData, sizeof(rec_val));
}

void setup() 
{
  Serial.begin(9600);
  WiFi.mode(WIFI_STA); 
  if (esp_now_init() != ESP_OK) 
  {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_recv_cb(OnDataRecv); 
  delay(500);
}

void loop() 
{
  Serial.write(rec_val);
  Serial.println("\nUART REC : ");
}
