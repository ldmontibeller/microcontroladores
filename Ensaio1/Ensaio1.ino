void setup() {
  Serial.begin(9600);
}

void loop() 
{
  testFunction1();
}

void testFunction1()
{
  Serial.println(micros());
  delay(148); 
}
