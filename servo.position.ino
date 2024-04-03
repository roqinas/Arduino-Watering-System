#include <Servo.h> // Include the Servo library, which allows you to control servo motors

Servo watering_angle; // Create a Servo object (watering_angle)

#define Angle_pin 9 // Define the pin number for connecting the servo motor
#define servoposition1  50 // Define servo positions for different angles
#define servoposition2  110
#define servoposition3  40
#define servoposition4  60
#define servoposition5  80
#define servoposition6  100
#define servoposition7  120

#define wateringtime 5000 //in milliseconds


void setup() {    // when the Arduino is powered on or reset
  Serial.begin(9600); // Initialize serial communication at a baud rate of 9600
  watering_angle.attach(Angle_pin); // Attach the servo motor to the specified pin
  Serial.println("Starting...."); // Print a message to the serial monitor
  delay(3000); // Pause for 3 seconds in milliseconds

  watering_angle.write(servoposition1); // Set the servo motor to position 50 degree
  Serial.println("The Position is: 50"); // Print the current position to the serial monitor
  delay(2000); // Pause for 2 seconds in milliseconds
  Serial.println("---------------------"); // Print a separator line
  delay(1000); // Pause for 1 second in milliseconds

  watering_angle.write(servoposition2); // Set the servo motor to position 110
  Serial.println("The Position is: 110"); // Print the current position to the serial monitor
  delay(2000); // Pause for 2 seconds
  Serial.println("---------------------"); // Print a separator line
  delay(1000); // Pause for 1 second
}

void loop() {
  // The loop function runs repeatedly as long as the Arduino is powered on
}
