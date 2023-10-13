void animation() {
  byte this_mode = led_control_data.mode;
  byte this_submode = led_control_data.submode;

  switch (this_mode) {
    case 1:
      switch (this_submode) {
        case 1:
          if (led_control_data.WHITE_TEMP > 90) one_color_all(HUE_ORANGE, (led_control_data.WHITE_TEMP - 90) * 2, led_control_data.LIGHT_SAT);
          else one_color_all(HUE_BLUE, 90 - led_control_data.WHITE_TEMP, led_control_data.LIGHT_SAT);
          break;
        case 2:
          one_color_all(led_control_data.LIGHT_COLOR, led_control_data.LIGHT_SAT, 255);
          break;
        case 3:
          if (timer_int(2)) one_color_all(led_control_data.color++, led_control_data.LIGHT_SAT, 255);
          break;
      }
      break;
  }
}