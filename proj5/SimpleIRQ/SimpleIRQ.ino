#define INPUT_PIN 2

volatile long int count = 0L;

void setup()
{
  pinMode(INPUT_PIN, INPUT);
  pinMode(LED_BUILTIN,OUTPUT);

  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(INPUT_PIN), click, FALLING);
}

void click() {
  count++;
  digitalWrite(LED_BUILTIN,(count & 0x01)); // toggle the LED for each hit
}

void loop()
{
  long int copy;   // an interrupt safe copy of the count

  delay(1000);     // Wait for 1000 millisecond(s)


  noInterrupts();  // disable interrupts
  copy = count;    // make a local safe copy
  count=0L;        // clear the global count
  interrupts();    // re-enable interrupts

  Serial.println(copy);
}