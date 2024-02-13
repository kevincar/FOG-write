#ifndef PINS_H_
#define PINS_H_

// ALPHA OMEGA DB 25 PORT SYSTEM
#define DIG01 48  // PIN 1
#define DIG03 46  // PIN 2
#define DIG05 44  // PIN 3
#define DIG07 42  // PIN 4
#define DIG09 40  // PIN 5
#define DIG11 38  // PIN 6
#define DIG13 36  // PIN 7
#define DIG15 34  // PIN 8
#define STROBE 32 // PIN 9
#define GND01 30  // PIN 10
#define GND02 23  // PIN 10
#define READY 25  // PIN 11
#define GND03 29  // PIN 12
#define GND04 29  // PIN 13
#define DIG02 53  // PIN 14
#define DIG04 51  // PIN 15
#define DIG06 49  // PIN 16
#define DIG08 47  // PIN 17
#define DIG10 45  // PIN 18
#define DIG12 43  // PIN 19
#define DIG14 41  // PIN 20
#define DIG16 39  // PIN 21
#define GND06 37  // PIN 22
#define GND07 35  // PIN 23
#define ANL01 A14 // PIN 24
#define ANL02 A15 // PIN 25

// NATUS VGA PORT (15 PIN Serial Port)
#define TRG1 A0 // PIN 1
#define TRG2 A1 // PIN 2
#define TRG3 A2 // PIN 3
#define TRG4 A3 // PIN 4
#define TRG5 A4 // PIN 5
#define TRG6 A5 // PIN 6
#define TRG7 A6 // PIN 7
#define TRG8 A7 // PIN 8
#define LT A8   // PIN 9
#define NGND1   // PIN 10
#define NGND2   // PIN 11
#define NGND3   // PIN 12
#define NGND4   // PIN 13
#define NGND5   // PIN 14
#define NGND6   // PIN 15

#define BTN 18

int PINS_NS[16] = {DIG01, DIG02, DIG03, DIG04, DIG05, DIG06, DIG07, DIG08,
                   DIG09, DIG10, DIG11, DIG12, DIG13, DIG14, DIG15, DIG16};

int PINS_NATUS[9] = {TRG1, TRG2, TRG3, TRG4, TRG5, TRG6, TRG7, TRG8, LT};

#endif /* PINS_H_ */
