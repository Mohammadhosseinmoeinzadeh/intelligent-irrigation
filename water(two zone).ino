#include <LiquidCrystal.h>   

LiquidCrystal lcd(7,6,5,4,3,2);
int set = 50;
int set2 = 50;
void setup(){
  analogReference(DEFAULT);

  pinMode(A0, INPUT);  
  pinMode(A1, INPUT);

  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);

  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(0, OUTPUT);

  lcd.begin(16, 2);   

    for (int a = 0;a <16;a++)
  {
    delay(200);    
    lcd.setCursor(4, 0);               
    lcd.print("Loading"); 
    lcd.setCursor(a, 1);              
    lcd.print("#");   
  } 

}
void loop(){

  float i ;
  float i2;

  int   YL69;
  int   kh;

  
  float mi2=0;

  
  float mi22=0;

  int x = 0;

  float z;
  float z2;


    if (digitalRead(8)==LOW)
  {
    digitalWrite(10,HIGH);
    delay(30);
    digitalWrite(10,LOW);
    set = set+5;
    if (set > 100){set = 0;}
   }
      if (digitalRead(9)==LOW)
        {
          digitalWrite(10,HIGH);
          delay(30);
          digitalWrite(10,LOW);
          set = set-5;
          if (set<0)
          {
           set = 0;
          }
        }
  
  if (digitalRead(12)==LOW)
  {
    digitalWrite(10,HIGH);
    delay(30);
    digitalWrite(10,LOW);
    set2 = set2+5;
    if (set2 > 100){set2 = 0;}
   }
      if (digitalRead(13)==LOW)
        {
          digitalWrite(10,HIGH);
          delay(30);
          digitalWrite(10,LOW);
          set2 = set2-5;
          if (set2<0)
          {
           set2 = 0;
          }
        }
  

  i = analogRead(A0);  
  i2 = analogRead(A1); 

  YL69 = (100 - (i * 100) / 1023)-8 ;
  kh = (100 - (i2 * 100) / 1023)-8 ;

  for(x=0;x<=2;x++){
    delay(250);
    mi2 +=YL69;
    mi22 +=kh;
  }

  z=mi2/2;
  z2=mi22/2;

  if (z>100){
    z = 100;
  }

if (z2>100){
    z2 = 100;
  }
  
  lcd.clear();                       
  lcd.print("Z1=");          
  lcd.print(z);                   
  lcd.print("%");

  lcd.print("Z2=");          
  lcd.print(z2);                   
  lcd.print("%");


  lcd.setCursor(1, 1);               
  lcd.print("SZ1=");          
  lcd.print(set);                   
  lcd.print("% ");

  lcd.print("SZ2=");          
  lcd.print(set2);                   
  lcd.print("%");  

  delay(200);  

    if (set > z)
    {
      digitalWrite(11,LOW);
    }
    else
    {
      digitalWrite(11,HIGH);
    }

        if (set2 > z2)
    {
      digitalWrite(0,LOW);
    }
    else
    {
      digitalWrite(0,HIGH);
    }

}