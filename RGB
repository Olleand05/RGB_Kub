// Blinks an LED attached to a green3XXX pin.

// ok to include only the one needed
// both included here to make things simple for example
#include <Adafruit_MCP23X17.h>

// initiera lager
const char layer1 = A3;
const char layer2 = A2;
const char layer3 = A1;
const char layer4 = A0;

// initiera knapp-inputs
const char fun1in = 13;
const char fun2in = 12;
const char fun3in = 11;
const char fun4in = 10;

const char forward = 7;
const char right = 6;
const char backward = 5;
const char left = 4;
const char up = 2;
const char down = 3;

// initiera state
int state = 0;

// initiera variabel för delay
int fun1tick = 200;

// uncomment appropriate line
//Adafruit_green3X08 mcp;
Adafruit_MCP23X17 red;
Adafruit_MCP23X17 green;
Adafruit_MCP23X17 blue;

// 2d array för MCP23017 inputs

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

  red.begin_I2C(0x26);
  green.begin_I2C(0x24);
  blue.begin_I2C(0x20);

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

  pinMode(forward, INPUT_PULLUP);
  pinMode(backward, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);
  pinMode(left, INPUT_PULLUP);
  pinMode(up, INPUT_PULLUP);
  pinMode(down,INPUT_PULLUP);

  pinMode(fun1in, INPUT_PULLUP);
  pinMode(fun2in, INPUT_PULLUP);
  pinMode(fun3in, INPUT_PULLUP);
  pinMode(fun4in, INPUT_PULLUP);

  digitalWrite(layer1, LOW);
  digitalWrite(layer2, LOW);
  digitalWrite(layer3, LOW);
  digitalWrite(layer4, LOW);
}

void loop() {
  allOff();

  // kollar om knapparna är nedtryckta
  if (digitalRead(fun1in) == LOW) {
    state = 1;
  }
  if (digitalRead(fun2in) == LOW) {
    state = 2;
  }
  if (digitalRead(fun3in) == LOW) {
    state = 3;
  }
  if (digitalRead(fun4in) == LOW) {
    state = 4;
  }

  if (state == 0) {
    allOff();
  }
  if (state == 1) {
    function1();
  }
  if (state == 2) {
    function2();
  }
  if (state == 3) {
    function3();
  }
  if (state == 4) {
    function4();
  }
}


void function1() {
  digitalWrite(layer1, HIGH);
  function1rainbowcorner();
  allOff();

  digitalWrite(layer1, HIGH);
  digitalWrite(layer2, HIGH);
  function1rainbowcorner();
  allOff();

  digitalWrite(layer1, HIGH);
  digitalWrite(layer2, HIGH);
  digitalWrite(layer3, HIGH);
  function1rainbowcorner();
  allOff();

  digitalWrite(layer1, HIGH);
  digitalWrite(layer2, HIGH);
  digitalWrite(layer3, HIGH);
  digitalWrite(layer4, HIGH);
  function1rainbowcorner();
  allOff();

  function1rainbowspin();
  function1rainbowspin();
  function1rainbowspin();
  function1rainbowspin();
  function1rainbowspin();

  function1upanddown();
  function1upanddown();
  function1upanddown();

  digitalWrite(layer1, HIGH);
  function1zigzagforward();

  digitalWrite(layer2, HIGH);
  function1zigzagbackward();

  digitalWrite(layer3, HIGH);
  function1zigzagforward();

  digitalWrite(layer4, HIGH);
  function1zigzagbackward();

  state = 0;
}

