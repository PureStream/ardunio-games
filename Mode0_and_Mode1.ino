void mode0P() {
  while(!game_ended) {
    if (mode==1) delay_time = random(mode1DelayA,mode1DelayB+1);
    move_led();
  }
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
  game_ended = false;
  is_win = false;
  delay(1000);
  if (random(2)) current_led = 0;
  else current_led = 8;
}

void move_led() {
  digitalWrite(led_array[current_led], HIGH);
  delay(delay_time);
  digitalWrite(led_array[current_led], LOW);
  if(current_led == 8){
    dir_flag = false;
    current_led -= 1;
  }
  else if(current_led == 0){
    dir_flag = true;
    current_led += 1;
  }
  else if(dir_flag) current_led += 1;
  else if(!dir_flag) current_led -= 1;
}
