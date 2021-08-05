#include <Arduino.h>

const int POTENCIOMETER = A0, BUTTON = 4, LED = 2, PWM_CHANNEL = 0,
          PWM_RES = 12, PWM_FREQ = 1000;

void setup(void) {

  Serial.begin(9600);
  
  pinMode(BUTTON, INPUT_PULLUP);

  ledcAttachPin(LED, PWM_CHANNEL);
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RES);
}

void loop(void) {

  int potenciometerReading = analogRead(POTENCIOMETER);
  bool isButtonPressed = !digitalRead(BUTTON);
  String isButtonPressedCheck = isButtonPressed ? "true" : "false";

  ledcWrite(PWM_CHANNEL, potenciometerReading);

  Serial.printf(
      "Potenciometer_Value = (%d) - PWM_LED = (%d) - Button_Pressed = (%s)\n ",
      potenciometerReading, potenciometerReading, isButtonPressedCheck);

  delay(100);
}
