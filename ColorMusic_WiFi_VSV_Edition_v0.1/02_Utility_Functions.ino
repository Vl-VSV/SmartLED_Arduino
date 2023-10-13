#define CORRECTION 0xFFFFFF  // Корректировка оттенка (что бы белый был БЕЛЫМ). Ниже есть стандартные варианты, я подгонял вручную под свою ленту. 0xFFB0D0
/*  Типовые значения: TypicalSMD5050      = 0xFFB0F
                      Typical8mmPixel     = 0xFFE08C
                      TypicalLEDStrip     = 0xFFB0F0 - стоял этот, но на мой взгляд он "синит"
                      TypicalPixelString  = 0xFFE08C
                      UncorrectedColor    = 0xFFFFFF - этот отменит всякую корректировку (рекомендуется)        
*/

void setupLED() {
  FastLED.addLeds<WS2813, LED_PIN, RGB>(leds, NUM_LEDS).setCorrection(CORRECTION);
  if (CURRENT_LIMIT > 0) FastLED.setMaxPowerInVoltsAndMilliamps(5, CURRENT_LIMIT);
  FastLED.setBrightness(led_control_data.bright);
}

// Функция изменяет величину value на шаг incr в пределах minimum .. maximum
int smartIncr(int value, int incr_step, int mininmum, int maximum) {
  int val_buf = value + incr_step;
  val_buf = constrain(val_buf, mininmum, maximum);
  return val_buf;
}

// Функция изменяет величину value на шаг incr в пределах minimum .. maximum
float smartIncrFloat(float value, float incr_step, float mininmum, float maximum) {
  float val_buf = value + incr_step;
  val_buf = constrain(val_buf, mininmum, maximum);
  return val_buf;
}

bool timer_int(byte timer = 0, int val = led_control_data.EFFECT_DELAY) {
  if (milli - timer_arr_int[timer] > val) {
    timer_arr_int[timer] = milli;
    return true;
  }
  return false;
}