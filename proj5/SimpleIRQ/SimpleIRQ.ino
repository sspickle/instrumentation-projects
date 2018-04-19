volatile long int count = 0L;

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), click, FALLING);
}

void click() {
  count++;
  digitalWrite(13, ((count) & 0x01));
}

void loop()
{
  delay(1000); // Wait for 1000 millisecond(s)
  Serial.println(count);
  count=0L;
}

