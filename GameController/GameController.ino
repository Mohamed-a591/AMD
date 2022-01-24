#include <Keyboard.h>

#define pb1 2 
#define pb2 3
#define pb3 4
#define pb4 5
#define pb5 6
#define pb6 7
#define SRight 7
#define SLeft 8

void setup() {
  // put your setup code here, to run once:
  pinMode(pb1, INPUT_PULLUP);
  pinMode(pb2, INPUT_PULLUP);
  pinMode(pb3, INPUT_PULLUP);
  pinMode(pb4, INPUT_PULLUP);
  pinMode(pb5, INPUT_PULLUP);
  pinMode(pb6, INPUT_PULLUP);
  pinMode(SRight, INPUT);
  pinMode(SLeft, INPUT);
  Keyboard.begin();
}
  for(int i=8; i<=13; i++){
      pinMode(i, OUTPUT);
      digitalWrite(i, LOW);
  }
  
  for(int i=18; i<=19; i++){
      pinMode(i, OUTPUT);
      digitalWrite(i, HIGH);
  }
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(pb6)!=HIGH){
    // put your main code here, to run repeatedly:
    Serial.println(digitalRead(pb1));
    if(digitalRead(pb1) == LOW){
      Keyboard.press(KEY_RIGHT_ARROW);
      delay(200);
    }else if(digitalRead(pb2) == LOW) {
      Keyboard.press(KEY_LEFT_ARROW);
      delay(200);
    }else if(digitalRead(pb3) == LOW) {
      Keyboard.press(KEY_UP_ARROW);
      delay(200);
    }else if(digitalRead(pb4) == LOW) {
      Keyboard.press(KEY_DWON_ARROW);
      delay(200);
    }else if(digitalRead(pb5) == LOW) {
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(200);
    }
    else {
      Keyboard.releaseAll();
    }
  }else{
      if(digitalRead(SRight) == HIGH) {
        Keyboard.press(KEY_RIGHT_ARROW);
        delay(200);
      }else if(digitalRead(SLeft) == HIGH) {
        Keyboard.press(KEY_LEFT_ARROW);
        delay(200);
      }else {
        Keyboard.releaseAll();
      }   
  }
}
