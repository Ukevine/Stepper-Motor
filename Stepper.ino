#include <Stepper.h>
// Define the number of steps per revolution (adjust based on your stepper motor, e.g., 2048 for 28BYJ-48)
const int stepsPerRevolution = 2048;
// Define the pins connected to the ULN2003 driver inputs
const int in1Pin = 8;
const int in2Pin = 9;
const int in3Pin = 10;
const int in4Pin = 11;
// Create a Stepper object
Stepper myStepper(stepsPerRevolution, in1Pin, in3Pin, in2Pin, in4Pin);
void setup() {
  // Set the motor control pins as outputs
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  Serial.begin(9600);
  myStepper.setSpeed(10); // Set speed in RPM
  Serial.println("Enter command like 'rotate 180' or 'rotate -270' to control the stepper motor.");
}
void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    if (command.startsWith("rotate ")) {
      String angleStr = command.substring(7);
      angleStr.trim();
      long angle = angleStr.toInt(); // Convert input to integer angle
      // Calculate steps (using float for precision, then cast to long)
      long steps = (long) ((angle / 360.0) * stepsPerRevolution);
      // Rotate the motor in the correct direction
      myStepper.step(steps);
      Serial.print("Rotated ");
      Serial.print(angle);
      Serial.println(" degrees.");
    } else {
      Serial.println("Invalid command. Use format: 'rotate X' where X is an integer (positive or negative).");
    }
  }
}