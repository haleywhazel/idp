#ifndef PINOUT
#define PINOUT
const int ultrasound_trig = 2;
const int ultrasound_echo = 6;
const int digital_vcc = 3;
const int button = 12;
const int button_vcc = 13;
const uint8_t ir_1 = A0;
const uint8_t ir_2 = A1;
const float ir_offset = 14;
const float default_speed = 0.7;
const float proportional_k = 0.025;
const int servo_sig = 10;
const int lm = 4;
const int rm = 3;
const float ema_k = 0.75;
#endif