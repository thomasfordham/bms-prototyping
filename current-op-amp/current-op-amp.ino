void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);

  float voltage = sensorValue * (5.0 / 1023.0);

  Serial.println(sensorValue);

  // Op Amp
  float actualVoltage = (voltage - 2.7705) / 0.5504;  

  float offset = 0.230;

  // - offset when + current. + offset when - current?
  // How to determine which direction before offset?

  float current = (actualVoltage - offset) / 100.0;
  current = current * 1000;
  current = current / 8.0;

  Serial.print("Current (A): ");
  Serial.println(current, 5);

  delay(1000);
}
