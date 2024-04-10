// Blinks an LED attached to a green3XXX pin.

// ok to include only the one needed
// both included here to make things simple for example
#include <Adafruit_MCP23X17.h>

// initiera lager
const char layer1 = 4;
const char layer2 = 5;
const char layer3 = 6;
const char layer4 = 7;

// initiera knapp-inputs
const char fun1in = 13;
const char fun2in = 12;
const char fun3in = 11;

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

  pinMode(fun1in, INPUT_PULLUP);
  pinMode(fun2in, INPUT_PULLUP);
  pinMode(fun3in, INPUT_PULLUP);

  digitalWrite(layer1, LOW);
  digitalWrite(layer2, LOW);
  digitalWrite(layer3, LOW);
  digitalWrite(layer4, LOW);
}

void loop() {
  allOff();

  // kollar om knapparna är nedtryckta
  if(digitalRead(fun1in) == LOW ) {
    state = 1;
  }
  if(digitalRead(fun2in) == LOW ) {
    state = 2;
  }
  if(digitalRead(fun3in) == LOW ) {
    state = 3;
  }

  if ( state == 0) {
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
  for (int i = 0; i<4; i++) {
    red.digitalWrite(layerRed[i][0], LOW);
  }
  delay(fun1tick/3);
  allColumnsOff();

  for (int i = 0; i<4; i++) {
    green.digitalWrite(layerGreen[i][1], LOW);
  }
  delay(fun1tick/3);
  allColumnsOff();

  for (int i = 0; i<4; i ++) {
    blue.digitalWrite(layerBlue[i][2], LOW);
  }
  delay(fun1tick/3);
  allColumnsOff();

  for (int i = 0; i<4; i ++) {
    red.digitalWrite(layerRed[i][3], LOW);
  }
  delay(fun1tick/3);
  allColumnsOff();

  digitalWrite(layer1, LOW);
  digitalWrite(layer2, HIGH);
  for (int i = 0; i<4; i ++) {
    green.digitalWrite(layerGreen[i][3], LOW);
  }
  delay(fun1tick/3);
  allColumnsOff();

  digitalWrite(layer2, LOW);
  digitalWrite(layer3, HIGH);
  for (int i = 0; i<4; i ++) {
    blue.digitalWrite(layerBlue[i][3], LOW);
  }
  delay(fun1tick/3);
  allColumnsOff();

  digitalWrite(layer3, LOW);
  digitalWrite(layer4, HIGH);
  for (int i = 0; i<4; i ++) {
    red.digitalWrite(layerRed[i][3], LOW);
  }
  delay(fun1tick/3);
  allColumnsOff();

  for (int i = 0; i<4; i ++) {
    green.digitalWrite(layerGreen[i][2], LOW);
  }
  delay(fun1tick/3);
  allColumnsOff();

  for (int i = 0; i<4; i ++) {
    blue.digitalWrite(layerBlue[i][1], LOW);
  }
  delay(fun1tick/3);
  allColumnsOff();

  for (int i = 0; i<4; i ++) {
    red.digitalWrite(layerRed[i][0], LOW);
  }
  delay(fun1tick/3);
  allColumnsOff();

  digitalWrite(layer4, LOW);
  digitalWrite(layer3, HIGH);
  for (int i = 0; i<4; i ++) {
    green.digitalWrite(layerGreen[i][0], LOW);
  }
  delay(fun1tick/3);
  allColumnsOff();

  digitalWrite(layer3, LOW);
  digitalWrite(layer2, HIGH);
  for (int i = 0; i<4; i ++) {
    blue.digitalWrite(layerBlue[i][0], LOW);
  }
  delay(fun1tick/3);
  allOff();
}

void function1upanddown() {
  digitalWrite(layer1, HIGH);
  for (int i = 1; i<3; i++) {
    red.digitalWrite(layerRed[i][1], LOW);
  }
  for (int i = 1; i<3; i++) {
    red.digitalWrite(layerRed[i][2], LOW);
  }
  delay(fun1tick/2);
  allOff();

  digitalWrite(layer2, HIGH);
  for (int i = 1; i<3; i++) {
    green.digitalWrite(layerGreen[i][1], LOW);
  }
  for (int i = 1; i<3; i++) {
    green.digitalWrite(layerGreen[i][2], LOW);
  }
  delay(fun1tick/2);
  allOff();

  digitalWrite(layer3, HIGH);
  for (int i = 1; i<3; i++) {
    blue.digitalWrite(layerBlue[i][1], LOW);
  }
  for (int i = 1; i<3; i++) {
    blue.digitalWrite(layerBlue[i][2], LOW);
  }
  delay(fun1tick/2);
  allOff();

  digitalWrite(layer4, HIGH);
  for (int i = 1; i<3; i++) {
    red.digitalWrite(layerRed[i][1], LOW);
  }
  for (int i = 1; i<3; i++) {
    red.digitalWrite(layerRed[i][2], LOW);
  }
  delay(fun1tick/2);
  allOff();

  digitalWrite(layer4, HIGH);
  allColumnsOff();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      red.digitalWrite(layerRed[i][j], LOW);
    }
  }
  delay(fun1tick/2);
  allOff();

  digitalWrite(layer3, HIGH);
  allColumnsOff();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      blue.digitalWrite(layerRed[i][j], LOW);
    }
  }
  delay(fun1tick/2);
  allOff();

  digitalWrite(layer2, HIGH);
  allColumnsOff();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      green.digitalWrite(layerGreen[i][j], LOW);
    }
  }
  delay(fun1tick/2);
  allOff();

  digitalWrite(layer1, HIGH);
  allColumnsOff();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      red.digitalWrite(layerRed[i][j], LOW);
    }
  }
  delay(fun1tick/2);
  allOff();
}

