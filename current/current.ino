const int sensorPin = A0;    // Analog input pin

void setup() {
  Serial.begin(9600);

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
}

void loop() {
  float sensorValue = analogRead(sensorPin);

  Serial.println(sensorValue);

  float voltage = (sensorValue) * (5.0 / 1023.0);

  // Serial.print("Sensor Voltage: ");
  // Serial.println(voltage);

  // With 0 A, Voltage = 0.243 V
  float offset = 0.243;
  // float offset = 0;

  // I = V/R. R = 100 ohms. 
  // Amps flowing through resistor.
  float current = (voltage - offset) / 100.0;

  Serial.print("Resistor Current (A): ");
  Serial.println(current, 5);

  // Multiply by turns ratio 1:1000
  current = current * 1000;

  // 8 Turns
  current = current / 8.0;

  if (current >= 3) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }

  Serial.print("Current (A): ");
  Serial.println(current, 5);
  
  delay(1000);
}