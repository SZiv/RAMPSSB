#include "GPIO.h"
#include "SRPO.h"
#include "benchmark.h"

SRPO<LSBFIRST, BOARD::D12, BOARD::D13> srpo;
#define DATA_PIN 12
#define CLOCK_PIN 13

void setup()
{
  Serial.begin(57600);
  while (!Serial);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  BENCHMARK_BASELINE(1000);
}

void loop()
{
  uint8_t value = 0xa5;

  BENCHMARK("1. Arduino core shiftOut", 1000) {
    shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, value);
  }

  BENCHMARK("2. SRPO output operator", 1000) {
    srpo << value;
  }

  Serial.println();
  delay(2000);
}