void function1zigzagforward() {
  allColumnsOff();
  red.digitalWrite(layerRed[0][0], LOW);
  delay(fun1tick/2);

  green.digitalWrite(layerGreen[1][0], LOW);
  delay(fun1tick/2);

  blue.digitalWrite(layerBlue[2][0], LOW);
  delay(fun1tick/2);

  red.digitalWrite(layerRed[3][0], LOW);
  delay(fun1tick/2);

  green.digitalWrite(layerGreen[3][1], LOW);
  delay(fun1tick/2);

  blue.digitalWrite(layerBlue[2][1], LOW);
  delay(fun1tick/2);

  red.digitalWrite(layerRed[1][1], LOW);
  delay(fun1tick/2);

  green.digitalWrite(layerGreen[0][1], LOW);
  delay(fun1tick/2);

  blue.digitalWrite(layerBlue[0][2], LOW);
  delay(fun1tick/2);

  red.digitalWrite(layerRed[1][2], LOW);
  delay(fun1tick/2);

  green.digitalWrite(layerGreen[2][2], LOW);
  delay(fun1tick/2);

  blue.digitalWrite(layerBlue[3][2], LOW);
  delay(fun1tick/2);

  red.digitalWrite(layerRed[3][3], LOW);
  delay(fun1tick/2);

  green.digitalWrite(layerGreen[2][3], LOW);
  delay(fun1tick/2);

  blue.digitalWrite(layerBlue[1][3], LOW);
  delay(fun1tick/2);

  red.digitalWrite(layerRed[0][3], LOW);
  delay(fun1tick/2);
}

void function1zigzagbackward() {
  allColumnsOff();
  red.digitalWrite(layerRed[0][3], LOW);
  delay(fun1tick/2);

  blue.digitalWrite(layerBlue[1][3], LOW);
  delay(fun1tick/2);

  green.digitalWrite(layerGreen[2][3], LOW);
  delay(fun1tick/2);

  red.digitalWrite(layerRed[3][3], LOW);
  delay(fun1tick/2);

  blue.digitalWrite(layerBlue[3][2], LOW);
  delay(fun1tick/2);

  green.digitalWrite(layerGreen[2][2], LOW);
  delay(fun1tick/2);

  red.digitalWrite(layerRed[1][2], LOW);
  delay(fun1tick/2);

  blue.digitalWrite(layerBlue[0][2], LOW);
  delay(fun1tick/2);

  green.digitalWrite(layerGreen[0][1], LOW);
  delay(fun1tick/2);

  red.digitalWrite(layerRed[1][1], LOW);
  delay(fun1tick/2);

  blue.digitalWrite(layerBlue[2][1], LOW);
  delay(fun1tick/2);

  green.digitalWrite(layerGreen[3][1], LOW);
  delay(fun1tick/2);

  red.digitalWrite(layerRed[3][0], LOW);
  delay(fun1tick/2);

  blue.digitalWrite(layerBlue[2][0], LOW);
  delay(fun1tick/2);

  green.digitalWrite(layerGreen[1][0], LOW);
  delay(fun1tick/2);

  red.digitalWrite(layerRed[0][0], LOW);
  delay(fun1tick/2);
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

  for (int i = 0; i < 3; i++) {
    circle("red");
    upToDown();
    allOff();

    circle("green");
    downToUp();
    allOff();

    circle("blue");
    upToDown();
    allOff();

    circle("red");
    downToUp();
    allOff();

    circle("green");
    upToDown();
    allOff();

    circle("blue");
    downToUp();
    allOff();
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

void upToDown() {
  digitalWrite(layer4, LOW);
  delay(100);
  digitalWrite(layer4, HIGH);
  digitalWrite(layer3, LOW);
  delay(100);
  digitalWrite(layer3, HIGH);
  digitalWrite(layer2, LOW);
  delay(100);
  digitalWrite(layer2, HIGH);
  digitalWrite(layer1, LOW);
  delay(100);
  digitalWrite(layer1, HIGH);
}

void downToUp() {
  digitalWrite(layer1, LOW);
  delay(100);
  digitalWrite(layer1, HIGH);
  digitalWrite(layer2, LOW);
  delay(100);
  digitalWrite(layer2, HIGH);
  digitalWrite(layer3, LOW);
  delay(100);
  digitalWrite(layer3, HIGH);
  digitalWrite(layer4, LOW);
  delay(100);
  digitalWrite(layer4, HIGH);
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
