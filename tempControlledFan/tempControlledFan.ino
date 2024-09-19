const int sensorPin = A0;  
const int fanPin = 4;
const int blueLedPin = 3;
const int redLedPin = 2;


void setup() {
  pinMode(fanPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  
  Serial.begin(9600);  
}

float sensorValueToTemp(int value) {
  // Omvandla sensorvärdet till spänning
  float voltage = value * (5.0 / 1023.0);
  
  // Omvandla spänning till temperatur i Celsius
  float temperatureC = (voltage - 0.5) * 100;

  return temperatureC;
}

void loop() {
  // Läs av sensorvärdet
  int sensorValue = analogRead(sensorPin);

  float temperatureC = sensorValueToTemp(sensorValue);
  
  if(temperatureC>25) {
    digitalWrite(fanPin,HIGH);
    digitalWrite(blueLedPin,LOW);
    digitalWrite(redLedPin,HIGH);

  }
  else {
    digitalWrite(fanPin,LOW);
    digitalWrite(blueLedPin,HIGH);
    digitalWrite(redLedPin,LOW);
  }
  
  delay(1000);  // Vänta 1 sekund innan nästa avläsning
}