#include <toneAC.h>

//!!----=====    configuration constants   ======------!!!!!
const int pingPin = 7;  //pin you use for range finder
const int buzzerPin = 9;
int potPin = 2; //pin for potentiometer

//freq of sound and it's derivative is proportional to freqSensitivity
const int freqSensitivity = 1;
//volume of sound and it's derivative is proportional to volumeSensitivity
const int volumeSensitivity = 1;
//If it is so far away that that the sound waves 
// take longer than the maxDuration then there
// will be no sound from the buzzer.You probably won't need 
// to configure maxDuration.
const int maxDuration = 9999;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(buzzerPin, OUTPUT);
}

int potVal;
void loop() {
  // put your main code here, to run repeatedly:
   long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  potVal = analogRead(potPin);
  toneAC((freqSensitivity * potVal)/duration), ((volumeSensitivity*potVal)/duration), 0);
  if(duration > maxDuration) toneAC();

  Serial.print(duration);

  delay(100);
}
