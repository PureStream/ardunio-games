unsigned long lastInterrupt;

void button_pressed() {
  if(millis() - lastInterrupt > 500) {
    if (isBegin) {
      isBegin = false;
      if (mode==0||mode==1) {
        Serial.println((current_led==4) ? "Button pressed on GREEN" : (current_led==5||current_led==3) ? "Button pressed on YELLOW" : "Button pressed on RED");
        if (current_led==4) is_win = true;
        game_ended = true;
        delay(500);
      }
      else if (mode==2) {
        Serial.println("Button pressed on: " + String(current_led+1));
        if (current_led==target) is_win =true;
        game_ended = true;
        delay(500);
      }
      else if (mode==3) {
        if (current_led==8||current_led==0) outOfBound = false;
        else {
          game_ended = true;
          delay(500);
        }
      }
    }
    lastInterrupt = millis();
  }
}
