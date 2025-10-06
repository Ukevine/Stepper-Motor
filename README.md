🌀 Stepper Motor Control via Serial Commands

This project demonstrates how to control a 28BYJ-48 stepper motor (or any 4-wire stepper motor) using an Arduino and the ULN2003 driver board.
You can send commands through the Serial Monitor to rotate the motor by specific angles.

📘 Features

Rotate the stepper motor by any angle (positive or negative).

Serial command interface for easy control.

Adjustable motor speed using setSpeed().

Works with 28BYJ-48 + ULN2003 driver setup.

⚙️ Hardware Requirements
Component	Quantity	Description
Arduino Uno (or compatible)	1	Microcontroller board
28BYJ-48 Stepper Motor	1	5V stepper motor
ULN2003 Driver Board	1	Motor driver for stepper
Jumper Wires	4+	For connecting Arduino to driver
🔌 Wiring Diagram
ULN2003 Pin	Arduino Pin
IN1	8
IN2	9
IN3	10
IN4	11
VCC	5V
GND	GND
Stepper Motor	Connected to ULN2003 Output Pins
🧩 Installation

Open the Arduino IDE.

Go to Sketch → Include Library → Manage Libraries.

Search for and install “Stepper” library (it comes pre-installed with Arduino IDE).

Copy the provided code into a new sketch.

Select your board and port, then upload the code.

💻 Serial Commands

After uploading, open the Serial Monitor (Ctrl + Shift + M) and set:

Baud Rate: 9600

Line Ending: Newline (\n)

Example Commands
Command	Description
rotate 180	Rotates the motor 180° clockwise
rotate -90	Rotates the motor 90° counterclockwise
rotate 360	Full rotation clockwise
rotate -720	Two full rotations counterclockwise
⚙️ Code Explanation

stepsPerRevolution = 2048
→ Number of steps for one full revolution (28BYJ-48 motor).

myStepper.setSpeed(10);
→ Sets motor speed in RPM (adjustable).

myStepper.step(steps);
→ Moves motor the calculated number of steps based on the input angle.

🧠 Notes

The 28BYJ-48 motor has a 64:1 gear reduction and typically 2048 steps per revolution.

You can modify stepsPerRevolution if using a different motor.

Avoid sending commands too quickly—wait for the motor to finish moving.

🧰 Example Output (Serial Monitor)
Enter command like 'rotate 180' or 'rotate -270' to control the stepper motor.
rotate 180
Rotated 180 degrees.
rotate -90
Rotated -90 degrees.

📄 License

This project is open-source and free to use for learning or development purposes.
