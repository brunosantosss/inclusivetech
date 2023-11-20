// Includes
#include <Ultrasonic.h>

// Defines
#define   ECHO_PIN            2
#define   TRIG_PIN            3        
 
Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);

void setup() {
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Distância: ");
  Serial.println(get_distance());
  delay(500);
}

int get_distance() {
  // Variables
  int range = 0;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

           
  range =  (ultrasonic.read(CM));
  return range;
}