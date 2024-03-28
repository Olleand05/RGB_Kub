// Blinks an LED attached to a green3XXX pin.

// ok to include only the one needed
// both included here to make things simple for example
#include <Adafruit_MCP23X17.h>


// uncomment appropriate line
//Adafruit_green3X08 mcp;
Adafruit_MCP23X17 red;
Adafruit_MCP23X17 green;
Adafruit_MCP23X17 blue;

int Level[] = {4,5,6,7};
int LampTower[4][4]={
  {0,0,0,0},
  {0,0,0,0},
  {0,0,0,0},
  {0,0,0,0}
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
  for (int i = 0; i < 16; i++) {
    red.digitalWrite(i, HIGH);
  }
  for (int i = 0; i < 16; i++) {
    green.digitalWrite(i, HIGH);
  }
  for (int i = 0; i < 16; i++) {
    blue.digitalWrite(i, LOW);
  }
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

void LightAllLamps(){

}