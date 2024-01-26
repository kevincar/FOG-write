/**
 *
 * FOG-write.ino
 * Author: Kevin Davis
 * Date: 2023.09.19
 *
 * This file coordinates triggering TTL pulses to both the NeuroSmart
 * recording system and the Natus Brain Monitoring box
 *
 * The NeuroSmart system has a 16 bit input and the Natus Brain
 * Monitoring system has an 8-bit input
 *
 * In order to ensure that we can synchronize the neural data recording
 * recorded by the NeuroSmart and the muscle data recorded by the Natus
 * System, this code will send synchronous TTL pulses to each.
 * Because there are some recording depths that may only be shortly
 * recorded, the TTL pulses will be sent every 0.5 seconds. To ensure
 * that we can line-up the pulses, each pulse will send a digit to
 * each device. However, to also ensure that we can send TTL pulses
 * that are human input, we will also have button. This way, the TTL
 * pulse sent with the button can function as a higher order signal
 * to synchronize to, then the lower-order 500ms signals can be lined
 * up
 *
 * The time signals will work by incrementing a 12-bit number to the
 * NeuroSmart device (max value = 4096). This will be matched with a
 * 6-bit number sent to the Natus Brain Monitoring System (max value =
 * 63). This will result in the digit number to cycle every 32 seconds
 * Because the natus is the limiting factor, we can increase the cycle
 * to every 64 seconds by having the cycle go back down rather than
 * simply repeating. This way, we can use the slope of the change to
 * provide more cycling time
 *
 * The highend two bits on both the NeuroSmart and the remaining high
 * end two bits on the Natus will be used to syncronize a button press
 * with a digits 0-3 sent to both
 */

// =================================================================

#include "pins.h"
#include "button.h"
#include "ports.h"

void setup() {
  Serial.begin(115200);
  pinMode(BTN, INPUT);

  // Setup pins for the NeuroSmart
  for (int i = 0; i < 16; i++) {
    int pin = PINS_NS[i];
    pinMode(pin, OUTPUT);
  }

  // Setup mins for the Natus
  for (int i = 0; i < 8; i++) {
    int pin = PINS_NATUS[i];
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  // send pulse
  ports_procedure(PINS_NS, PINS_NATUS);

  // button - only update every 100 milliseconds
  button_procedure(BTN);
}
