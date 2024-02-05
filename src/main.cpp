#include <Arduino.h>
#include <Servo.h>

Servo myServo;


int RPWM = 5; // Digital/PWM pin 5 to the RPWM on the BTS7960
int LPWM = 6; // Digital/PWM pin 6 to the LPWM on the BTS7960

// Enable "Left" and "Right" movement
int L_EN = 8; // connect Digital/PWM pin 7 to L_EN on the BTS7960
int R_EN = 7; // connect Digital/PWM pin 8 to R_EN on the BTS7960
int LED = 9;

void setup()
{
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);
  pinMode(L_EN, OUTPUT);
  pinMode(R_EN, OUTPUT);
  pinMode(LED, OUTPUT);
  myServo.attach(A1);  // attaches the servo on pin 9 to the Servo object
  myServo.write(90); // set initial position to 90 degrees (Should be a straight line)

  digitalWrite(RPWM, LOW);
  digitalWrite(LPWM, LOW);
  Serial.begin(9600);

  // enable "Right" and "Left" movement on the HBridge
  //  Notice use of digitalWrite to simply turn it on and keep it on.

  // Blink the LED to indicate system about to start
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
  }

  
}

void loop()
{
  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);
  
  Serial.println("Forward");
  analogWrite(LED, 0);
  analogWrite(RPWM, 100);
  analogWrite(LPWM, 0);
  delay(2000);

  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
  delay(2000);
}