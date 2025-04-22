#define PIN A0         
#define DEFAULT_RESISTANCE 10000      
#define DEFAULT_TEMP 25   
#define BETA 3950
#define SERIES_RESISTOR 10000    

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  float reading = analogRead(PIN);
  
  float resistance = SERIES_RESISTOR * (1023.0 / reading - 1.0); 
  
  // Need to convert the resisance reading to temperature using the steinhart equation.
  float temp;
  temp = resistance / DEFAULT_RESISTANCE;  
  temp = log(temp);                     
  temp /= BETA;                       
  temp += 1.0 / (DEFAULT_TEMP + 273.15); 
  temp = 1.0 / temp;                     
  temp -= 273.15;                             
  
  Serial.print("Temperature "); 
  Serial.print(temp);
  Serial.println(" *C");
  
  delay(1000);
}
