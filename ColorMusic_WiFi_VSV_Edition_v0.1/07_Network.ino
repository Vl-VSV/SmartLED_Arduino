#if (USE_WEMOS && NET_REMOTE)
void connectWifi() {
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Подключение к Wi-Fi...");
  }

  Serial.println("Подключено к Wi-Fi");
}
#endif

#if (USE_WEMOS && NET_REMOTE)
void networkTick() {
  if (timer_int(1, NET_DELAY), WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    if (http.begin(client, server)) {
      int httpCode = http.GET();

      if (httpCode > 0) {
        String payload = http.getString();
        Serial.println("Response: " + payload);
      } else {
        Serial.println("Не удалось выполнить GET-запрос. Код ошибки: " + String(httpCode));
      }
    }
    http.end();
  }
}
#endif