
#include <LiquidCrystal.h>   

LiquidCrystal lcd(11, 10, 9, 8, 7, 6, 5);
int set = 0;

void setup() {

  analogReference(DEFAULT);
  pinMode(A0, INPUT);         
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
   pinMode(2, OUTPUT);
    pinMode(1, OUTPUT);
  lcd.begin(16, 2);           

}
void loop() {
  float i ;                   
  int   YL69 ;
  


  if (digitalRead(3)==LOW)
  {
    digitalWrite(2,HIGH);
    delay(30);
    digitalWrite(2,LOW);
    set = set+1;
    if (set > 100){set = 0;}
    }
     if (digitalRead(4)==LOW)
    {
      digitalWrite(2,HIGH);
      delay(30);
      digitalWrite(2,LOW);
      set = set-1;
      if (set<0){ set = 0; }
      }

  i = analogRead(A0);                
  YL69 = 100 - (i * 100) / 1023 ;   
 // YL69 = 24 +YL69; 
   if (YL69 > 100)
  {
    YL69 = 100;
    }
  lcd.clear();                       
  lcd.print("Water Level= ");          
  lcd.print(YL69);                   
  lcd.print("%");                    
  lcd.setCursor(2, 1);               
  lcd.print("SET Level= ");          
  lcd.print(set);                   
  lcd.print("%");          
  delay(200);                        
 
  if (set > YL69)
  {
   digitalWrite(1,HIGH);
    }else
    {
      digitalWrite(1,LOW);
      }
 
      
  
}
