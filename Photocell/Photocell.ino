// Author: Herbert Caller
// Date: 11-11-2017

// Outputs a PWM signal
int pinRed = 3;
int pinGreen = 5;

// Reads the analog voltage (10 bit number)
int pinPhotoCell = 0;

// Reading value
int photoCellInput;

int brightness;

void setup() {
  // Lets to show values on the serial monitor
  Serial.begin(9600);
}

void loop() {
  // Read photocell voltage
  photoCellInput = analogRead(pinPhotoCell);
  // Show values on the serial monitor
  Serial.print("photocell ==> "); 
  Serial.println(photoCellInput);
  // Map voltage photocell to LED output range
  brightness = map(photoCellInput, 0, 1023, 0, 255);
  // Full darkness gives a red light
  analogWrite(pinRed, 255 - brightness);
  // Full light gives a green light
  analogWrite(pinGreen, brightness);
}
