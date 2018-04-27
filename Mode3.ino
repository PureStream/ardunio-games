bool checkIfStart = false;

void mode3P() {
  int thisDelay = delay_time;
  while(!game_ended) {
    move_led_mode3();
    checkIfStart = true;
  }
  score=0;
  Serial.print("GAME OVER");
  if(is_win) {
    Serial.print(" AND YOU WON!");
    for(int i=0; i<5;i++){
      pulse();
      delay(100);
    }
  }
  Serial.println("");
  sweepI();
  checkIfStart = false;
  game_ended = false;
  is_win = false;
  delay(1000);
  if (random(2)) current_led = 0;
  else current_led = 8;
  outOfBound = false;
  delay_time = thisDelay;
}

void move_led_mode3() {
  digitalWrite(led_array[current_led], HIGH);
  delay(delay_time);
  digitalWrite(led_array[current_led], LOW);
  if (checkIfStart && !outOfBound) {
    if (current_led==8||current_led==0) {
      delay_time -= (difficulty<8) ? 10+(difficulty*3) : 74;
      score++;
      if (delay_time<=0 || (score==10 && difficulty<8)) {
        game_ended = true;
        is_win = true;
      }
      Serial.println("Score: " + String(score));
    }
  }
  if(current_led == 8){
    if (outOfBound) game_ended = true;
    dir_flag = false;
    current_led -= 1;
  }
  else if(current_led == 0){
    if (outOfBound) game_ended = true;
    dir_flag = true;
    current_led += 1;
  }
  else if(dir_flag) current_led += 1;
  else if(!dir_flag) current_led -= 1;
  outOfBound = true;
  isBegin = true;
}
