//left side motors ( front left and back left) connected to OUT1 & OUT2
#define L1 1        // input1 pin 
#define L2 2        // input2 pin 

//right side motors ( front right and back right) connected to OUT3 & OUT4
#define R1 3        // input3 pin 
#define R2 4        // input4 pin 

// IR sensors pin
#define IR_LEFT 5
#define IR_RIGHT 6

void setup() {
  //setup motor pins as output
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);

  // setup IR sensor pins as input
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);
}

void loop() {
  // read both left and right sensor values. It may return either 0(false) or 1 (true)
  int ir_left_detected = digitalRead(IR_LEFT);
  int ir_right_detected = digitalRead(IR_RIGHT);

  if (ir_right_detected == 0 && ir_left_detected == 0) {
    forward();  //FORWARD
  }

  else if (ir_right_detected == 0 && ir_left_detected == 1) {
    right();  //Move Right
  }

  else if (ir_right_detected == 1 && ir_left_detected == 0) {
    left();  //Move Left
  }

  else if (ir_right_detected == 1 && ir_left_detected == 1) {
    halt();  //STOP
  }
}

//move forward
void forward() {
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
}

//move backward
void back() {
  digitalWrite(L2, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(R2, HIGH);
  digitalWrite(R1, LOW);
}

//move left
void left() {
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
}

//move right
void right() {
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
}
// stop
void halt() {
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
}