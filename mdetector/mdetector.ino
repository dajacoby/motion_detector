int relayPin = 3;     // choose the output pin for relay
int val = 0;          // start with relayPIN is LOW
int inputPin = 2;     // choose the input pin for PIR sensor
int pirState = LOW;   // start with no motion detected
int LDRinput = A3;    // choose the input pin for LDR sensor
int sensorwert=0;     // start with 0 for LDR sensor  
int input = A0;       // choose the input pin for Rotary Potentiometer
int reglerwert=0;     // start with 0 for Rotary Potentiometer  
int button = 6;       // choose the input pin for button (light on for xx time) 
int buttonstatus=0;   // start with no button pushed
int yellowLED = 12;    // choose the output pin for yellow LED (motion detection on)
int greenLED = 13;    // choose the output pin for green LED (Power ON)

void setup() 
{ 
  pinMode(relayPin, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(inputPin, INPUT);
  pinMode(button, INPUT);
} 
 
void loop(){
  digitalWrite(greenLED, HIGH);
  buttonstatus=digitalRead(button);
  if (buttonstatus == HIGH){          // if button pushed then
    digitalWrite(relayPin,HIGH);      // relayPIN (light on)
    delay(5000);                      // wait for a second
    digitalWrite(relayPin,LOW);       // relayPIN (light off)
 }
  else {  
    sensorwert=analogRead(LDRinput);
    reglerwert=analogRead(input);
  if (sensorwert < reglerwert) {
    digitalWrite(yellowLED,HIGH);     // yellow LED on
    val = digitalRead(inputPin);      // read relayPIN 
  if (val == HIGH) {
    do{                               // start with do-while
    digitalWrite(relayPin, INPUT);     // turn the relay on (HIGH is the voltage level)
    delay(10000);                      // wait for a second
    }while(digitalRead(inputPin));    // read the PIR sensor for replay the do-while
  //  delay(5000);
  } else {
      digitalWrite(relayPin, OUTPUT);      // turn the relay off by making the voltage LOW
  }
  } else {
      digitalWrite(yellowLED, LOW);
      digitalWrite(relayPin, OUTPUT);
  }
  }
}
 
