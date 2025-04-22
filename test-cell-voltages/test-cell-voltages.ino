// #include <Wire.h>
// #include <Adafruit_ADS1X15.h>
// Adafruit_ADS1115 ads;

// int16_t adc0;

void setup() {
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  // if (!ads.begin()) {
  //   Serial.println("Failed to initialize ADC.");
  //   while (1);
  // }

}

void loop() {
  int truthTable[16][4] = {
    {0, 0, 0, 0},
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {1, 1, 0, 0},
    {0, 0, 1, 0},
    {1, 0, 1, 0},
    {0, 1, 1, 0},
    {1, 1, 1, 0},
    {0, 0, 0, 1},
    {1, 0, 0, 1},
    {0, 1, 0, 1},
    {1, 1, 0, 1},
    {0, 0, 1, 1},
    {1, 0, 1, 1},
    {0, 1, 1, 1},
    {1, 1, 1, 1}
  };

  int i = 0;

  // Mux 1
  digitalWrite(2, truthTable[i][0]);
  digitalWrite(3, truthTable[i][1]);
  digitalWrite(4, truthTable[i][2]);
  digitalWrite(5, truthTable[i][3]);

  // Mux 2
  digitalWrite(6, truthTable[i][0]);
  digitalWrite(7, truthTable[i][1]);
  digitalWrite(8, truthTable[i][2]);
  digitalWrite(9, truthTable[i][3]);

  
  int analogReading = analogRead(A1);
  float voltage = (analogReading / 1023.00) * 5.00; 

  // Account for voltage divider.
  voltage = voltage * 13;

  Serial.print("Cell: ");
  Serial.print(i + 1);

  Serial.print(" Voltage: ");
  Serial.println(voltage);

}

  // ads.setGain(GAIN_ONE);

  // int pin1 = 11;
  // int pin2 = pin1 + 1;

  // digitalWrite(2, truthTable[pin1][0]);
  // digitalWrite(3, truthTable[pin1][1]);
  // digitalWrite(4, truthTable[pin1][2]);
  // digitalWrite(5, truthTable[pin1][3]);

  // digitalWrite(6, truthTable[pin2][0]);
  // digitalWrite(7, truthTable[pin2][1]);
  // digitalWrite(8, truthTable[pin2][2]);
  // digitalWrite(9, truthTable[pin2][3]);

  // float adc0 = ads.readADC_SingleEnded(0);
  // float adc1 = ads.readADC_SingleEnded(1);


  // float voltage1 = adc0 * (4.096 / 32768.0);
  // // float voltage1 = 0;
  // float voltage2 = adc1 * (4.096 / 32768.0);

  // float voltage = voltage2 - voltage1;

  // voltage = voltage * 13;

  // Serial.print("Voltage: ");
  // Serial.println(voltage, 3);
  // delay(1000);




  
  // // put your main code here, to run repeatedly:
  // for (int i = 0; i < 16; i++) {
    
  //   digitalWrite(6, truthTable[i][0]);
  //   digitalWrite(7, truthTable[i][1]);
  //   digitalWrite(8, truthTable[i][2]);
  //   digitalWrite(9, truthTable[i][3]);

    
  //   int analogReading = analogRead(A1);
  //   float voltage = (analogReading / 1023.00) * 5.00; 

  //   // Account for voltage divider.
  //   voltage = voltage * 13;

  //   Serial.print("Cell: ");
  //   Serial.print(i + 1);

  //   Serial.print(" Voltage: ");
  //   Serial.println(voltage);


  //   delay(500);
  // }
  
  

}
