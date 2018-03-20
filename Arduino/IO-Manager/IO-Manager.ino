#define LED_PIN 13  // Built-in led

String incomingBytes = "AAA";   // for incoming serial data

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  pinMode(LED_PIN, OUTPUT);
  flash(10);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
      // read the incoming byte:
    incomingBytes = Serial.readString();
    flash(4);
      // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingBytes);
  }
}

void flash(int x){
  for(int i = 0; i < x; i++){
    digitalWrite(LED_PIN, HIGH);
    delay(10);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }
}
