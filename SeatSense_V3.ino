// SeatSense V3
// Real distance sensor test using HC-SR04

const int trigPin = 9;
const int echoPin = 10;

long duration;
float distanceCm;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    Serial.println("No reading");
  } else {
    distanceCm = duration * 0.0343 / 2.0;

    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");
  }

  delay(300);
}
