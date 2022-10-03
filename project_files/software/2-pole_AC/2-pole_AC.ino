int motor_RU = 8;
int motor_LU = 7;
int motor_RD = 5;
int motor_LD = 4;

void drive(int mode, int cycles)
{
  int cnt = 0;
  if(mode == 0)
  {
    while(cnt < cycles)
    {
      digitalWrite(motor_RU, LOW);
      digitalWrite(motor_LU, LOW);
      digitalWrite(motor_RD, LOW);
      digitalWrite(motor_LD, LOW);
      delay(3);
      digitalWrite(motor_RU, LOW);
      digitalWrite(motor_LU, LOW);
      digitalWrite(motor_RD, LOW);
      digitalWrite(motor_LD, LOW);
      delay(1);
      cnt++;
    }
  }
  else if(mode == 1)
  {
    while(cnt < cycles)
    {
      digitalWrite(motor_RU, LOW);
      digitalWrite(motor_LU, HIGH);
      digitalWrite(motor_RD, HIGH);
      digitalWrite(motor_LD, LOW);
      delay(3);
      digitalWrite(motor_RU, LOW);
      digitalWrite(motor_LU, LOW);
      digitalWrite(motor_RD, LOW);
      digitalWrite(motor_LD, LOW);
      delay(1);
      cnt++;
    }
  }
  else if(mode == -1)
  {
    while(cnt < cycles)
    {
      digitalWrite(motor_RU, HIGH);
      digitalWrite(motor_LU, LOW);
      digitalWrite(motor_RD, LOW);
      digitalWrite(motor_LD, HIGH);
      delay(3);
      digitalWrite(motor_RU, LOW);
      digitalWrite(motor_LU, LOW);
      digitalWrite(motor_RD, LOW);
      digitalWrite(motor_LD, LOW);
      delay(1);
      cnt++;
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(motor_RU, OUTPUT);
  pinMode(motor_LU, OUTPUT);
  pinMode(motor_RD, OUTPUT);
  pinMode(motor_LD, OUTPUT);
  drive(0, 2);
}

void loop() {
  //Alternate poles slowly.
  for(int i = 0; i < 4; i++)
  {
    drive(1, 17);
    drive(0, 350);
    drive(-1, 17);
    drive(0, 350);
  }

  //Alternate poles quickly, driving the rotor.
  for(int i = 0; i < 150; i++)
  {
    drive(1, 13);
    drive(0, 1);
    drive(-1, 13);
    drive(0, 1);
  }
}
