#include <Servo.h>

// === Definitions ===
// L298N Motor Control Pins
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define ENA 9
#define ENB 11

// Servo Motor
Servo myServo;
#define SERVO_PIN 6

// Ultrasonic Distance Sensor Pins
#define TRIG_FRONT 7
#define ECHO_FRONT 8
#define TRIG_BACK 12
#define ECHO_BACK 13

// Distance Variables
long distanceFront = 0;
long distanceBack = 0;

// === Setup ===
void setup() {
  delay(2000); // Wait for connection stabilization
  Serial.begin(9600);

  // Motor Pins Setup
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Servo Setup
  myServo.attach(SERVO_PIN);
  myServo.write(90); // Default to middle position

  // Ultrasonic Sensors Setup
  pinMode(TRIG_FRONT, OUTPUT);
  pinMode(ECHO_FRONT, INPUT);
  pinMode(TRIG_BACK, OUTPUT);
  pinMode(ECHO_BACK, INPUT);
}

// === Main Loop ===
void loop() {
  distanceFront = getSmoothDistance(TRIG_FRONT, ECHO_FRONT);
  distanceBack = getSmoothDistance(TRIG_BACK, ECHO_BACK);

  Serial.print("Front: "); 
  Serial.print(distanceFront);
  Serial.print(" | Back: ");
  Serial.println(distanceBack);

  // Safe distance set to 20 cm for better response time
  if (distanceFront < 20) {
    stopMotors();
    moveBackward();
    delay(500);
    scanAndAvoidAdvanced();
  } else if (distanceBack < 20) {
    stopMotors();
    moveForward();
    delay(500);
    scanAndAvoidBackward();
  } else {
    moveForward();
  }
}

// === Distance Functions ===
long getSmoothDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 29000);
  return duration > 0 ? (duration * 0.034 / 2) : 500; // Returns distance in cm
}

// === Movement Functions ===
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

// === Advanced Servo Scanning and Avoidance ===
void scanAndAvoidAdvanced() {
  int bestAngle = 90; // Default position
  long maxDistance = 0;

  for (int angle = 0; angle <= 180; angle += 30) {
    myServo.write(angle);
    delay(300);
    long distance = getSmoothDistance(TRIG_FRONT, ECHO_FRONT);

    if (distance > maxDistance) {
      maxDistance = distance;
      bestAngle = angle;
    }
  }

  myServo.write(bestAngle);
  delay(500);

  if (bestAngle < 90) turnLeft();
  else if (bestAngle > 90) turnRight();

  delay(500);
  stopMotors();
}

// === Backward Scanning and Avoidance ===
void scanAndAvoidBackward() {
  turnLeft();
  delay(500);
  moveBackward();
  delay(500);
  stopMotors();
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
