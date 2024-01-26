#ifndef NEUROSMART_H_
#define NEUROSMART_H_

void neurosmart_set_pins(int const *pins, uint16_t value, int max_pin) {
  for (int i = 0; i < max_pin; i++) {
    bool set = (value >> i) & 1;
    int pin = pins[i];
    digitalWrite(pin, set);
  }
}

void neurosmart_send_button(int pins[2], int value) {
  neurosmart_set_pins(pins, value, 2);
}

void neurosmart_send_value(int pins[17], uint16_t value) {
  neurosmart_set_pins((int *)pins, value, 12);

  // STROBE
  int strobe_pin = pins[16];
  digitalWrite(strobe_pin, HIGH);
  delay(50);
  digitalWrite(strobe_pin, LOW);
}

#endif /* NEUROSMART_H_ */
