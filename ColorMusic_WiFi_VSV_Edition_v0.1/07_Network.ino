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
  if (timer_int(1, NET_DELAY) && WiFi.status() == WL_CONNECTED) {
    
    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
    client->setInsecure();

    HTTPClient https;
    
    if (https.begin(*client, "https://smartled.onrender.com/getData")) {

      int httpCode = https.GET();

      if (httpCode > 0) {
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = https.getString();
          parseData(payload);
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
      }
      https.end();
    }
  }
}
#endif

#if (USE_WEMOS && NET_REMOTE)
void parseData(String data) {
  deserializeJson(jsonDoc, data);

  int mode = jsonDoc["mode"];
  int submode = jsonDoc["submode"];

  Serial.println("New mode: " + String(mode));
  Serial.println("New submode: " + String(submode));

  led_control_data.mode = mode;
  led_control_data.submode = submode;
}
#endif