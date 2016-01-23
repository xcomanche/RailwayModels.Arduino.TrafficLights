/* The list of signals icould be found here
 *  https://ru.wikipedia.org/wiki/%D0%96%D0%B5%D0%BB%D0%B5%D0%B7%D0%BD%D0%BE%D0%B4%D0%BE%D1%80%D0%BE%D0%B6%D0%BD%D0%B0%D1%8F_%D1%81%D0%B2%D0%B5%D1%82%D0%BE%D1%84%D0%BE%D1%80%D0%BD%D0%B0%D1%8F_%D1%81%D0%B8%D0%B3%D0%BD%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F
 * /-\
 * |O| - yellowTop
 * |O| - green
 * |O| - yellowCenter
 * \_/
 *  |
 * /-\
 * |O| - red
 * |O| - yellowBottom
 * \_/
 *  |
 *||||||  - greenBar
 *  |
 * /-\
 * |O| - white
 * \_/
 *  |
 *  |
 */

const int yellowTop =  12;
const int green =  11;
const int yellowMiddle =  10;
const int red =  9;
const int yellowBottom =  8;
const int greenBar =  7;
const int white =  6;
const int blue =  5;
const int switchPin = 3;
const int buttonPin = 2;

int blinkingLedState = LOW;
unsigned long previousMillis = 0;
unsigned long millisFromStart = 0;
const long interval = 1000;
const long signalInterval = 5000;
const int signalCount = 14;
int currentSignal = 0;
int previousSignal = -1;
int buttonState = 0;  
int previousButtonState = 0;
int switchState = 0;  

void setup() {
  // set the digital pin as output:
  pinMode(yellowTop, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellowMiddle, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellowBottom, OUTPUT);
  pinMode(greenBar, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
 
  currentSignal = ceil((millis() - millisFromStart) / signalInterval);
  if (currentSignal > signalCount) {
    millisFromStart = millis();
  }  
  
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (blinkingLedState == LOW) {
      blinkingLedState = HIGH;
    } else {
      blinkingLedState = LOW;
    }
  }    
    
  // set the LED with the ledState of the variable:
  displaySignal(currentSignal, blinkingLedState);
}

void turnOffSignals() {
  digitalWrite(yellowTop, LOW);
  digitalWrite(green, LOW);
  digitalWrite(yellowMiddle, LOW);
  digitalWrite(red, LOW);
  digitalWrite(yellowBottom, LOW);
  digitalWrite(greenBar, LOW);
  digitalWrite(white, LOW);
  digitalWrite(blue, LOW);
}

void displaySignal(int code, int blinkingLedState) {
  if (code != previousSignal) {
    previousSignal = code;
    turnOffSignals();
  }
  
  switch(code){
    case 0:
      digitalWrite(red, HIGH);
    break;
    case 1:
      digitalWrite(yellowTop, HIGH);
    break;
    case 2:
      digitalWrite(green, HIGH);
    break;
    case 3:
      digitalWrite(yellowTop, HIGH);
      digitalWrite(green, HIGH);
    break;
    case 4:
      digitalWrite(yellowTop, HIGH);
      digitalWrite(yellowBottom, HIGH);
    break;
    case 5:
      digitalWrite(yellowTop, blinkingLedState);
      digitalWrite(yellowBottom, HIGH);
    break;
    case 6:
      digitalWrite(yellowTop, blinkingLedState);
    break;
    case 7:
      digitalWrite(yellowTop, HIGH);
      digitalWrite(yellowBottom, HIGH);
      digitalWrite(greenBar, HIGH);
    break;
    case 8:
      digitalWrite(yellowTop, blinkingLedState);
      digitalWrite(yellowBottom, HIGH);
      digitalWrite(greenBar, HIGH);
    break;
    case 9:
      digitalWrite(green, blinkingLedState);
      digitalWrite(yellowBottom, HIGH);
      digitalWrite(greenBar, HIGH);
    break;
    case 10:
      digitalWrite(green, blinkingLedState);
    break;
    case 11:
      digitalWrite(yellowTop, HIGH);
      digitalWrite(white, HIGH);
    break;
    case 12:
      digitalWrite(green, HIGH);
      digitalWrite(white, HIGH);
    break;
    case 13:
      digitalWrite(yellowTop, blinkingLedState);
      digitalWrite(white, HIGH);
    break;
    case 14:
      digitalWrite(blue, HIGH);
    break;
    default:
      digitalWrite(red, blinkingLedState);
    break;
  }
}

