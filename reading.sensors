#define limitofwatering 750 // Define the limit value for watering

// Define the moisture sensor pins
char sensor_pin[4] = {A0, 1, 2, 3}; // Define an array to store sensor pins

// Define an array to store the value read from each moisture sensor
int sensor_value[4];

void setup() {
  Serial.begin(9600); // Initialize serial communication at a baud rate of 9600
}

void loop() {
  
  // Read the analog input value from sensor_pin[2] (A0 pin):
  
  sensor_value[2] = analogRead(sensor_pin[2]);
  delay(50); // Delay to stabilize sensor reading

  // Print sensor pin number and its corresponding value to the serial monitor:
  Serial.print("Sensor Pin: ");
  Serial.print(sensor_pin[2]);
  Serial.print(", Moisture Value: ");
  Serial.println(sensor_value[2]);
  
  delay(50); // Delay before reading the sensor again
}
