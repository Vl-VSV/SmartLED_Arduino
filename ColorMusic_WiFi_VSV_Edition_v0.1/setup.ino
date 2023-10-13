void setup() {
  setupLED();

#if IR_REMOTE
  IRLremote.begin(IR_PIN);
#endif

#if AUTO_LOW_PASS
  fullLowPass();
#endif

#if !USE_WEMOS
  analogReference(INTERNAL);
#endif

#if !USE_WEMOS
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
  sbi(ADCSRA, ADPS2);
  cbi(ADCSRA, ADPS1);
  sbi(ADCSRA, ADPS0);
#endif

  FastLED.clear();

#if (USE_WEMOS && NET_REMOTE)
  connectWifi();
#endif

  Serial.begin(9600);
}