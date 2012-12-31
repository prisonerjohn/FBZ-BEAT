#ifndef FBZ_BEAT_GLOBALS
#define FBZ_BEAT_GLOBALS

//*************************
// STEP DEFINITIONS
//*************************

#define NUM_STEPS      8

//*************************
// MODE DEFINITIONS
//*************************

#define MODE_BANK_SEL  1
#define MODE_PATTERN   2
#define MODE_LIVE_PLAY 3

//*************************
// INPUT DEFINITIONS
//*************************

#define KNOB_TEMPO     A0
#define SWITCH_MODE_1  A3
#define SWITCH_MODE_2  A4

//*************************
// OUTPUT DEFINITIONS
//*************************

#define LATCH_PIN      7  // Pin connected to ST_CP of 74HC595 to D8 or D7 (green)
#define CLOCK_PIN      6  // Pin connected to SH_CP of 74HC595 to D12 or D6 (yellow)
#define DATA_PIN       5  // Pin connected to DS of 74HC595 to D11 or D5 (blue)

#endif
