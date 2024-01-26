#ifndef PORTS_H_
#define PORTS_H_

#include "NeuroSmart.h"
#include "bits.h"
#include "natus.h"

uint16_t tick = 0;
int ports_prev_t = 0;
float ports_T = 500.0;

inline uint16_t ports_increment_tick(uint16_t value) {
  return ++value % 0x1000;
}

void ports_procedure(int neurosmart_pins[16], int natus_pins[9]) {
  int t = millis();
  int dt = t - ports_prev_t;

  if (dt >= ports_T) {
    tick = ports_increment_tick(tick);
    neurosmart_send_value(neurosmart_pins, tick);
    natus_send_value(natus_pins, bits_ensure6(tick));
    ports_prev_t = t;
  }
}

#endif /* PORTS_H_ */
