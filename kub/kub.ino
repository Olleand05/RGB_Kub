// Blinks an LED attached to a green3XXX pin.

// ok to include only the one needed
// both included here to make things simple for example
#include <Adafruit_MCP23X17.h>

const char layer1 = 4;
const char layer2 = 5;
const char layer3 = 6;
const char layer4 = 7;

int fun1tick = 200;
int timer1 = 0;

// uncomment appropriate line
//Adafruit_green3X08 mcp;
Adafruit_MCP23X17 red;
Adafruit_MCP23X17 green;
Adafruit_MCP23X17 blue;

int layerRed[4][4] = {
  { 2, 4, 10, 11 },
  { 3, 0, 6, 12 },
  { 14, 15, 7, 9 },
  { 1, 13, 5, 8 }
};

int layerGreen[4][4] = {
  { 2, 5, 0, 1 },
  { 8, 10, 7, 14 },
  { 9, 15, 12, 3 },
  { 11, 6, 4, 13 }
};

int layerBlue[4][4] = {
  { 6, 0, 1, 2 },
  { 7, 13, 8, 9 },
  { 3, 4, 11, 12 },
  { 5, 15, 14, 10 }
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
    red.pinMode(i, OUTPUT);
  }
  for (int i = 0; i < 16; i++) {
    green.pinMode(i, OUTPUT);
  }
  for (int i = 0; i < 16; i++) {
    blue.pinMode(i, OUTPUT);
  }
  pinMode(layer1, OUTPUT);
  pinMode(layer2, OUTPUT);
  pinMode(layer3, OUTPUT);
  pinMode(layer4, OUTPUT);

  digitalWrite(layer1, LOW);
  digitalWrite(layer2, LOW);
  digitalWrite(layer3, LOW);
  digitalWrite(layer4, LOW);
}

void loop() {
  allOff();
  //function1();

  //lightSomeLampsPatternByOlleSigmaLord();

  crazyFrog();
}

void LightAllLamps() {
}

void function1() {
  digitalWrite(layer1, HIGH);
  function1pattern();
  allOff();

  digitalWrite(layer1, HIGH);
  digitalWrite(layer2, HIGH);
  function1pattern();
  allOff();

  digitalWrite(layer1, HIGH);
  digitalWrite(layer2, HIGH);
  digitalWrite(layer3, HIGH);
  function1pattern();
  allOff();

  digitalWrite(layer1, HIGH);
  digitalWrite(layer2, HIGH);
  digitalWrite(layer3, HIGH);
  digitalWrite(layer4, HIGH);
  function1pattern();
  allOff();
}

