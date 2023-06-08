
#include <ESP8266WiFi.h>
#include <espnow.h>

// REPLACE WITH RECEIVER MAC Address
uint8_t broadcastAddress[] = {0xEC , 0x62 , 0x60 , 0x75 , 0x4C , 0x70};

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message 
{
  String a; 
} struct_message;
struct_message myData;

char rec=0;
// Create a struct_message called myData

unsigned long lastTime = 0;  
unsigned long timerDelay = 2000;  // send readings timer

// Callback when data is sent
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) 
{
    Serial.print("Last Packet Send Status: ");
    if (sendStatus == 0)
    {
        Serial.println("Delivery success");
    }
    else
    {
        Serial.println("Delivery fail");
    }
}
 
void setup() {
  
  // Init Serial Monitor
  Serial.begin(9600);
 
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != 0) 
  {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}
 
void loop() 
{
  if(Serial.available()>0)    //Checks is there any data in buffer 
  {
    Serial.print("We got:");
    Serial.print('\n');
    rec =Serial.read();

    Serial.print(rec);
    Serial.print('\n');
    esp_now_send(broadcastAddress, (uint8_t *) &rec, sizeof(rec));
  }
  
  if ((millis() - lastTime) > timerDelay) 
  {
    lastTime = millis();
  }
}
