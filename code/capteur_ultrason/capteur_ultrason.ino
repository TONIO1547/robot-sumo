// Robot sumo — test du capteur ultrason HC-SR04
// Mesure la distance devant le robot (détection de l'adversaire) et l'affiche
// sur le moniteur série (115200 bauds). TRIG sur la broche 8, ECHO sur la broche 9.


const byte TRIGGER_PIN = 8; 
const byte ECHO_PIN = 9;  
 

const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s


const float SOUND_SPEED = 340.0 / 1000;


void setup() {
   

  Serial.begin(115200);
   

  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); 
  pinMode(ECHO_PIN, INPUT);
}
 

void loop() {
  
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);  // le HC-SR04 demande une impulsion d'au moins 10 µs
  digitalWrite(TRIGGER_PIN, LOW);
  

  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
   

  float distance_mm = measure / 2.0 * SOUND_SPEED;
   

  Serial.print(F("Distance: "));
 Serial.print(distance_mm / 10.0, 2);
  Serial.println(F("cm, "));
   
  delay(100);
}
