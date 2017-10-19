#include "GPIO.h"
#include "SRPI.h"
#include "benchmark.h"

SRPI<LSBFIRST, BOARD::D12, BOARD::D13> srpi;
#define DATA_PIN 12
#define CLOCK_PIN 13

void setup()
{
  Serial.begin(57600);
  while (!Serial);

  // Set pin mode
  pinMode(DATA_PIN, INPUT);
  pinMode(CLOCK_PIN, OUTPUT);

  // Set benchmark baseline
  BENCHMARK_BASELINE(1000);
}

void loop()
{
  uint8_t value;

  BENCHMARK("1. Arduino core shiftIn", 1000) {
    value = shiftIn(DATA_PIN, CLOCK_PIN, LSBFIRST);
  }

  BENCHMARK("2. SRPI input operator", 1000) {
    srpi >> value;
  }

  Serial.println();
  delay(2000);
}
