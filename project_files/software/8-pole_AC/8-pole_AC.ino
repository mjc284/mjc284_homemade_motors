int motor_AU = 9;
int motor_BU = 8;
int motor_CU = 7;
int motor_AD = 6;
int motor_BD = 5;
int motor_CD = 4;

void drive(float mode, int cycles)
{
  int cnt = 0;
  if(mode == 0)
  {
    while(cnt < cycles)
    {
      digitalWrite(motor_AU, LOW);
      digitalWrite(motor_BU, LOW);
      digitalWrite(motor_CU, LOW);
      digitalWrite(motor_AD, LOW);
      digitalWrite(motor_BD, LOW);
      digitalWrite(motor_CD, LOW);
      delay(3);
      digitalWrite(motor_AU, LOW);
      digitalWrite(motor_BU, LOW);
      digitalWrite(motor_CU, LOW);
      digitalWrite(motor_AD, LOW);
      digitalWrite(motor_BD, LOW);
      digitalWrite(motor_CD, LOW);
      delay(1);
      cnt++;
    }
  }
  else if(mode == 1)
  {
    while(cnt < cycles)
    {
      digitalWrite(motor_AU, HIGH);
      digitalWrite(motor_BU, LOW);
      digitalWrite(motor_CU, LOW);
      digitalWrite(motor_AD, LOW);
      digitalWrite(motor_BD, HIGH);
      digitalWrite(motor_CD, LOW);
      delay(3);
      digitalWrite(motor_AU, LOW);
      digitalWrite(motor_BU, LOW);
      digitalWrite(motor_CU, LOW);
      digitalWrite(motor_AD, LOW);
      digitalWrite(motor_BD, LOW);
      digitalWrite(motor_CD, LOW);
      delay(1);
      cnt++;
    }
  }
  else if(mode == 1.5)
  {
    while(cnt < cycles)
    {
      digitalWrite(motor_AU, HIGH);
      digitalWrite(motor_BU, LOW);
      digitalWrite(motor_CU, HIGH);
      digitalWrite(motor_AD, LOW);
      digitalWrite(motor_BD, HIGH);
      digitalWrite(motor_CD, LOW);
      delay(2);
      digitalWrite(motor_AU, LOW);
      digitalWrite(motor_BU, LOW);
      digitalWrite(motor_CU, LOW);
      digitalWrite(motor_AD, LOW);
      digitalWrite(motor_BD, LOW);
      digitalWrite(motor_CD, LOW);
      delay(2);
      cnt++;
    }
  }
  else if(mode == -1)
  {
    while(cnt < cycles)
    {
      digitalWrite(motor_AU, LOW);
      digitalWrite(motor_BU, HIGH);
      digitalWrite(motor_CU, LOW);
      digitalWrite(motor_AD, HIGH);
      digitalWrite(motor_BD, LOW);
      digitalWrite(motor_CD, LOW);
      delay(3);
      digitalWrite(motor_AU, LOW);
      digitalWrite(motor_BU, LOW);
      digitalWrite(motor_CU, LOW);
      digitalWrite(motor_AD, LOW);
      digitalWrite(motor_BD, LOW);
      digitalWrite(motor_CD, LOW);
      delay(1);
      cnt++;
    }
  }
  else if(mode == -1.5)
  {
    while(cnt < cycles)
    {
      digitalWrite(motor_AU, LOW);
      digitalWrite(motor_BU, HIGH);
      digitalWrite(motor_CU, LOW);
      digitalWrite(motor_AD, HIGH);
      digitalWrite(motor_BD, LOW);
      digitalWrite(motor_CD, HIGH);
      delay(2);
      digitalWrite(motor_AU, LOW);
      digitalWrite(motor_BU, LOW);
      digitalWrite(motor_CU, LOW);
      digitalWrite(motor_AD, LOW);
      digitalWrite(motor_BD, LOW);
      digitalWrite(motor_CD, LOW);
      delay(2);
      cnt++;
    }
  }
  else if(mode == 2)
  {
    while(cnt < cycles)
    {
      digitalWrite(motor_AU, LOW);
      digitalWrite(motor_BU, LOW);
      digitalWrite(motor_CU, HIGH);
      digitalWrite(motor_AD, LOW);
      digitalWrite(motor_BD, HIGH);
      digitalWrite(motor_CD, LOW);
      delay(3);
      digitalWrite(motor_AU, LOW);
      digitalWrite(motor_BU, LOW);
      digitalWrite(motor_CU, LOW);
      digitalWrite(motor_AD, LOW);
      digitalWrite(motor_BD, LOW);
      digitalWrite(motor_CD, LOW);
      delay(1);
      cnt++;
    }
  }
  else if(mode == 2.5)
  {
    while(cnt < cycles)
    {
      digitalWrite(motor_AU, LOW);
      digitalWrite(motor_BU, LOW);
      digitalWrite(motor_CU, HIGH);
      digitalWrite(motor_AD, HIGH);
      digitalWrite(motor_BD, LOW);
      digitalWrite(motor_CD, LOW);
      delay(4);
      cnt++;
    }
  }
  else if(mode == -2)
  {
    while(cnt < cycles)
    {
      digitalWrite(motor_AU, LOW);
      digitalWrite(motor_BU, HIGH);
      digitalWrite(motor_CU, LOW);
      digitalWrite(motor_AD, LOW);
      digitalWrite(motor_BD, LOW);
      digitalWrite(motor_CD, HIGH);
      delay(3);
      digitalWrite(motor_AU, LOW);
      digitalWrite(motor_BU, LOW);
      digitalWrite(motor_CU, LOW);
      digitalWrite(motor_AD, LOW);
      digitalWrite(motor_BD, LOW);
      digitalWrite(motor_CD, LOW);
      delay(1);
      cnt++;
    }
  }
  else if(mode == -2.5)
  {
    while(cnt < cycles)
    {
      digitalWrite(motor_AU, HIGH);
      digitalWrite(motor_BU, LOW);
      digitalWrite(motor_CU, LOW);
      digitalWrite(motor_AD, LOW);
      digitalWrite(motor_BD, LOW);
      digitalWrite(motor_CD, HIGH);
      delay(4);
      cnt++;
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(motor_AU, OUTPUT);
  pinMode(motor_BU, OUTPUT);
  pinMode(motor_CU, OUTPUT);
  pinMode(motor_AD, OUTPUT);
  pinMode(motor_BD, OUTPUT);
  pinMode(motor_CD, OUTPUT);
  drive(0, 2);
}

float x = 100;
float sequence[8] = {1, 1.5, 2, 2.5, -1, -1.5, -2, -2.5};
int index = 0;

void loop() {
  //Turn clockwise slowly.
  for(int i = 0; i < 16; i++)
  {
    drive(sequence[index], 200);
    index++;
    if(index > 7){index = 0;}
  }
  
  //Turn clockwise faster.
  for(int i = 0; i < 50; i++)
  {
    drive(sequence[index], 8);
    index++;
    if(index > 7){index = 0;}
  }
  
  //Turn clockwise fast.
  for(int i = 0; i < 2000; i++)
  {
    drive(sequence[index], 2);
    index++;
    if(index > 7){index = 0;}
  }
  
  //Rest
  drive(0, 800);

  //Turn counter-clockwise slowly.
  for(int i = 0; i < 16; i++)
  {
    drive(sequence[index], 200);
    index--;
    if(index < 0){index = 7;}
  }

  //Turn counter-clockwise faster.
  for(int i = 0; i < 50; i++)
  {
    drive(sequence[index], 8);
    index--;
    if(index < 0){index = 7;}
  }

  //Turn counter-clockwise fast.
  for(int i = 0; i < 2000; i++)
  {
    drive(sequence[index], 2);
    index--;
    if(index < 0){index = 7;}
  }

  //Rest
  drive(0, 800);
}
