#ifndef BITS_H_
#define BITS_H_

uint8_t bits_ensure6(uint16_t value) {
  int n_bits = 6;
  uint8_t max_value = (1 << n_bits) - 1;
  return ((max_value - (value & max_value)) * ((value >> n_bits) % 2)) +
         ((value & max_value) * (((value >> n_bits) + 1) % 2));
}

#endif /* BITS_H_ */
