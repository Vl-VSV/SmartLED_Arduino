#if !USE_WEMOS
void analyzeAudio() {
  for (int i = 0; i < FHT_N; i++) {
    int sample;
    sample = analogRead(SOUND_MIC_FREQ);

    delayMicroseconds(42);
    fht_input[i] = sample;
  }

  fht_window();   // окно данных для лучшей частотной характеристики window the data for better frequency response
  fht_reorder();  // переупорядочить данные перед выполнением fht    reorder the data before doing the fht
  fht_run();      // обработайте данные в fht                        process the data in the fht
  fht_mag_log();  // возьмите выходные данные fht                    take the output of the fht
}
#endif

void autoLowPass() {
#if USE_WEMOS
  delay(10);
#else
  _delay_ms(10);  // ждём инициализации АЦП
#endif

  int thisMax = 0;  // максимум
  int thisLevel;

  for (byte i = 0; i < 200; i++) {  // делаем 200 измерений
    thisLevel = analogRead(SOUND_MIC);
    if (thisLevel > thisMax) thisMax = thisLevel;  // ищем максимумы и запоминаем
  }
  LOW_PASS = thisMax + LOW_PASS_ADD;  // нижний порог как максимум тишины + некая величина


// для режима спектра
#if !USE_WEMOS
  for (byte i = 0; i < 100; i++) {   // делаем 100 измерений
    analyzeAudio();                  // разбить в спектр
    for (byte j = 2; j < 32; j++) {  // первые 2 канала - хлам
      thisLevel = fht_log_out[j];
      if (thisLevel > thisMax)  // ищем максимумы
        thisMax = thisLevel;    // запоминаем
    }
  }
  SPEKTR_LOW_PASS = thisMax + LOW_PASS_FREQ_ADD;  // нижний порог как максимум тишины
#endif
}


void fullLowPass() {
  FastLED.setBrightness(0);
  FastLED.show();


#if USE_WEMOS
  delay(100);
  autoLowPass();
  delay(100);
#else
  _delay_ms(100);
  autoLowPass();
  _delay_ms(100);
#endif

  FastLED.setBrightness(led_control_data.bright);
}