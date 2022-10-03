int motor_RU = 8;
int motor_LU = 7;
int motor_RD = 5;
int motor_LD = 4;

void drive(int mode)
{
  if(mode == 0)
  {
    digitalWrite(motor_RU, LOW);
    digitalWrite(motor_LU, LOW);
    digitalWrite(motor_RD, LOW);
    digitalWrite(motor_LD, LOW);
  }
  else if(mode == 1)
  {
    digitalWrite(motor_RU, LOW);
    digitalWrite(motor_LU, HIGH);
    digitalWrite(motor_RD, HIGH);
    digitalWrite(motor_LD, LOW);
  }
  else if(mode == -1)
  {
    digitalWrite(motor_RU, HIGH);
    digitalWrite(motor_LU, LOW);
    digitalWrite(motor_RD, LOW);
    digitalWrite(motor_LD, HIGH);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(motor_RU, OUTPUT);
  pinMode(motor_LU, OUTPUT);
  pinMode(motor_RD, OUTPUT);
  pinMode(motor_LD, OUTPUT);
  drive(0);
}

float x = 100;
float cnt = 75;

void loop() {
  //Drive rotor with slow sinusoidal PWM current waveform.
  x = int(sin(cnt/100*2*PI)*50 + 50);
  if(cnt < 100){cnt++;}
  else{cnt = 0;}
  drive(0);
  delay(x);
  drive(-1);
  delay(100 - x);
}
