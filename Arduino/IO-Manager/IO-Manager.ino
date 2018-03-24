#define LED_PIN 13  // Built-in led
#define Digital_1 7
#define Analog_1 7

//Config
//Loop out
//Setup/Receive

String incomingBytes = "AAAAA";   // for incoming serial data
int Digital[10];
int Analog[10];

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  pinMode(Digital_1, INPUT);
  pinMode(LED_PIN, OUTPUT);
  flash(10);
}

void loop() {
  if(CheckSerial() == true){
    GetPins();
    Send();
  }
}

bool CheckSerial(){
  int timer;
  
  for(timer = 1000; timer != 0; timer--){
    if(Serial.available() > 0) {
      digitalWrite(LED_PIN, HIGH);
        // read the incoming byte:
      incomingBytes = Serial.readString();
        // say what you got:
      if(incomingBytes[0] == '#')
        LoopSend();
      return true;
    }
    return false;
  }
}

void LoopSend(){
  while(true){
    digitalWrite(LED_PIN, HIGH);
    delay(300);
    Serial.println("sendforever");
    digitalWrite(LED_PIN, LOW);
  }
}

void GetPins(){
  Digital[0] = digitalRead(Digital_1);
  Analog[0] = analogRead(Analog_1);
  
}

void Send(){
  delay(10);
  Serial.print(Digital[0]);
  Serial.print(";");
  Serial.print(Analog[0]);
  Serial.print(";");
  Serial.print(millis());
  Serial.print(";");
  Serial.println(incomingBytes);
  digitalWrite(LED_PIN, LOW);
}

void flash(int x){
  for(int i = 0; i < x; i++){
    digitalWrite(LED_PIN, HIGH);
    delay(10);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }
}


