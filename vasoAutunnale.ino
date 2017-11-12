/*
 * vasoInvernale
 * REQUIRES: FastLED 3.1.0
 * 
 * Copyright (c) 2017 Matteo Marchesi
 *
 */


#include "FastLED.h"

// definisce il numero di led da comnadare nella striscia
#define NUM_LEDS 20

#define DATA_PIN 3

CRGB leds[NUM_LEDS];

int C = 50;
int S = 255;
int B = 100;

int CB = 22;
int SB = 255;
int BB = 148;


int incr = 1;
int incrB = 1;

unsigned long previousAut = 0;
const long intervalAut = 300;

int incrBr = 1;
int incrBrB = 1;
unsigned long previousBright = 0;
const long intervalBright = 30;
unsigned long previousBrightB = 0;
const long intervalBrightB = 10;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  unsigned long current = millis();

  if (current - previousAut >= intervalAut) {
    previousAut = current;
    C = C + incr;
    if ((C>64) or (C<20)) {incr = -incr;};
    CB = CB + incrB;
    if ((CB>64) or (CB<20)) {incrB = -incrB;};
  }
  if (current - previousBright >= intervalBright) {
    previousBright = current;
    B = B + incrBr;
    if ((B>150) or (B<50)) {incrBr = -incrBr;};
  }
  if (current - previousBrightB >= intervalBrightB) {
    previousBrightB = current;
    BB = BB + incrBrB;
    if ((BB>150) or (BB<50)) {incrBrB = -incrBrB;};
  }
  
  cycleColorAndBright();
  cycleColorAndBrightB();
  
}


void cycleColorAndBright(){
  leds[0] = CHSV(C,S,B);
  for (int i = 1; i < 20; i++){
    if ( (i % 2) == 0) {
      leds[i] = leds[0];
    }
  };
  FastLED.show();
}

void cycleColorAndBrightB(){
  leds[1] = CHSV(CB,S,BB);
  for (int i = 1; i < 20; i++){
    if ( (i % 2) != 0) {
      leds[i] = leds[1];
    }
  };
  FastLED.show();
}

