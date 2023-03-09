#include "sensors.h"

void Sensors::setup() {
	pinMode(ultrasound_trig, OUTPUT);
	pinMode(ultrasound_echo, INPUT);
	pinMode(digital_vcc, OUTPUT);
	pinMode(button, INPUT);
	pinMode(button_vcc, OUTPUT);
	pinMode(ir_1, INPUT);
	pinMode(ir_2, INPUT);

	digitalWrite(button_vcc, HIGH);
	digitalWrite(digital_vcc, HIGH);
}

void sort(int a[], int size) {
    for(int i=0; i<(size-1); i++) {
        bool flag = true;
        for(int o=0; o<(size-(i+1)); o++) {
            if(a[o] > a[o+1]) {
                int t = a[o];
                a[o] = a[o+1];
                a[o+1] = t;
                flag = false;
            }
        }
        if (flag) break;
    }
}

float Sensors::front_ultrasonic() {
	digitalWrite(ultrasound_trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(ultrasound_trig, LOW);

	int duration = pulseIn(ultrasound_echo, HIGH);
	float reading = duration / 5.8;
	return reading;
}

float Sensors::read_ir(uint8_t pin) {
	const int sample_size = 25;
	int readings[sample_size];
	for (int r = 0; r < sample_size; r++) {
		readings[r] = analogRead(ir_1);
		delay(1);
	}
	sort(readings, sample_size);
	int median = readings[(sample_size - 1) / 2];
	
  	float reading = 60.374 * pow(map(median, 0, 1023, 0, 5000)/1000.0, -1.16);
	return reading;
}

bool Sensors::block_blue() {
	return true;
}
