
int buttonPin =2;
// code for potentiometer
int potPin=A0;
int reading_Pot;
////////////////
int ledPin=9;
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);	
}

void loop() 
{
  int brightness;
  if (digitalRead(buttonPin)==LOW){
    reading_Pot = analogRead(potPin);
    if (reading_Pot >=0 && reading_Pot <=350)
    {
    brightness= reading_Pot/4;
    }
    else if (reading_Pot >=351 && reading_Pot <=511)
    {
    brightness= reading_Pot/8;
    }
    else
    {
    brightness = 255 - (reading_Pot / 4);
    }
    analogWrite(ledPin,brightness);
    Serial.println(reading_Pot);
    delay(100);
  }
  else {
    analogWrite(ledPin, 0);}
}