void function1pattern() {
  allColumnsOff();
  red.digitalWrite(layerRed[0][0], LOW);
  delay(fun1tick);

  allColumnsOff();
  green.digitalWrite(layerGreen[0][0], LOW);
  red.digitalWrite(layerRed[1][0], LOW);
  red.digitalWrite(layerRed[0][1], LOW);
  delay(fun1tick);

  allColumnsOff();
  blue.digitalWrite(layerBlue[0][0], LOW);
  green.digitalWrite(layerGreen[1][0], LOW);
  green.digitalWrite(layerGreen[0][1], LOW);
  red.digitalWrite(layerRed[2][0], LOW);
  red.digitalWrite(layerRed[1][1], LOW);
  red.digitalWrite(layerRed[0][2], LOW);
  delay(fun1tick);

  allColumnsOff();
  red.digitalWrite(layerRed[0][0], LOW);
  blue.digitalWrite(layerBlue[1][0], LOW);
  blue.digitalWrite(layerBlue[0][1], LOW);
  green.digitalWrite(layerGreen[2][0], LOW);
  green.digitalWrite(layerGreen[1][1], LOW);
  green.digitalWrite(layerGreen[0][2], LOW);
  red.digitalWrite(layerRed[3][0], LOW);
  red.digitalWrite(layerRed[0][3], LOW);
  red.digitalWrite(layerRed[2][1], LOW);
  red.digitalWrite(layerRed[1][2], LOW);
  delay(fun1tick);

  allColumnsOff();
  green.digitalWrite(layerGreen[0][0], LOW);
  red.digitalWrite(layerRed[1][0], LOW);
  red.digitalWrite(layerRed[0][1], LOW);
  blue.digitalWrite(layerBlue[2][0], LOW);
  blue.digitalWrite(layerBlue[1][1], LOW);
  blue.digitalWrite(layerBlue[0][2], LOW);
  green.digitalWrite(layerGreen[3][0], LOW);
  green.digitalWrite(layerGreen[0][3], LOW);
  green.digitalWrite(layerGreen[2][1], LOW);
  green.digitalWrite(layerGreen[1][2], LOW);
  red.digitalWrite(layerRed[3][1], LOW);
  red.digitalWrite(layerRed[1][3], LOW);
  red.digitalWrite(layerRed[2][2], LOW);
  delay(fun1tick);

  allColumnsOff();
  blue.digitalWrite(layerBlue[0][0], LOW);
  green.digitalWrite(layerGreen[1][0], LOW);
  green.digitalWrite(layerGreen[0][1], LOW);
  red.digitalWrite(layerRed[2][0], LOW);
  red.digitalWrite(layerRed[1][1], LOW);
  red.digitalWrite(layerRed[0][2], LOW);
  blue.digitalWrite(layerBlue[3][0], LOW);
  blue.digitalWrite(layerBlue[0][3], LOW);
  blue.digitalWrite(layerBlue[2][1], LOW);
  blue.digitalWrite(layerBlue[1][2], LOW);
  green.digitalWrite(layerGreen[3][1], LOW);
  green.digitalWrite(layerGreen[1][3], LOW);
  green.digitalWrite(layerGreen[2][2], LOW);
  red.digitalWrite(layerRed[2][3], LOW);
  red.digitalWrite(layerRed[3][2], LOW);
  delay(fun1tick);

  allColumnsOff();
  red.digitalWrite(layerRed[0][0], LOW);
  blue.digitalWrite(layerBlue[1][0], LOW);
  blue.digitalWrite(layerBlue[0][1], LOW);
  green.digitalWrite(layerGreen[2][0], LOW);
  green.digitalWrite(layerGreen[1][1], LOW);
  green.digitalWrite(layerGreen[0][2], LOW);
  red.digitalWrite(layerRed[3][0], LOW);
  red.digitalWrite(layerRed[0][3], LOW);
  red.digitalWrite(layerRed[2][1], LOW);
  red.digitalWrite(layerRed[1][2], LOW);
  blue.digitalWrite(layerBlue[3][1], LOW);
  blue.digitalWrite(layerBlue[1][3], LOW);
  blue.digitalWrite(layerBlue[2][2], LOW);
  green.digitalWrite(layerGreen[2][3], LOW);
  green.digitalWrite(layerGreen[3][2], LOW);
  red.digitalWrite(layerRed[3][3], LOW);
  delay(fun1tick);

  allColumnsOff();
  green.digitalWrite(layerGreen[0][0], LOW);
  red.digitalWrite(layerRed[1][0], LOW);
  red.digitalWrite(layerRed[0][1], LOW);
  blue.digitalWrite(layerBlue[2][0], LOW);
  blue.digitalWrite(layerBlue[1][1], LOW);
  blue.digitalWrite(layerBlue[0][2], LOW);
  green.digitalWrite(layerGreen[3][0], LOW);
  green.digitalWrite(layerGreen[0][3], LOW);
  green.digitalWrite(layerGreen[2][1], LOW);
  green.digitalWrite(layerGreen[1][2], LOW);
  red.digitalWrite(layerRed[3][1], LOW);
  red.digitalWrite(layerRed[1][3], LOW);
  red.digitalWrite(layerRed[2][2], LOW);
  blue.digitalWrite(layerBlue[2][3], LOW);
  blue.digitalWrite(layerBlue[3][2], LOW);
  green.digitalWrite(layerGreen[3][3], LOW);
  delay(fun1tick);

  allColumnsOff();
  blue.digitalWrite(layerBlue[0][0], LOW);
  green.digitalWrite(layerGreen[1][0], LOW);
  green.digitalWrite(layerGreen[0][1], LOW);
  red.digitalWrite(layerRed[2][0], LOW);
  red.digitalWrite(layerRed[1][1], LOW);
  red.digitalWrite(layerRed[0][2], LOW);
  blue.digitalWrite(layerBlue[3][0], LOW);
  blue.digitalWrite(layerBlue[0][3], LOW);
  blue.digitalWrite(layerBlue[2][1], LOW);
  blue.digitalWrite(layerBlue[1][2], LOW);
  green.digitalWrite(layerGreen[3][1], LOW);
  green.digitalWrite(layerGreen[1][3], LOW);
  green.digitalWrite(layerGreen[2][2], LOW);
  red.digitalWrite(layerRed[2][3], LOW);
  red.digitalWrite(layerRed[3][2], LOW);
  blue.digitalWrite(layerBlue[3][3], LOW);
  delay(fun1tick);
}

void lightSomeLampsPatternByOlleSigmaLord() {
  digitalWrite(layer1, HIGH);
  digitalWrite(layer2, HIGH);
  digitalWrite(layer3, HIGH);
  digitalWrite(layer4, HIGH);

  int y[] = { 0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 2, 1, 1, 1, 2, 2 };
  int x[] = { 0, 1, 2, 3, 3, 3, 3, 2, 1, 0, 0, 0, 1, 2, 2, 1 };

  for (int i = 0; i < 16; i++) {
    blue.digitalWrite(layerBlue[y[i]][x[i]], HIGH);
    green.digitalWrite(layerGreen[y[i]][x[i]], LOW);
    delay(200);
  }
  delay(500);
  for (int i = 0; i < 16; i++) {
    green.digitalWrite(layerGreen[y[i]][x[i]], HIGH);
    red.digitalWrite(layerRed[y[i]][x[i]], LOW);
    delay(200);
  }
  delay(500);
  for (int i = 0; i < 16; i++) {
    red.digitalWrite(layerRed[y[i]][x[i]], HIGH);
    blue.digitalWrite(layerBlue[y[i]][x[i]], LOW);
    delay(200);
  }
} 

