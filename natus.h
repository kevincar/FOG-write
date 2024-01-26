#ifndef NATUS_H_
#define NATUS_H_

void natus_set_pins(int const *pins, uint8_t value, int max_pin) {
  for (int i = 0; i < max_pin; i++) {
    bool set = (value >> i) & 1;
    int pin = pins[i];
    digitalWrite(pin, set);
  }
}

void natus_send_button(int pins[2], int value) {
  natus_set_pins(pins, value, 2);
}

void natus_send_value(int pins[9], uint8_t value) {
  natus_set_pins(pins, value, 6);
}

#endif /* NATUS_H_ */
