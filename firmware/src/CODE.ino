#include <Arduino.h>
#include <EEPROM.h>

// Motor driver pins
const int ENA = 10;
const int IN1 = 12;
const int IN2 = 11;

// End stop pins
const int minEndStop = 8;
const int maxEndStop = 9;

// Encoder pin
const int encoderPin = A3;

// Button pins
const int upButton = 2;
const int downButton = 3;
const int mode1Button = 6;
const int mode2Button = 7;
const int saveButton = 4;

// LED pins
const int mode1LED = A4;
const int mode2LED = A5;

// Motor speed (adjust as needed)
const int motorSpeed = 255;  // Adjust this value based on your motor

// Encoder resolution (pulses per revolution)
const int encoderResolution = 1024;  // Adjust this value based on your encoder

// Distance per pulse (adjust based on thread pitch and gear ratio)
const float distancePerPulse = 0.001;  // Example value, adjust accordingly

// EEPROM addresses for storing mode positions
const int mode1Address = 0;
const int mode2Address = 4;

// State variables
int mode = 1;  // Current mode
bool savingMode = false;
long encoderCount = 0;
long targetCount = 0;
bool movingUp = false;
bool movingDown = false;
long previousEncoderValue = 0;
bool goingToPosition = false;

// Function prototypes
void moveMotor(int direction);
void readEncoder();
void checkEndStops();
void handleButtons();
void Home();

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(minEndStop, INPUT_PULLUP);
  pinMode(maxEndStop, INPUT_PULLUP);
  pinMode(encoderPin, INPUT_PULLUP);
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(mode1Button, INPUT_PULLUP);
  pinMode(mode2Button, INPUT_PULLUP);
  pinMode(saveButton, INPUT_PULLUP);
  pinMode(mode1LED, OUTPUT);
  pinMode(mode2LED, OUTPUT);

  Serial.begin(9600);
  
  // Initialize motor and encoder
  // ... (code to initialize motor and encoder)

  Home();
}

void loop() {
  readEncoder();
  handleButtons();

  if (goingToPosition) {
    if (encoderCount < targetCount) {
      movingUp = true;
      movingDown = false;
    } else if (encoderCount > targetCount) {
      movingUp = false;
      movingDown = true;
    } else {
      goingToPosition = false;
      movingUp = false;
      movingDown = false;
    }
  } else {
  if (movingUp) {
    moveMotor(1);
  } else if (movingDown) {
    moveMotor(-1);
  } else {
    // Stop motor
    analogWrite(ENA, 0);
  }
 }
}
void moveMotor(int direction) {
  if (direction == 1) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else if (direction == -1) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
  analogWrite(ENA, motorSpeed);
}

void readEncoder() {
  if (debounce()) { 
  if (movingUp) {
      encoderCount++;
    } 
  if (movingUp) {
      encoderCount--;
    }
  }
}


void handleButtons() {
  if (digitalRead(upButton) == LOW) {
    movingUp = true;
    movingDown = false;
    if (digitalRead(maxEndStop) == LOW) {
    // Reached maximum position
    movingUp = false;
    encoderCount = 30;

  }} else if (digitalRead(downButton) == LOW) {
    movingUp = false;
    movingDown = true;
      if (digitalRead(minEndStop) == LOW) {
    // Reached minimum position
    movingDown = false;
    encoderCount = 0;
  }}
  else{
    movingUp = false;
    movingDown = false;
  }

  if (digitalRead(saveButton) == LOW) {
    savingMode = true;
    digitalWrite(mode1LED, HIGH);
    digitalWrite(mode2LED, HIGH);
  }

  if (digitalRead(mode1Button) == LOW) {
    if (savingMode) {
      EEPROM.write(0, encoderCount);
      savingMode = false;
    } else {
    mode = 1;
    digitalWrite(mode1LED, HIGH);
    digitalWrite(mode2LED, LOW);
    goingToPosition = true;
    targetCount = EEPROM.read(0);
    }
  } else if (digitalRead(mode2Button) == LOW) {
    if (savingMode) {
      EEPROM.write(4, encoderCount);
      savingMode = false;
    } else {
    mode = 2;
    digitalWrite(mode1LED, LOW);
    digitalWrite(mode2LED, HIGH);
    goingToPosition = true;
    targetCount = EEPROM.read(4);
    }
  } else {
    digitalWrite(mode1LED, mode == 1 ? HIGH : LOW);
    digitalWrite(mode2LED, mode == 2 ? HIGH : LOW);
  }
}


void Home() {
  while(digitalRead(minEndStop) != LOW){
    moveMotor(-1);
    encoderCount = 0;
  }
}

bool debounce() {
  static unsigned long lastDebounceTime[4] = {0}; // Static variable to store state
  const unsigned long debounceDelay = 200;
  
  if (digitalRead(A3) == LOW) {
    if (millis() - lastDebounceTime[A3] >= debounceDelay) {
      lastDebounceTime[A3] = millis();
      return true;
    }
  }
  return false;
}