int resist, celsius;
void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT); //Pin 3 is connected to the Relay Module
  pinMode(A0, INPUT); //Pin A0 is connected to the Temperature Sensor
  pinMode(6, INPUT); //Pin 6 is connected to the Soil moisture Sensor
  pinMode(10, INPUT); //Pin 10 is connected to the Soil moisture Sensor
  pinMode(11, INPUT); //Pin 11 is connected to the Soil moisture Sensor
}

void loop() {
  resist = (analogRead(6)+analogRead(10)+analogRead(11))/3; //Reading the average moisture level
  
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, 40, 125); //Reading temperature
  
  if (resist > 350 || celsius > 45) //When moisture level exceeds the threshold value
  {
    Serial.println("Pump ON");
    Serial.println(resist);
  	Serial.println(celsius);
    Serial.println();
    digitalWrite(3, LOW); //LED & Motor ON -> Relay ON -> Pump ON
  }
  else //When moisture level is below the threshold value
  {
    Serial.println("Pump OFF");
    Serial.println(resist); //Display moisture level
  	Serial.println(celsius);
    Serial.println();
    digitalWrite(3, HIGH); //LED & Motor OFF -> Relay OFF -> Pump OFF
  }
  delay(100);
}
