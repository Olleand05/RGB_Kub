// Blinks an LED attached to a green3XXX pin.

// ok to include only the one needed
// both included here to make things simple for example
#include <Adafruit_MCP23X17.h>



Adafruit_MCP23XXX red;
Adafruit_MCP23XXX green;
Adafruit_MCP23XXX blue;

int Layer[] = { 4, 5, 6, 7 };
int LampTower[4][4] = {
  { 0, 0, 0, 0 },
  { 0, 0, 0, 0 },
  { 0, 0, 0, 0 },
  { 0, 0, 0, 0 }
};

void setup() {
  Serial.begin(9600);
  //while (!Serial);
  Serial.println("green3xxx Blink Test!");

  // uncomment appropriate mcp.begin
  red.begin_I2C(0x26);
  green.begin_I2C(0x24);
  blue.begin_I2C(0x20);

  // configure pin for output
  for (int i = 0; i < 16; i++) {
    red.pinMode(i, HIGH);
  }
  for (int i = 0; i < 16; i++) {
    green.pinMode(i, HIGH);
  }
  for (int i = 0; i < 16; i++) {
    blue.pinMode(i, HIGH);
  }
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  Serial.println("Looping...");
}

void loop() {
  LightAllLamps(false, false, true);
}

void LightAllLamps(bool redB, bool blueB, bool greenB) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(Layer[i], HIGH);
  }
  for (int i = 0; i < 16; i++) {
    if (redB == true) {
      red.digitalWrite(i, LOW);
    }
    if (blueB == true) {
      blue.digitalWrite(i, LOW);
    }
    if (greenB == true) {
      green.digitalWrite(i, LOW);
    }
  }
}
