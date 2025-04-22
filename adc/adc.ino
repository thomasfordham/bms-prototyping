
#include <Wire.h>

#define ADC_ADDRESS 0x48
#define V_REF 5.0         // Reference voltage
#define ADC_MAX_VALUE 65535 // Maximum value for 16-bit ADC


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    Wire.begin();
    Serial.println("hello");
}

void loop() {
    Wire.beginTransmission(ADC_ADDRESS);
    Wire.write(2); // Select the channel
    Wire.endTransmission();
    Wire.requestFrom(ADC_ADDRESS, 2);

    int value = Wire.read() << 8 | Wire.read();

    float voltage = (value / (float)ADC_MAX_VALUE) * V_REF; 

    Serial.println(value);
    
    Serial.println(voltage);
    
    Serial.println("here");
    delay(1000); // Wait for a second before the next read
}
