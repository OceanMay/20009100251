#include <MsTimer2.h>               //定时器库的 头文件
unsigned char time=0;
 
void flash()                        //中断处理函数，改变灯的状态
{                        
  time++;
  if(time>=99)
  time=0;;
}
 
void setup() 
{
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
 
  MsTimer2::set(1000, flash);        // 中断设置函数，每 1000ms 进入一次中断
  MsTimer2::start();                 //开始计时
}
void num(unsigned char c)
{
 switch(c)
 {
  case 0:{
          digitalWrite(8, LOW);
          digitalWrite(9, LOW); 
          digitalWrite(10, LOW);
          digitalWrite(11, LOW); 
         }
  break; 
  case 1:{
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW); 
          digitalWrite(10, LOW);
          digitalWrite(11, LOW); 
         }
  break; 
  case 2:{
          digitalWrite(8, LOW);
          digitalWrite(9, HIGH); 
          digitalWrite(10, LOW);
          digitalWrite(11, LOW); 
         }
  break; 
  case 3:{
          digitalWrite(8, HIGH);
          digitalWrite(9, HIGH); 
          digitalWrite(10, LOW);
          digitalWrite(11, LOW); 
         }
  break;         
  case 4:{
          digitalWrite(8, LOW);
          digitalWrite(9, LOW); 
          digitalWrite(10, HIGH);
          digitalWrite(11, LOW); 
         }
  break; 
  case 5:{
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW); 
          digitalWrite(10, HIGH);
          digitalWrite(11, LOW); 
         }
  break; 
  case 6:{
          digitalWrite(8, LOW);
          digitalWrite(9, HIGH); 
          digitalWrite(10, HIGH);
          digitalWrite(11, LOW); 
         }
  break; 
  case 7:{
          digitalWrite(8, HIGH);
          digitalWrite(9, HIGH); 
          digitalWrite(10, HIGH);
          digitalWrite(11, LOW); 
         }
  break; 
  case 8:{
          digitalWrite(8, LOW);
          digitalWrite(9, LOW); 
          digitalWrite(10, LOW);
          digitalWrite(11, HIGH); 
         }
  break; 
  case 9:{
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW); 
          digitalWrite(10, LOW);
          digitalWrite(11, HIGH); 
           }
  break; 
  } 
}
void display()
{
  num(time%10);
  digitalWrite(12, LOW);
  delay(100);
  digitalWrite(12, HIGH);
  num(time/10);
  digitalWrite(13, LOW);  
  delay(100);
  digitalWrite(13, HIGH);
}
void key()
{
unsigned char key_flag=1;
 key_flag=digitalRead(7);
 if(key_flag==LOW)
 {
  delay(5);
   if(key_flag==LOW) time=0;
 }
}
 
void loop()
{
 display();
 key();
}
