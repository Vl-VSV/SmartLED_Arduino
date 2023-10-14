void loop() {
  milli = millis();
#if IR_REMOTE
  remoteTick();
#endif

#if NET_REMOTE
  networkTick();
#endif

  if (timer_int(0, MAIN_LOOP)) {
    animation();

#if IR_REMOTE
    if (!IRLremote.receiving())
#endif
      FastLED.show();
  }
}