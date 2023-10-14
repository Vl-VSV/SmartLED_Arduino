struct LEDControlData {
  byte mode = 1;
  byte submode = 1;
  byte maxSubmode[1] = { 3 };

  byte color = 0;

  byte bright = 255;
  byte maxBright = 255;
  byte minBright = 0;

  byte settings[2] = {90, 255};
};