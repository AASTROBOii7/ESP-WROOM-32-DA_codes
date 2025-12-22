#define VIBRATION_PIN 27
#define LED_PIN 2

void setup() {
  pinMode(VIBRATION_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int vibration = digitalRead(VIBRATION_PIN);

  if (vibration == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Vibration detected!");
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(50); // debounce delay
}
