const int ledGreen = 13;     // LED
const int pinRed = 11;       // RGB LED red pin
const int pinBlue = 10;      // RGB LED blue pin
const int pinGreen = 9;      // RGB LED green pin
const int buzzerPin = 6;     // Piezo Buzzer pin
int pirPin = 12;             // PIR sensor signal pin
int pirStat = 0;             // PIR sensor status

void setup() {
  pinMode(ledGreen, OUTPUT);
  pinMode(pinRed, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
  Serial.println("Warming Up...");
  delay(5000);
  Serial.println("Ready..");

}

void loop() {
  pirStat = digitalRead(pirPin);
  if (pirStat == HIGH) {
    Serial.println("Motion Detected!");
    digitalWrite(ledGreen, LOW);
    policeLights();
  } else {
    digitalWrite(ledGreen, HIGH);
    everythingIsFine();
    Serial.println("No Motion Detected.");
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(pinRed, red);
  analogWrite(pinGreen, green);
  analogWrite(pinBlue, blue);
}

void policeLights() {
  setColor(255, 0, 0);
  delay(500);
  setColor(0, 0, 255);
  delay(500);
  motionDetected();
}

void everythingIsFine() {
  setColor(0, 0, 0);
  noMotion();
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