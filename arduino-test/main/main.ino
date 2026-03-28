void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String incoming = Serial.readStringUntil('\n');
    incoming.trim(); 
    if (incoming == "ping") {
      Serial.println("pong");
    }
  }
}
