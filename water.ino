#include <EEPROM.h>
#include <LiquidCrystal.h>   

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int set = 50;

void setup() {

  analogReference(DEFAULT);
  pinMode(A0, INPUT);         
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  lcd.begin(16, 2);   
         

}
void loop() {
  float i ;                   
  int   YL69 ;
  float mi;
  float mi2=0;
  int x = 0;
  float z;
    
  


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
      if (set<0){ set = 0; }
      }

  i = analogRead(A0);                
  YL69 = 100 - (i * 100) / 1023 ;   
 // YL69 = 24 +YL69; 
  mi = YL69 - 8;
  for (x=0;x<=60;x++){
    delay(250);
    mi2 +=mi;
    }
   z = mi2/60;
   if (z > 100)
  {
    z = 100;
    }
  lcd.clear();                       
  lcd.print("Water Level=");          
  lcd.print(z);                   
  lcd.print("%");                    
  lcd.setCursor(2, 1);               
  lcd.print("SET Level= ");          
  lcd.print(set);                   
  lcd.print("%");          
  delay(200);                        
 
  if (set > z)
  {
   digitalWrite(11,LOW);
    }else
    {
      digitalWrite(11,HIGH);
      }
 
      
  
}
