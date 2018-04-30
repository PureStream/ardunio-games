
void mode4P() {
  for (int i=0; i<(numbersOfPlay); i++) patterns[i] = random(5,9);
  for (int i=0; i<(numbersOfPlay); i++) Serial.println(patterns[i]);
  arrayPos = 1;
  currentPos = 0;
  while (!game_ended) {
    current_led = 0;
    digitalWrite(led_array[4], HIGH);
    delay(500);
    stillSelect = true;
    for (int i=0; i<arrayPos; i++) {
      digitalWrite(led_array[patterns[i]], HIGH);
      delay(500);
      digitalWrite(led_array[patterns[i]], LOW);
      delay(500);
    }
    digitalWrite(led_array[current_led], HIGH);
    while (stillSelect) b.update();
    digitalWrite(led_array[current_led], LOW);
    arrayPos++;
    currentPos = 0;
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

