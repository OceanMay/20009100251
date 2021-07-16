// C++ code
//
int i=13;
int j=0;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  for(i=13;i>5;i--)
  {
    digitalWrite(i,HIGH);
    delay(250);
    digitalWrite(i,LOW);
  }
}
