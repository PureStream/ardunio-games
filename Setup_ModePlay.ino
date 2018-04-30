void(* resetFunc) (void) = 0;

void startUp() {
  Serial.println("Select a mode.(1-Classic 2-Chaos 3-Precision 4-PingPong 5-Memory)");
  for(int i=0;i<9;i++) pinMode(led_array[i], OUTPUT);
  b.attachDoubleClick(doubleClick);
  b.attachClick(click);
  b.setActiveLow();
  b.enablePullup();
  sweep();
  digitalWrite(led_array[mode], HIGH);
  Serial.println("Mode: " + String(mode+1));
  while (!is_finished_mode) b.update();
}

void pressReset() {
  if(!digitalRead(button)) {
    Serial.println("The game is resetting.");
    for (int i=0; i<2; i++) pulse();
    while(!digitalRead(button))
    delay(100);
    resetFunc();
  }
}

void modeStart() {
  randomSeed(analogRead(0));
  Serial.println("The game is setting up!");
  sweep();
  difficulty = 0;
  digitalWrite(led_array[difficulty], HIGH);
  Serial.println("Difficulty level is: "+String(difficulty+1));
  while(!is_finished_selecting) b.update();
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), button_pressed, FALLING);
  delay(1200);
}

void modePlay() {
  isBegin = true;
  Serial.println("The game has begun!");
  if (mode==0 || mode==1) mode0P();
  else if (mode==2) mode2P();
  else if (mode==3) mode3P();
  else if (mode==4) mode4P();
}
