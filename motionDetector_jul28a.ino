const int ledGreen = 13;     // LED
const int buzzerPin = 6;     // Piezo Buzzer pin
int pirPin = 12;             // PIR sensor signal pin
int motionStat = 0;          // PIR sensor status
int pirState = LOW;          // the state the PIR sensor starts at


void setup() {
  pinMode(ledGreen, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
  delay(5000);
}

void loop() {
  motionStat = digitalRead(pirPin);
  if (motionStat == HIGH) {

      digitalWrite(ledGreen, LOW);

    // activate
    if (pirState == LOW){
      Serial.println("Motion Detected!");
      pirState = HIGH;
    }
  } else {

      digitalWrite(ledGreen, HIGH);

    // deactivate
    if (pirState == HIGH) {
      Serial.println("No Motion Detected.");
      pirState = LOW;
    }
  }
}

void motionDetected() {
  tone(buzzerPin, 300, 300);  // Low buzz
  delay(350);
  tone(buzzerPin, 200, 300);  // Lower buzz
  delay(350);
}

void noMotion() {
  noTone(buzzerPin);
}