// SeatSense V4
// Distance-based seat detection with LED feedback

const int trigPin = 9;
const int echoPin = 10;
const int ledPin = LED_BUILTIN;

const float occupiedThreshold = 20.0;

int missedReadings = 0;
const int maxMissedReadings = 5;

bool occupied = false;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, LOW);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    missedReadings++;

    if (missedReadings >= maxMissedReadings) {
      occupied = false;
    }

    Serial.println("No reading");
  } else {
    missedReadings = 0;

    float distanceCm = duration * 0.0343 / 2.0;

    if (distanceCm < occupiedThreshold) {
      occupied = true;
    } else {
      occupied = false;
    }

    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");
  }

  if (occupied) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Seat Status: OCCUPIED");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("Seat Status: EMPTY");
  }

  delay(300);
}
