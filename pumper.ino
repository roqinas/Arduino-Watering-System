const int pumpPin = 7; // Define the pin number for connecting the pump relay

void setup() {
  // The setup function runs once when the Arduino is powered on or reset
  Serial.begin(9600); // Initialize serial communication at a baud rate of 9600
  pinMode(pumpPin, OUTPUT); // Set the pumpPin as an output
  delay(5000); // Pause for 5 seconds in millisecond
}

void loop() {
  // The loop function runs repeatedly as long as the Arduino is powered on
                          
  Serial.println("the pump start working"); // Print a message to the serial monitor
  
  digitalWrite(pumpPin, HIGH); // Turn ON the pump by setting the pumpPin HIGH
  Serial.println("-----------------------"); // Print a separator line
  delay(6000); // Pause for 6 seconds in millisecond
  
  Serial.println("the pump is not-working"); // Print a message to the serial monitor
  digitalWrite(pumpPin, LOW); // Turn OFF the pump by setting the pumpPin LOW
  Serial.println("-----------------------"); // Print a separator line
  delay(5000); // Pause for 5 seconds
}
