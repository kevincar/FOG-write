#ifndef BUTTON_H_
#define BUTTON_H_

#include "NeuroSmart.h"
#include "natus.h"
#include "pins.h"

void button_on_press();
void button_handle_state(int button_state);
int const button_update_state(int const button_state, int const button_input);
inline int button_value_increment(int const value);

// button states
int button_state = 0; // 0 - off, 1 - on, 2 - released, 3 - pressed
int button_value = 0;

// timing states
int button_prev_t = 0;
float button_T = 100.0;

void button_procedure(int btn_pin) {
  int t = millis();
  int dt = t - button_prev_t;
  if (dt >= button_T) {
    button_state = button_update_state(button_state, digitalRead(btn_pin));
    button_handle_state(button_state);
    button_prev_t = t;
  }
}

void button_handle_state(int button_state) {
  switch (button_state) {
  case 0: // OFF
    break;
  case 1: // PRESSED
    button_on_press();
    break;
  case 2: // RELASED
    Serial.println("Released");
    break;
  case 3: // ON
    break;
  }
}

void button_on_press() {
  button_value = button_value_increment(button_value);
  neurosmart_send_button(&PINS_NS[14], button_value);
  natus_send_button(&PINS_NATUS[6], button_value);
}

int const button_update_state(int const button_state, int const button_input) {
  return ((button_state & 1) << 1) | button_input;
}

inline int button_value_increment(int value) { return ++value % 4; }

#endif /* BUTTON_H_ */
