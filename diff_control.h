// Class to establish and control differential stearing.

// Very simple steering directions.
//  Straight
//  Left
//  Right
//  Stop

struct diff_con
{
  uint8_t l_1;
  uint8_t l_2;
  uint8_t l_3;
  uint8_t l_4;
  uint8_t e_1_4;

  int last_dir{};

  diff_con(uint8_t L_1, uint8_t L_2, uint8_t L_3, uint8_t L_4, uint8_t E_1_4);
  void set();
  void stop();
  void right();
  void left();
  void straight();
  void backwards();
  void set_dir_manual(String dir); 
  void set_dir_auto(int dir); 
};

diff_con::diff_con(uint8_t L_1, uint8_t L_2, uint8_t L_3, uint8_t L_4, uint8_t E_1_4)
{
  l_1 = L_1;
  l_2 = L_2;
  l_3 = L_3;
  l_4 = L_4;
  e_1_4 = E_1_4;
  last_dir = 0;
}

void diff_con::set()
{
  pinMode(l_1, OUTPUT);
  pinMode(l_2, OUTPUT);
  pinMode(l_3, OUTPUT);
  pinMode(l_4, OUTPUT);
  pinMode(e_1_4, OUTPUT);

  digitalWrite(l_1, LOW);
  digitalWrite(l_2, LOW);
  digitalWrite(l_3, LOW);
  digitalWrite(l_4, LOW);
  digitalWrite(e_1_4, HIGH);
}

void diff_con::stop()
{
  digitalWrite(l_1,LOW);
  digitalWrite(l_2,LOW);
  digitalWrite(l_3,LOW);
  digitalWrite(l_4,LOW);
  last_dir = 3;
}

void diff_con::right()
{
  digitalWrite(l_1,LOW);
  digitalWrite(l_2,HIGH);
  digitalWrite(l_3,HIGH);
  digitalWrite(l_4,LOW);
  last_dir = 2;
}

void diff_con::left()
{
  digitalWrite(l_1,HIGH);
  digitalWrite(l_2,LOW);
  digitalWrite(l_3,LOW);
  digitalWrite(l_4,HIGH);
  last_dir = 1;
}

void diff_con::straight()
{
  digitalWrite(l_1,LOW);
  digitalWrite(l_2,HIGH);
  digitalWrite(l_3,LOW);
  digitalWrite(l_4,HIGH);
  last_dir = 0;
}

void diff_con::backwards()
{
  digitalWrite(l_1,HIGH);
  digitalWrite(l_2,LOW);
  digitalWrite(l_3,HIGH);
  digitalWrite(l_4,LOW);
  last_dir = 4;
}

void diff_con::set_dir_manual(String dir)
{
  if(dir == "0")
  {
    if(last_dir == 4)
    {
      stop();
      delay(100);
    }
    straight();
  }
  else if(dir == "1")
  {
    if(last_dir == 2)
    {
      stop();
      delay(100);
    }
    left();
  }
  else if(dir == "2")
  {
    if(last_dir == 1)
    {
      stop();
      delay(100);
    }
    right();
  }
  else if(dir == "3")
  {
    stop();
  }
  else if(dir == "4")
  {
    if(last_dir == 0)
    {
      stop();
      delay(100);
    }
    backwards();
  }
  else
  {
    stop();
  }
}

void diff_con::set_dir_auto(int dir)
{
  if(dir == 0)
  {
    if(last_dir == 4)
    {
      stop();
      delay(100);
    }
    straight();
  }
  else if(dir == 1)
  {
    if(last_dir == 2)
    {
      stop();
      delay(100);
    }
    left();
  }
  else if(dir == 2)
  {    
    if(last_dir == 1)
    {
      stop();
      delay(100);
    }
    right();
  }
  else if(dir == 3)
  {
    stop();
  }
  else if(dir == 4)
  {
    if(last_dir == 0)
    {
      stop();
      delay(100);
    }
    backwards();
  }
  else
  {
    stop();
  }
}