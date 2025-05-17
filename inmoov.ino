#include <Servo.h>

Servo thumb;
Servo indexFinger;  // Renamed to avoid conflict with variable
Servo middle;
Servo ring;
Servo pinky;

void setup() {
  Serial.begin(9600);

  thumb.attach(3);
  indexFinger.attach(5);
  middle.attach(6);
  ring.attach(9);
  pinky.attach(10);
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    int angles[5];
    int i = 0;
    char* ptr = strtok((char*)data.c_str(), ",");

    while (ptr != NULL && i < 5) {
      angles[i++] = atoi(ptr);
      ptr = strtok(NULL, ",");
    }

    if (i == 5) {
      thumb.write(angles[0]);
      indexFinger.write(angles[1]);
      middle.write(angles[2]);
      ring.write(angles[3]);
      pinky.write(angles[4]);
    }
  }
}
