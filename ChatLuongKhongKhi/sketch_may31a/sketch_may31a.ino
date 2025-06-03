#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

// ==== Cấu hình WiFi ====
const char* ssid = "HQQ";
const char* password = "223035df";

// ==== Cấu hình cảm biến ====
#define DHTPIN 15         // Chân OUT của DHT22 nối GPIO15
#define DHTTYPE DHT22     // ✅ Đúng loại cảm biến
#define MQ135PIN 36       // MQ135 nối chân AO vào GPIO36 (VP)

DHT dht(DHTPIN, DHTTYPE);

// ==== Địa chỉ server Flask ====
const char* serverURL = "http://192.168.1.10:5000/airquality";

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Đang kết nối WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ Kết nối WiFi thành công!");
}

void loop() {
  float temperature = dht.readTemperature(); // °C
  float humidity = dht.readHumidity();
  int gas = analogRead(MQ135PIN);           // Giá trị ADC MQ135

  // Kiểm tra lỗi khi đọc
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("⚠️ Không đọc được dữ liệu từ DHT22!");
    delay(5000);
    return;
  }

  // Lọc dữ liệu không hợp lý
  if (temperature < -20 || temperature > 60 || humidity < 0 || humidity > 100) {
    Serial.print("⚠️ Giá trị bất thường: ");
    Serial.print("Nhiệt độ: "); Serial.print(temperature);
    Serial.print(" °C | Độ ẩm: "); Serial.println(humidity);
    delay(5000);
    return;
  }

  Serial.print("📤 Đang gửi: ");
  Serial.print(temperature); Serial.print(" °C | ");
  Serial.print(humidity); Serial.print(" % | ");
  Serial.print("Gas: "); Serial.println(gas);

  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    http.begin(client, serverURL);
    http.addHeader("Content-Type", "application/json");

    String payload = "{";
    payload += "\"temperature\":" + String(temperature, 1) + ",";
    payload += "\"humidity\":" + String(humidity, 1) + ",";
    payload += "\"gas\":" + String(gas);
    payload += "}";

    int httpResponseCode = http.POST(payload);
    if (httpResponseCode > 0) {
      Serial.print("✅ Gửi thành công! Phản hồi: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("❌ Gửi thất bại! Mã lỗi: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("🚫 Mất kết nối WiFi");
  }

  delay(10000); // Gửi mỗi 10 giây
}
