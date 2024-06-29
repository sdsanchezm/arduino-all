#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

void setup() {
  Serial.begin(115200);
  matrix.begin();
}

// this is the initialization of all leds
uint8_t frame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

// this is just to clear all leds to 0
uint8_t blankFrame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void leftEye() {
  //Left eye
  frame[1][3] = 1;
  frame[1][4] = 1;
  frame[2][3] = 1;
  frame[2][4] = 1;
}

void wink() {
  //Wink with the left eye
  frame[1][3] = 0;
  frame[1][4] = 0;
  frame[2][3] = 1;
  frame[2][4] = 1;
}

void rightEye() {
  //Right eye
  frame[1][8] = 1;
  frame[1][9] = 1;
  frame[2][8] = 1;
  frame[2][9] = 1;
}

void oneblink(uint8_t x, uint8_t y) {
  frame[y][x] = 1;
}

void mouth() {
  //Mouth
  frame[5][3] = 1;
  frame[5][9] = 1;
  frame[6][3] = 1;
  frame[6][4] = 1;
  frame[6][5] = 1;
  frame[6][6] = 1;
  frame[6][7] = 1;
  frame[6][8] = 1;
  frame[6][9] = 1;
}

void loop()
{
  // leftEye();
  // rightEye();
  // mouth();

  // matrix.renderBitmap(frame, 8, 12);

  // delay(1000);
  // wink();

  // matrix.renderBitmap(frame, 8, 12);
  // delay(1000);

  for (uint8_t i = 0; i < 12; i++)
  {
    for (uint8_t j = 0; j < 8; j++)
    {
      delay(100);
      if (frame[j][i] == 1)
      {
        frame[j][i] = 0;
      }
      else
      {
        frame[j][i] = 1;
      }
      matrix.renderBitmap(frame, 8, 12);
    }
  }

  for (uint8_t j = 0; j < 8; j++)
  {
    for (uint8_t i = 0; i < 12; i++)
    {
      delay(100);
      if (frame[j][i] == 1)
      {
        frame[j][i] = 0;
      }
      else
      {
        frame[j][i] = 1;
      }
      matrix.renderBitmap(frame, 8, 12);
    }
  }

  // matrix.renderBitmap(blankFrame, 8, 12);
  delay(100);
}