void function1rainbowcorner() {
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

void function1rainbowspin() {
  digitalWrite(layer1, HIGH);
  for (int i = 0; i < 4; i++) {
    red.digitalWrite(layerRed[i][0], LOW);
  }
  delay(fun1tick / 3);
  allColumnsOff();

  for (int i = 0; i < 4; i++) {
    green.digitalWrite(layerGreen[i][1], LOW);
  }
  delay(fun1tick / 3);
  allColumnsOff();

  for (int i = 0; i < 4; i++) {
    blue.digitalWrite(layerBlue[i][2], LOW);
  }
  delay(fun1tick / 3);
  allColumnsOff();

  for (int i = 0; i < 4; i++) {
    red.digitalWrite(layerRed[i][3], LOW);
  }
  delay(fun1tick / 3);
  allColumnsOff();

  digitalWrite(layer1, LOW);
  digitalWrite(layer2, HIGH);
  for (int i = 0; i < 4; i++) {
    green.digitalWrite(layerGreen[i][3], LOW);
  }
  delay(fun1tick / 3);
  allColumnsOff();

  digitalWrite(layer2, LOW);
  digitalWrite(layer3, HIGH);
  for (int i = 0; i < 4; i++) {
    blue.digitalWrite(layerBlue[i][3], LOW);
  }
  delay(fun1tick / 3);
  allColumnsOff();

  digitalWrite(layer3, LOW);
  digitalWrite(layer4, HIGH);
  for (int i = 0; i < 4; i++) {
    red.digitalWrite(layerRed[i][3], LOW);
  }
  delay(fun1tick / 3);
  allColumnsOff();

  for (int i = 0; i < 4; i++) {
    green.digitalWrite(layerGreen[i][2], LOW);
  }
  delay(fun1tick / 3);
  allColumnsOff();

  for (int i = 0; i < 4; i++) {
    blue.digitalWrite(layerBlue[i][1], LOW);
  }
  delay(fun1tick / 3);
  allColumnsOff();

  for (int i = 0; i < 4; i++) {
    red.digitalWrite(layerRed[i][0], LOW);
  }
  delay(fun1tick / 3);
  allColumnsOff();

  digitalWrite(layer4, LOW);
  digitalWrite(layer3, HIGH);
  for (int i = 0; i < 4; i++) {
    green.digitalWrite(layerGreen[i][0], LOW);
  }
  delay(fun1tick / 3);
  allColumnsOff();

  digitalWrite(layer3, LOW);
  digitalWrite(layer2, HIGH);
  for (int i = 0; i < 4; i++) {
    blue.digitalWrite(layerBlue[i][0], LOW);
  }
  delay(fun1tick / 3);
  allOff();
}

void function1upanddown() {
  digitalWrite(layer1, HIGH);
  for (int i = 1; i < 3; i++) {
    red.digitalWrite(layerRed[i][1], LOW);
  }
  for (int i = 1; i < 3; i++) {
    red.digitalWrite(layerRed[i][2], LOW);
  }
  delay(fun1tick / 2);
  allOff();

  digitalWrite(layer2, HIGH);
  for (int i = 1; i < 3; i++) {
    green.digitalWrite(layerGreen[i][1], LOW);
  }
  for (int i = 1; i < 3; i++) {
    green.digitalWrite(layerGreen[i][2], LOW);
  }
  delay(fun1tick / 2);
  allOff();

  digitalWrite(layer3, HIGH);
  for (int i = 1; i < 3; i++) {
    blue.digitalWrite(layerBlue[i][1], LOW);
  }
  for (int i = 1; i < 3; i++) {
    blue.digitalWrite(layerBlue[i][2], LOW);
  }
  delay(fun1tick / 2);
  allOff();

  digitalWrite(layer4, HIGH);
  for (int i = 1; i < 3; i++) {
    red.digitalWrite(layerRed[i][1], LOW);
  }
  for (int i = 1; i < 3; i++) {
    red.digitalWrite(layerRed[i][2], LOW);
  }
  delay(fun1tick / 2);
  allOff();

  digitalWrite(layer4, HIGH);
  allColumnsOff();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      red.digitalWrite(layerRed[i][j], LOW);
    }
  }
  delay(fun1tick / 2);
  allOff();

  digitalWrite(layer3, HIGH);
  allColumnsOff();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      blue.digitalWrite(layerRed[i][j], LOW);
    }
  }
  delay(fun1tick / 2);
  allOff();

  digitalWrite(layer2, HIGH);
  allColumnsOff();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      green.digitalWrite(layerGreen[i][j], LOW);
    }
  }
  delay(fun1tick / 2);
  allOff();

  digitalWrite(layer1, HIGH);
  allColumnsOff();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      red.digitalWrite(layerRed[i][j], LOW);
    }
  }
  delay(fun1tick / 2);
  allOff();
}

