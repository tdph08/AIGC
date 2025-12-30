#include <WiFi.h> 
#include <DHT.h> 
#include "ThingSpeak.h" 

// wifi và mật khẩu cho esp32 sử dụng 
#define WIFI_SSID "BKSTAR" 
#define WIFI_PASSWORD "stemstar" 

// liên kết ThingSpeak với esp32, id và write APIKey từ dự án đã tạo 
#define SECRET_CH_ID 3209451 
#define SECRET_WRITE_APIKEY "QNBUOTDQIME8I00L" 

#define DHTPIN 12
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

WiFiClient client; 
unsigned long myChannelNumber = SECRET_CH_ID; 
const char * myWriteAPIKey = SECRET_WRITE_APIKEY; 

unsigned long dataMillis = 0; // biến điều khiển delay 

void setup() { 
  Serial .begin(9600);  
  dht.begin(); // khởi tạo DHT 

  WiFi.begin (WIFI_SSID,WIFI_PASSWORD); 
  Serial .print("Connecting to Wi-Fi"); 
  while (WiFi.status() != WL_CONNECTED) { 
  delay(500); 
  Serial.print("-"); 
  } 
  Serial .println(""); 
  Serial .println("WiFi Connected"); 
  Serial .print("IP Address: "); 
  Serial .print("http://"); 
  Serial .print(WiFi.localIP()); 
  Serial .println("/"); 

  ThingSpeak .begin(client); // khởi tạo ThingSpeak 
} 
void loop() { 

  // đọc dữ liệu nhiệt độ, độ ẩm từ cảm biến DHT 
  float temperature = dht.readTemperature(); 
  float humidity = dht.readHumidity(); 

  ThingSpeak .setField(1, temperature); 
  ThingSpeak .setField(2, humidity); 

  // Đọc dữ liệu lên ThingSpeak sau mỗi 20 giây 
  if (millis() - dataMillis > 20000) 
  { 
    Serial.printf("temperature value: %.2f\n", temperature); 
    Serial.printf("humidity value: %.2f\n", humidity); 
    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey); 
    // x luôn bằng 200 khi dữ liệu được gửi thành công lên ThingSpeak 
    if ( x == 200){ 
    Serial.println("Channel update successful."); 
    } 
    else{ 
    Serial.println("Problem updating channel. HTTP error code " + String(x)); 
  } 
  } 

}