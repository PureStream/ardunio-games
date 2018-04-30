void doubleClick() {
  if (is_finished_selecting && mode==4) {
    if (current_led != 8-patterns[currentPos]) {
      game_ended = true;
      stillSelect = false;
    }
    currentPos++;
    if (currentPos >= arrayPos) stillSelect = false;
    if ((currentPos >= numbersOfPlay) && !game_ended) {
      game_ended = true;
      is_win = true;
    }
    if (!is_win && stillSelect && !game_ended) {
      digitalWrite(led_array[current_led], LOW);
      delay(100);
      digitalWrite(led_array[current_led], HIGH);
    }
  }
  else if (!is_finished_mode) {
    is_finished_mode = true;
    Serial.print("You have confirmed with the ");
    Serial.println((mode==0) ? "classic mode" : (mode==1) ? "chaos mode" : (mode==2) ? "precision mode" : (mode==3) ? "ping pong mode" : "memory mode");
  }
  else {
    is_finished_selecting = true;
    if (mode==0) delay_time = (difficulty<8) ? floor(500/(difficulty+2)) : 25; 
    else if (mode==1) {
      mode1DelayA = (!difficulty==8) ? floor(500/((difficulty*5)+10)) : 5;
      mode1DelayB = (difficulty<5) ? 300 : (difficulty<7) ? 200 : (difficulty==7) ? 120 : 30;
    }
    else if (mode==2) delay_time = (difficulty<8) ? floor(500-(difficulty*38)) : 150;
    else if (mode==3) delay_time = floor(500-(difficulty*25));
    else if (mode==4) numbersOfPlay = (difficulty<8) ? 5+difficulty*2 : 30;
    Serial.println((difficulty<8) ? "Difficulty: " + String(difficulty+1) : "Diffuculty: GOD");
    sweep();
  }
}

void click() {
  if (is_finished_selecting && mode==4) {
    digitalWrite(led_array[current_led], LOW);
    current_led++;
    if (current_led>3) current_led = 0;
    digitalWrite(led_array[current_led], HIGH);
    Serial.println("Now selecting: " + String(current_led));
  }
  else if (!is_finished_mode) {
    digitalWrite(led_array[mode], LOW);
    mode++;
    if (mode>4) mode = 0;
    digitalWrite(led_array[mode], HIGH);
    Serial.println("Mode: " + String(mode+1));
  }
  else {
    digitalWrite(led_array[difficulty], LOW);
    difficulty++;
    if(difficulty>8) difficulty = 0;
    digitalWrite(led_array[difficulty], HIGH);
    Serial.println((difficulty<8) ? "Difficulty level is: " + String(difficulty+1) : "Difficulty level is: GODLEVEL");
  }
  delay(100);
}
