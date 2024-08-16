#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(13, 12);  // Initialize sensor that uses digital pins 13 and 12.

int primeiroLed = 5;
int segundoLed = 6;
int terceiroLed = 7;


void setup () {
    pinMode(primeiroLed, OUTPUT);
    pinMode(segundoLed, OUTPUT);
    pinMode(terceiroLed, OUTPUT);
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}

void loop () {
    float distancia = distanceSensor.measureDistanceCm();

    if (distancia <= 7) {
      digitalWrite(primeiroLed, HIGH);
      digitalWrite(segundoLed, LOW);
      digitalWrite(terceiroLed, LOW);
    }
    else if (distancia > 7 && distancia <= 15) {
      digitalWrite(primeiroLed, HIGH);
      digitalWrite(segundoLed, HIGH);
      digitalWrite(terceiroLed, LOW);
    }
    else {
      digitalWrite(primeiroLed, HIGH);
      digitalWrite(segundoLed, HIGH);
      digitalWrite(terceiroLed, HIGH);
    }
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    Serial.println(distanceSensor.measureDistanceCm());
    delay(500);
}
