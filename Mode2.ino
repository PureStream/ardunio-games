void mode2P() {
  target = random(0,9);
  for (int i=0; i<5; i++) {
    digitalWrite(led_array[target], HIGH);
    delay(100);
    digitalWrite(led_array[target], LOW);
    delay(100);
  }
  delay(500);
  while(!game_ended) random_led();
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
}

int ifSame = -1;

void random_led() {
  while (ifSame==current_led) current_led = random(0,9);
  ifSame = current_led;
  digitalWrite(led_array[current_led], HIGH);
  delay(delay_time);
  digitalWrite(led_array[current_led], LOW);
}
