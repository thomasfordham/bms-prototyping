#include <Wire.h>

void setup() {
  // Start the I2C bus
  Wire.begin();
  // Start the Serial communication
  Serial.begin(9600);
  while (!Serial); // Wait for Serial to initialize
  Serial.println("\nI2C Scanner");
}

void loop() {
  Serial.println("Scanning...");

  // Reset the device count
  int deviceCount = 0;

  // Scan for devices
  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println("  !");
      deviceCount++;
      delay(500); // Wait a bit before the next scan
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }

  if (deviceCount == 0) {
    Serial.println("No I2C devices found\n");
  } else {
    Serial.print("Total I2C devices found: ");
    Serial.println(deviceCount);
  }

  delay(5000); // Wait 5 seconds before the next scan
}
