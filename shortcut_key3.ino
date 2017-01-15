#include "Keyboard.h"

#define Button1 5
#define Button2 6
#define Button3 7
#define Button4 8
#define Button5 9

void setup() {
  Keyboard.begin();
  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  pinMode(Button3, INPUT_PULLUP);
  pinMode(Button4, INPUT_PULLUP);
  pinMode(Button5, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(Button1) == LOW){
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('d');
    delay(100);
    Keyboard.releaseAll();
    delay(500);
    
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_ESC);
    delay(100);
    Keyboard.releaseAll();
    
    while(digitalRead(Button1) == LOW);
  }
  
  if(digitalRead(Button2) == LOW){
    Keyboard.write(0xCE);//prtscr
    delay(100);
    
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(100);
    
    Keyboard.print("mspaint");
    Keyboard.write(KEY_RETURN);
    delay(500);
    
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('v');
    Keyboard.releaseAll();
    
    delay(100);
    Keyboard.releaseAll();
    
    while(digitalRead(Button2) == LOW);
  }
  
  if(digitalRead(Button3) == LOW){
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(100);
    
    Keyboard.print("cmd");
    Keyboard.write(KEY_RETURN);
    delay(500);
    
    Keyboard.print("echo %date%%time%");
    Keyboard.write(KEY_RETURN);
    
    delay(100);
    Keyboard.releaseAll();
    
    while(digitalRead(Button3) == LOW);
  }
  
  if(digitalRead(Button4) == LOW){
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('u');
    delay(100);
    Keyboard.releaseAll();
    
    while(digitalRead(Button4) == LOW);
  }
  
  if(digitalRead(Button5) == LOW){
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(100);
    
    Keyboard.print("notepad");
    Keyboard.write(KEY_RETURN);
    delay(500);
    Keyboard.releaseAll();

    delay(1500);
    while(digitalRead(Button5) == LOW);
    while(digitalRead(Button5) == HIGH){
      Keyboard.print("Yes! ");
      delay(500);
      Keyboard.print("Takasu ");
      delay(500);
      Keyboard.print("Clinic!");
      delay(2000);
      Keyboard.write('\n');
    }
    while(digitalRead(Button5) == LOW);
  }
  
  delay(100);
}