void crazyFrog() {
  digitalWrite(layer1, LOW);
  digitalWrite(layer2, LOW);
  digitalWrite(layer3, LOW);
  digitalWrite(layer4, LOW);

  digitalWrite(layer4, HIGH);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      blue.digitalWrite(layerBlue[i][j], LOW);
    }
  }

  delay(200);

  digitalWrite(layer4, LOW);
  digitalWrite(layer3, HIGH);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      green.digitalWrite(layerBlue[i][j], LOW);
      blue.digitalWrite(layerBlue[i][j], LOW);
    }
  }

  delay(200);

  digitalWrite(layer3, LOW);
  digitalWrite(layer2, HIGH);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      green.digitalWrite(layerBlue[i][j], HIGH);
      blue.digitalWrite(layerBlue[i][j], LOW);
    }
  }

  delay(200);

  digitalWrite(layer2, LOW);
  digitalWrite(layer1, HIGH);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      green.digitalWrite(layerGreen[i][j], LOW);
      blue.digitalWrite(layerBlue[i][j], LOW);
    }
  }

  delay(200);
  allOff();

  digitalWrite(layer1, HIGH);
  digitalWrite(layer2, HIGH);
  digitalWrite(layer3, HIGH);
  digitalWrite(layer4, HIGH);


  for(int i = 0; i<4;i++){
    red.digitalWrite(layerRed[0][i], LOW);
  }
  delay(200);

  for(int i = 0; i<4;i++){
    green.digitalWrite(layerGreen[1][i], LOW);
  }

  delay(200);

  for(int i = 0; i<4;i++){
    red.digitalWrite(layerRed[2][i], LOW);
    green.digitalWrite(layerGreen[2][i], HIGH);
  }

  delay(200);

  for(int i = 0; i<4;i++){
    green.digitalWrite(layerGreen[3][i], LOW);
  }

  delay(200); 

  allOff();

  delay(200);

  digitalWrite(layer1, HIGH);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      blue.digitalWrite(layerBlue[i][j], LOW);
    }
  }

  delay(200);

  digitalWrite(layer1, LOW);
  digitalWrite(layer2, HIGH);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      green.digitalWrite(layerGreen[i][j], LOW);
      blue.digitalWrite(layerBlue[i][j], HIGH);
    }
  }

  delay(200);

  digitalWrite(layer2, LOW);
  digitalWrite(layer3, HIGH);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      green.digitalWrite(layerGreen[i][j], HIGH);
      blue.digitalWrite(layerBlue[i][j], LOW);
    }
  }

  delay(200);

  digitalWrite(layer3, LOW);
  digitalWrite(layer4, HIGH);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      green.digitalWrite(layerGreen[i][j], LOW);
      blue.digitalWrite(layerBlue[i][j], HIGH);
    }
  }

  allOff();

  for (int i = 0; i < 4; i++) {
    red.digitalWrite(layerRed[3][i], LOW);
  }
  delay(200);

  for (int i = 0; i < 4; i++) {
    green.digitalWrite(layerGreen[2][i], LOW);
    blue.digitalWrite(layerBlue[2][i], LOW);
    red.digitalWrite(layerRed[2] [i], HIGH);
  }

  delay(200);

  for (int i = 0; i < 4; i++) {
   green.digitalWrite(layerGreen[1][i], HIGH);
    blue.digitalWrite(layerBlue[1][i], HIGH);
    red.digitalWrite(layerRed[1][i], LOW);
  }

  delay(200);

  for (int i = 0; i < 4; i++) {
    green.digitalWrite(layerGreen[0][i], LOW);
    blue.digitalWrite(layerBlue[0][i], LOW);
    red.digitalWrite(layerRed[0][i], HIGH);
  }

  delay(200);

  allOff();
}



void testOrderBlue() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      blue.digitalWrite(layerBlue[i][j], LOW);
      delay(400);
    }
  }
}
void testOrderRed() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      red.digitalWrite(layerRed[i][j], LOW);
      delay(400);
    }
  }
}
void testOrderGreen() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      green.digitalWrite(layerGreen[i][j], LOW);
      delay(400);
    }
  }
}

void allOff() {
  for (int i = 0; i < 16; i++) {
    red.digitalWrite(i, HIGH);
  }
  for (int i = 0; i < 16; i++) {
    green.digitalWrite(i, HIGH);
  }
  for (int i = 0; i < 16; i++) {
    blue.digitalWrite(i, HIGH);
  }
  digitalWrite(layer1, LOW);
  digitalWrite(layer2, LOW);
  digitalWrite(layer3, LOW);
  digitalWrite(layer4, LOW);
}

void allColumnsOff() {
  for (int i = 0; i < 16; i++) {
    red.digitalWrite(i, HIGH);
  }
  for (int i = 0; i < 16; i++) {
    green.digitalWrite(i, HIGH);
  }
  for (int i = 0; i < 16; i++) {
    blue.digitalWrite(i, HIGH);
  }
  
}
