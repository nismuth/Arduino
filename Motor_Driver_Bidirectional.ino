/* This is a simple Arduino program for a motor driver

Action: motor spins in one direction then the other after 1 sec  

components used for testing code:
- Arduino Uno
- breadboard
- 15 jumper wires
- L293D h-bridge motor driver
- hobby gearmotor

DISCLAIMER: external battery source maybe needed to avoid killing Arduino
if killed -> 3.5V from Arduino, 3-5V from external *DON'T connect buses*
*/

// Object Declarations
const int forwardPin = 8; // Input 1 pin
const int backwardPin = 10; // Input 2 pin
const int delayTime = 1000; // 1000 milliseconds = 1 sec

// Pin Setup
void setup()
{
  pinMode(forwardPin, OUTPUT); // Output 1 setup
  pinMode(backwardPin, OUTPUT); // Output 2 setup
}

// Operation
void loop()
{
  // Stop
  digitalWrite(forwardPin, LOW); // LOW = disabled
  digitalWrite(backwardPin, LOW);
  delay(delayTime); // 1 sec/1000 millisec delay

  // Forward
  digitalWrite(forwardPin, HIGH); // HIGH = enabled
  digitalWrite(backwardPin, LOW);
  delay(delayTime);

  // Stop
  digitalWrite(forwardPin, LOW);
  digitalWrite(backwardPin, LOW);
  delay(delayTime);

  // Reverse
  digitalWrite(forwardPin, LOW);
  digitalWrite(backwardPin, HIGH);
  delay(delayTime);
}