void function1zigzagforward() {
  allColumnsOff();
  red.digitalWrite(layerRed[0][0], LOW);
  delay(fun1tick / 2);

  green.digitalWrite(layerGreen[1][0], LOW);
  delay(fun1tick / 2);

  blue.digitalWrite(layerBlue[2][0], LOW);
  delay(fun1tick / 2);

  red.digitalWrite(layerRed[3][0], LOW);
  delay(fun1tick / 2);

  green.digitalWrite(layerGreen[3][1], LOW);
  delay(fun1tick / 2);

  blue.digitalWrite(layerBlue[2][1], LOW);
  delay(fun1tick / 2);

  red.digitalWrite(layerRed[1][1], LOW);
  delay(fun1tick / 2);

  green.digitalWrite(layerGreen[0][1], LOW);
  delay(fun1tick / 2);

  blue.digitalWrite(layerBlue[0][2], LOW);
  delay(fun1tick / 2);

  red.digitalWrite(layerRed[1][2], LOW);
  delay(fun1tick / 2);

  green.digitalWrite(layerGreen[2][2], LOW);
  delay(fun1tick / 2);

  blue.digitalWrite(layerBlue[3][2], LOW);
  delay(fun1tick / 2);

  red.digitalWrite(layerRed[3][3], LOW);
  delay(fun1tick / 2);

  green.digitalWrite(layerGreen[2][3], LOW);
  delay(fun1tick / 2);

  blue.digitalWrite(layerBlue[1][3], LOW);
  delay(fun1tick / 2);

  red.digitalWrite(layerRed[0][3], LOW);
  delay(fun1tick / 2);
}

void function1zigzagbackward() {
  allColumnsOff();
  red.digitalWrite(layerRed[0][3], LOW);
  delay(fun1tick / 2);

  blue.digitalWrite(layerBlue[1][3], LOW);
  delay(fun1tick / 2);

  green.digitalWrite(layerGreen[2][3], LOW);
  delay(fun1tick / 2);

  red.digitalWrite(layerRed[3][3], LOW);
  delay(fun1tick / 2);

  blue.digitalWrite(layerBlue[3][2], LOW);
  delay(fun1tick / 2);

  green.digitalWrite(layerGreen[2][2], LOW);
  delay(fun1tick / 2);

  red.digitalWrite(layerRed[1][2], LOW);
  delay(fun1tick / 2);

  blue.digitalWrite(layerBlue[0][2], LOW);
  delay(fun1tick / 2);

  green.digitalWrite(layerGreen[0][1], LOW);
  delay(fun1tick / 2);

  red.digitalWrite(layerRed[1][1], LOW);
  delay(fun1tick / 2);

  blue.digitalWrite(layerBlue[2][1], LOW);
  delay(fun1tick / 2);

  green.digitalWrite(layerGreen[3][1], LOW);
  delay(fun1tick / 2);

  red.digitalWrite(layerRed[3][0], LOW);
  delay(fun1tick / 2);

  blue.digitalWrite(layerBlue[2][0], LOW);
  delay(fun1tick / 2);

  green.digitalWrite(layerGreen[1][0], LOW);
  delay(fun1tick / 2);

  red.digitalWrite(layerRed[0][0], LOW);
  delay(fun1tick / 2);
}

void function2() {

  //Sets koordinates in 3d grid

  int y[] = { 0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 2, 1, 1, 1, 2, 2 };
  int x[] = { 0, 1, 2, 3, 3, 3, 3, 2, 1, 0, 0, 0, 1, 2, 2, 1 };

  //Sets layer 1 to green

  for (int i = 0; i < 16; i++) {
    digitalWrite(layer1, HIGH);
    green.digitalWrite(layerGreen[y[i]][x[i]], LOW);
    delay(50);
  }
  delay(500);
  allOff();

  //Sets layer 1 and 2 to red

  for (int i = 0; i < 16; i++) {
    digitalWrite(layer1, HIGH);
    digitalWrite(layer2, HIGH);


    red.digitalWrite(layerRed[y[i]][x[i]], LOW);
    delay(50);
  }
  delay(500);
  allOff();

  //Sets layer 1,2 and 3 to blue

  for (int i = 0; i < 16; i++) {
    digitalWrite(layer1, HIGH);
    digitalWrite(layer2, HIGH);
    digitalWrite(layer3, HIGH);


    blue.digitalWrite(layerBlue[y[i]][x[i]], LOW);
    delay(50);
  }
  delay(500);
  allOff();

  //Sets all layers to mixed color

  for (int i = 0; i < 16; i++) {
    digitalWrite(layer1, HIGH);
    digitalWrite(layer2, HIGH);
    digitalWrite(layer3, HIGH);
    digitalWrite(layer4, HIGH);


    blue.digitalWrite(layerBlue[y[i]][x[i]], LOW);
    green.digitalWrite(layerBlue[y[i]][x[i]], LOW);
    red.digitalWrite(layerBlue[y[i]][x[i]], LOW);
    delay(50);
  }


  delay(1000);

  //Back out of the cube

  for (int i = 0; i < 16; i++) {
    blue.digitalWrite(layerBlue[y[16 - i]][x[16 - i]], HIGH);
    red.digitalWrite(layerGreen[y[16 - i]][x[16 - i]], HIGH);
    green.digitalWrite(layerGreen[y[16 - i]][x[16 - i]], HIGH);
    delay(50);
  }
  state = 0;
}

