
void mode4P() {
  for (int i=0; i<(numbersOfPlay); i++) patterns[i] = random(5,9);
  pos1 = 1;
  currentPos = 0;
  while (!game_ended) {
    current_led = 0;
    stillSelect = true;
    for (int i=0; i<pos1; i++) {
      digitalWrite(led_array[patterns[i]], HIGH);
      delay(500);
      digitalWrite(led_array[patterns[i]], LOW);
      delay(500);
    }
    digitalWrite(led_array[current_led], HIGH);
    while (stillSelect) b.update();
    pos1++;
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
}

