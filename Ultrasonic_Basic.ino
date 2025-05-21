
// Define Trig and Echo pins.
const int TRIG_PIN = 3;
const int ECHO_PIN = 2;


void setup() {
  // Define inputs and outputs to HC-SR04 sensor.
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);


  Serial.begin(9600);
}


void loop() {
  int distanceCentimeters = getDistanceCentimeters();


  // Print the distance on the Serial Monitor.
  Serial.print("Distance = ");
  Serial.print(distanceCentimeters);
  Serial.println(" cm");


  delay(50);
}


int getDistanceCentimeters() {
  // Clear the trigPin by setting it LOW.
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);


  // Trigger the sensor by setting the trigPin high for 10 microseconds.
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);


  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds.
  long durationMicroseconds = pulseIn(ECHO_PIN, HIGH);
  // Calculate the distance in centimeters. Note that at 20 degrees Celcius, the speed of sound
  // is roughly 0.034 cm / us.
  int distanceCentimeters = durationMicroseconds * 0.034 / 2;


  return distanceCentimeters;
}