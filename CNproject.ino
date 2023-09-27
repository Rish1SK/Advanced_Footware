const int trigPin = 8;
const int echoPin = 7;
const int speakerPin = 11;
const float distanceThreshold = 50.0; // Distance threshold in cm

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  if (distance < distanceThreshold) {
    Serial.print("OBJECT DETECTED!! Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    tone(speakerPin, 1000);
    delay(500);
    noTone(speakerPin);
  }

  delay(500);
}