void function3() {
  //stänger av alla lager
  allOff();

  //
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

  allOn();
  for (int i = 0; i < 4; i++) {
    red.digitalWrite(layerRed[0][i], LOW);
  }
  delay(200);

  for (int i = 0; i < 4; i++) {
    green.digitalWrite(layerGreen[1][i], LOW);
  }

  delay(200);

  for (int i = 0; i < 4; i++) {
    red.digitalWrite(layerRed[2][i], LOW);
    green.digitalWrite(layerGreen[2][i], HIGH);
  }

  delay(200);

  for (int i = 0; i < 4; i++) {
    green.digitalWrite(layerGreen[3][i], LOW);
  }

  delay(200);

  allOff();

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
  delay(200);

  allOff();

  allOn();
  for (int i = 0; i < 4; i++) {
    red.digitalWrite(layerRed[3][i], LOW);
  }
  delay(200);

  for (int i = 0; i < 4; i++) {
    green.digitalWrite(layerGreen[2][i], LOW);
    blue.digitalWrite(layerBlue[2][i], LOW);
    red.digitalWrite(layerRed[2][i], HIGH);
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

  for (int i = 0; i < 6; i++) {
    circle("red");
    upToDown(300 - i * 50);
    allOff();

    circle("green");
    downToUp(300 - i * 50);
    allOff();

    circle("blue");
    upToDown(300 - i * 50);
    allOff();

    circle("red");
    downToUp(300 - i * 50);
    allOff();

    circle("green");
    upToDown(300 - i * 50);
    allOff();

    circle("blue");
    downToUp(300 - i * 50);
    allOff();
  }
  function1upanddown();

  delay(250);

  for (int i = 0; i < 1000; i++) {
    rain();
  }
  state = 0;
}

void circle(String color) {
  if (color == "red") {
    red.digitalWrite(layerRed[1][0], LOW);
    red.digitalWrite(layerRed[2][0], LOW);

    red.digitalWrite(layerRed[0][1], LOW);
    red.digitalWrite(layerRed[0][2], LOW);

    red.digitalWrite(layerRed[1][3], LOW);
    red.digitalWrite(layerRed[2][3], LOW);

    red.digitalWrite(layerRed[3][1], LOW);
    red.digitalWrite(layerRed[3][2], LOW);
  }
  if (color == "green") {
    green.digitalWrite(layerGreen[1][0], LOW);
    green.digitalWrite(layerGreen[2][0], LOW);

    green.digitalWrite(layerGreen[0][1], LOW);
    green.digitalWrite(layerGreen[0][2], LOW);

    green.digitalWrite(layerGreen[1][3], LOW);
    green.digitalWrite(layerGreen[2][3], LOW);

    green.digitalWrite(layerGreen[3][1], LOW);
    green.digitalWrite(layerGreen[3][2], LOW);
  }
  if (color == "blue") {
    blue.digitalWrite(layerBlue[1][0], LOW);
    blue.digitalWrite(layerBlue[2][0], LOW);

    blue.digitalWrite(layerBlue[0][1], LOW);
    blue.digitalWrite(layerBlue[0][2], LOW);

    blue.digitalWrite(layerBlue[1][3], LOW);
    blue.digitalWrite(layerBlue[2][3], LOW);

    blue.digitalWrite(layerBlue[3][1], LOW);
    blue.digitalWrite(layerBlue[3][2], LOW);
  }
}

void upToDown(int goon) {
  digitalWrite(layer4, LOW);
  delay(goon);
  digitalWrite(layer4, HIGH);
  digitalWrite(layer3, LOW);
  delay(goon);
  digitalWrite(layer3, HIGH);
  digitalWrite(layer2, LOW);
  delay(goon);
  digitalWrite(layer2, HIGH);
  digitalWrite(layer1, LOW);
  delay(goon);
  digitalWrite(layer1, HIGH);
  delay(goon);
}

void downToUp(int bust) {
  digitalWrite(layer1, LOW);
  delay(bust);
  digitalWrite(layer1, HIGH);
  digitalWrite(layer2, LOW);
  delay(bust);
  digitalWrite(layer2, HIGH);
  digitalWrite(layer3, LOW);
  delay(bust);
  digitalWrite(layer3, HIGH);
  digitalWrite(layer4, LOW);
  delay(bust);
  digitalWrite(layer4, HIGH);
  delay(bust);
}




void rain() {
  allOff();
  //std::list<Type> colors = {"red","green,blue"}
  int randCol = rand() % 3;
  int randX = rand() % 4;
  int randY = rand() % 4;

  if (randCol == 0) {
    red.digitalWrite(layerRed[randX][randY], LOW);
  }

  if (randCol == 1) {
    green.digitalWrite(layerGreen[randX][randY], LOW);
  }

  if (randCol == 2) {
    blue.digitalWrite(layerBlue[randX][randY], LOW);
  }


  digitalWrite(layer4, HIGH);
  delay(20);

  digitalWrite(layer4, LOW);
  digitalWrite(layer3, HIGH);
  delay(20);

  digitalWrite(layer3, LOW);
  digitalWrite(layer2, HIGH);
  delay(20);

  digitalWrite(layer2, LOW);
  digitalWrite(layer1, HIGH);
  delay(20);

  allOff();
  allOn();
  for(int i; i<4;i++){
    for(int j; j<4;j++){
      
  if (randCol == 0) {
    red.digitalWrite(layerRed[i][j],LOW);
  }

  if (randCol == 1) {
    green.digitalWrite(layerGreen[i][j],LOW);
  }

  if (randCol == 2) {
    blue.digitalWrite(layerBlue[i][j],LOW);
  }
    }
  }
  delay(20);
  allOff();
}


void function4() {
  int z = 1;
  int x = 0;
  int y = 0;
  int oy = 0;
  int ox = 0;

  allOff();
  while (true) {

    if (digitalRead(right) == LOW && x < 3) {
      ox = x;
      x += 1;
      Serial.print("x++");
    }
    if (digitalRead(left) == LOW && x >= 0) {
      ox = x;
      x -= 1;
      Serial.print("x--");
    }
    if (digitalRead(forward) == LOW && y >= 0) {
      oy = y;
      y -= 1;
      Serial.print("y--");
    }
    if (digitalRead(backward) == LOW && y < 3) {
      oy = y;
      y += 1;
      Serial.print("y++");
    }
    if (digitalRead(up) == LOW && z < 4) {
      z += 1;
      Serial.print("z++");
    }
    if (digitalRead(down) == LOW && z >= 0) {
      z -= 1;
      Serial.print("z--");
    }


    green.digitalWrite(layerGreen[ox][oy], HIGH);
    green.digitalWrite(layerGreen[x][y], LOW);
    if (z == 1) {
      digitalWrite(layer1, HIGH);
      digitalWrite(layer2, LOW);
      digitalWrite(layer3, LOW);
      digitalWrite(layer4, LOW);
    }
    if (z == 2) {
      digitalWrite(layer1, LOW);
      digitalWrite(layer2, HIGH);
      digitalWrite(layer3, LOW);
      digitalWrite(layer4, LOW);
    }
    if (z == 3) {
      digitalWrite(layer1, LOW);
      digitalWrite(layer2, LOW);
      digitalWrite(layer3, HIGH);
      digitalWrite(layer4, LOW);
    }
    if (z == 4) {
      digitalWrite(layer1, LOW);
      digitalWrite(layer2, LOW);
      digitalWrite(layer3, LOW);
      digitalWrite(layer4, HIGH);
    }
  }
}

void allOn() {
  digitalWrite(layer1, HIGH);
  digitalWrite(layer2, HIGH);
  digitalWrite(layer3, HIGH);
  digitalWrite(layer4, HIGH);
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
