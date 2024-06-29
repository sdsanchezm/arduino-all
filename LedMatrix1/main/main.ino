#include "Arduino_LED_Matrix.h"
#include "fonts.h"
ArduinoLEDMatrix matrix;

uint8_t ledsTable[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void setup() {
  Serial.begin(115200);
  // delay(1500);
  matrix.begin();
}

const uint32_t happy[] = {
    0x19819,
    0x80000001,
    0x81f8000
};

const uint32_t heart[] = {
    0x3184a444,
    0x44042081,
    0x100a0040
};

// 3184A44442081100A0040000

// Example
// 0011 0001 1000 318
// 0100 1010 0100 4A4

// 000000000000
// 000000100100
// 010001000100 
// 001000001000
// 000100010000
// 000010100000
// 000001000000
// 000000000000

// powershell to convert binary to hex
// $number = [Convert]::ToInt32('001100011000', 2) | ForEach-Object { Write-Host $_.ToString('X') }

void loop() {

  // for (char c = 'A'; c <= 'Z'; c++) {
  //   clear_ledsTable();
  //   add_to_ledsTable(c, 5);
  //   display_ledsTable();
  //   delay(1000);
  // }

  uint8_t pub[5] = { 'L', 'I', 'N', 'U', 'X' };

  for (uint8_t i = 0; i < 5; i++) {
    clear_ledsTable();
    add_to_ledsTable(pub[i], i);
    display_ledsTable();
    delay(1000);
  }

// only leds sequentially ==============
  // for (uint8_t i = 0; i < 96; i ++)
  // {
  //   matrix.on(i);
  //   delay(100);
  // }

// loading 2 frames ==============
  // matrix.loadFrame(happy);
  // delay(1000);

  // matrix.loadFrame(heart);
  // delay(1000);

}

void clear_ledsTable() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 12; col++) {
      ledsTable[row][col] = 0;
    }
  }
}

void display_ledsTable() {
  matrix.renderBitmap(ledsTable, 8, 12);
}

void add_to_ledsTable(char c, int pos) {
  int index = -1;
  if (c >= '0' && c <= '9')
    index = c - '0';
  else if (c >= 'A' && c <= 'Z')
    index = c - 'A' + 10;
  else {
    Serial.println("WARNING: unsupported character");
    return;
  }

  for (int row = 0; row < 8; row++)
  {
    uint32_t temp = fonts[index][row] << (7 - pos);

    for (int col = 0; col < 12; col++)
    {
      ledsTable[row][col] |= (temp >> (11 - col)) & 1;
    }
  }
}
