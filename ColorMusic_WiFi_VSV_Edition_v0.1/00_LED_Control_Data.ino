struct LEDControlData {
  byte mode = 1;
  byte submode = 1;
  byte maxSubmode[4] = {3, 6, 4, 9};

  byte color = 0;
  byte bright = 255;
  byte hue = 0;

  byte settings[2] = {90, 255};
};