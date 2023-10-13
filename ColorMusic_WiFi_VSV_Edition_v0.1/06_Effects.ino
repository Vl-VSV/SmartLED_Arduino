// Функция делает всю ленту выбранным цветом
void one_color_all(byte hue, byte sat, byte val) {
  for (int i = 0; i < NUM_LEDS; i++) leds[i].setHSV(hue, sat, val);
}