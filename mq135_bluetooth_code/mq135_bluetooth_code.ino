int device = 2;
int setpoint = 40;
int mq135 = A0;
int led = 8;
float g ,m= 0;

void setup() {
  Serial.begin(9600);
  pinMode(device, OUTPUT);
  pinMode(mq135, INPUT);
  pinMode(led, OUTPUT);
  delay(2000);
}

void loop()
{
  m = analogRead(mq135);
  g = (m / 1023 * 100);
  Serial.print("Air Quality Level = ");
  Serial.println(g);
  if (g >= 37 ) 
  {
    Serial.println("Air Quality low");
    digitalWrite(led, HIGH);
  }
  else 
  {
    Serial.println("Air Quality Good");
    digitalWrite(led, LOW);
  }
  delay(3000);
}
