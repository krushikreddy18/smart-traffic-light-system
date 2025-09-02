#define IR_SENSOR_INCREASE_1 A0
#define IR_SENSOR_DECREASE_1 A1
#define IR_SENSOR_INCREASE_2 A4
#define IR_SENSOR_DECREASE_2 A5
#define IR_SENSOR_INCREASE_3 A2
#define IR_SENSOR_DECREASE_3 A3

#define RED_LIGHT_1 13
#define YELLOW_LIGHT_1 12
#define GREEN_LIGHT_1 11
#define RED_LIGHT_2 10
#define YELLOW_LIGHT_2 9
#define GREEN_LIGHT_2 8
#define RED_LIGHT_3 7
#define YELLOW_LIGHT_3 6
#define GREEN_LIGHT_3 5

int count1 = 0;
int count2 = 0;
int count3 = 0;
int greenPriority = -1; // -1 means no priority

void setup() {
  pinMode(IR_SENSOR_INCREASE_1, INPUT);
  pinMode(IR_SENSOR_DECREASE_1, INPUT);
  pinMode(IR_SENSOR_INCREASE_2, INPUT);
  pinMode(IR_SENSOR_DECREASE_2, INPUT);
  pinMode(IR_SENSOR_INCREASE_3, INPUT);
  pinMode(IR_SENSOR_DECREASE_3, INPUT);

  pinMode(RED_LIGHT_1, OUTPUT);
  pinMode(YELLOW_LIGHT_1, OUTPUT);
  pinMode(GREEN_LIGHT_1, OUTPUT);
  pinMode(RED_LIGHT_2, OUTPUT);
  pinMode(YELLOW_LIGHT_2, OUTPUT);
  pinMode(GREEN_LIGHT_2, OUTPUT);
  pinMode(RED_LIGHT_3, OUTPUT);
  pinMode(YELLOW_LIGHT_3, OUTPUT);
  pinMode(GREEN_LIGHT_3, OUTPUT);
  
  digitalWrite(RED_LIGHT_1, HIGH);
  digitalWrite(RED_LIGHT_2, HIGH);
  digitalWrite(RED_LIGHT_3, HIGH);
}

void loop() {
  int inc1 = digitalRead(IR_SENSOR_INCREASE_1);
  int dec1 = digitalRead(IR_SENSOR_DECREASE_1);
  int inc2 = digitalRead(IR_SENSOR_INCREASE_2);
  int dec2 = digitalRead(IR_SENSOR_DECREASE_2);
  int inc3 = digitalRead(IR_SENSOR_INCREASE_3);
  int dec3 = digitalRead(IR_SENSOR_DECREASE_3);
  
  if (inc1 == LOW) count1++;
  if (dec1 == LOW && count1 > 0) { count1--; greenPriority = 1; }
  if (inc2 == LOW) count2++;
  if (dec2 == LOW && count2 > 0) { count2--; greenPriority = 2; }
  if (inc3 == LOW) count3++;
  if (dec3 == LOW && count3 > 0) { count3--; greenPriority = 3; }

  manageTrafficLights();
}

void manageTrafficLights() {
  if (greenPriority != -1) {
    // Prioritize the light with decreasing count
    switch (greenPriority) {
      case 1:
        digitalWrite(GREEN_LIGHT_1, HIGH);
        digitalWrite(RED_LIGHT_1, LOW);
        digitalWrite(GREEN_LIGHT_2, LOW);
        digitalWrite(RED_LIGHT_2, HIGH);
        digitalWrite(GREEN_LIGHT_3, LOW);
        digitalWrite(RED_LIGHT_3, HIGH);
        break;
      case 2:
        digitalWrite(GREEN_LIGHT_1, LOW);
        digitalWrite(RED_LIGHT_1, HIGH);
        digitalWrite(GREEN_LIGHT_2, HIGH);
        digitalWrite(RED_LIGHT_2, LOW);
        digitalWrite(GREEN_LIGHT_3, LOW);
        digitalWrite(RED_LIGHT_3, HIGH);
        break;
      case 3:
        digitalWrite(GREEN_LIGHT_1, LOW);
        digitalWrite(RED_LIGHT_1, HIGH);
        digitalWrite(GREEN_LIGHT_2, LOW);
        digitalWrite(RED_LIGHT_2, HIGH);
        digitalWrite(GREEN_LIGHT_3, HIGH);
        digitalWrite(RED_LIGHT_3, LOW);
        break;
    }
    // Reset priority if count reaches zero
    if ((greenPriority == 1 && count1 == 0) ||
        (greenPriority == 2 && count2 == 0) ||
        (greenPriority == 3 && count3 == 0)) {
      greenPriority = -1;
    }
  } else {
    // Find the intersection with the highest count and manage lights accordingly
    int maxCount = max(max(count1, count2), count3);
    if (maxCount > 0) {
      if (count1 == maxCount) {
        digitalWrite(GREEN_LIGHT_1, HIGH);
        digitalWrite(RED_LIGHT_1, LOW);
        digitalWrite(GREEN_LIGHT_2, LOW);
        digitalWrite(RED_LIGHT_2, HIGH);
        digitalWrite(GREEN_LIGHT_3, LOW);
        digitalWrite(RED_LIGHT_3, HIGH);
      } else if (count2 == maxCount) {
        digitalWrite(GREEN_LIGHT_1, LOW);
        digitalWrite(RED_LIGHT_1, HIGH);
        digitalWrite(GREEN_LIGHT_2, HIGH);
        digitalWrite(RED_LIGHT_2, LOW);
        digitalWrite(GREEN_LIGHT_3, LOW);
        digitalWrite(RED_LIGHT_3, HIGH);
      } else {
        digitalWrite(GREEN_LIGHT_1, LOW);
        digitalWrite(RED_LIGHT_1, HIGH);
        digitalWrite(GREEN_LIGHT_2, LOW);
        digitalWrite(RED_LIGHT_2, HIGH);
        digitalWrite(GREEN_LIGHT_3, HIGH);
        digitalWrite(RED_LIGHT_3, LOW);
      }
    } else {
      // All lights red if all counts are zero
      digitalWrite(GREEN_LIGHT_1, LOW);
      digitalWrite(RED_LIGHT_1, HIGH);
      digitalWrite(GREEN_LIGHT_2, LOW);
      digitalWrite(RED_LIGHT_2, HIGH);
      digitalWrite(GREEN_LIGHT_3, LOW);
      digitalWrite(RED_LIGHT_3, HIGH);
    }
  }
}