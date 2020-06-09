/*
   Simple state machine for control of inputs / outputs
   Teaches students enums and switch case (vs. long if) statements
*/

// What states can our output have? for LEDs this might be brightness levels, patterns, etc.
enum OUTPUTSTATE {OFF, RIGHT, LEFT, STRAIGHT};
enum INPUTSTATE {BASE, COLD, WARM, HOT};

// We want to keep track of our current output state and previous state
int outputState = OFF;
int lastOutputState;

// We want to keep track of our current input state and previous state
int inputState = BASE;
int lastInputState;

void setup() {
  Serial.begin(9600);
}

void loop() {

  int sensorVal = 55; // we could be reading this value from a real sensor here

  if (sensorVal == 0) {
    inputState = BASE;
    outputState = OFF;
  }
  else if (sensorVal > 0 && sensorVal < 50) {
    inputState = COLD;
    outputState = RIGHT;
  }
  else if (sensorVal >= 50 && sensorVal < 75) {
    inputState = WARM;
    outputState = LEFT;
  }
  else if (sensorVal >= 75 && sensorVal < 100) {
    inputState = HOT;
    outputState = STRAIGHT;
  }
  else {
    Serial.println("sensor out of range");
  }

  // only change our output if it needs to be changed
  if (inputState != lastInputState && outputState != lastOutputState) {

    switch (outputState) {
      case OFF:
        Serial.println("off");
        break;
      case RIGHT:
        Serial.println("right");
        break;
      case LEFT:
        Serial.println("left");
        break;
      case STRAIGHT:
        Serial.println("straight");
        break;
      default:
        Serial.println("do nothing");
        break;

    }
  }

  lastInputState = inputState;
  lastOutputState = outputState;
}
