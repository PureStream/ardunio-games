void pulse() {
  for(int i=0; i<9;i++) digitalWrite(led_array[i], HIGH);
  delay(100);
  for(int i=0; i<9;i++) digitalWrite(led_array[i], LOW);
}

void sweepRL() {
  for(int i=0; i<9;i++){
    digitalWrite(led_array[i], HIGH);
    delay(50);
    digitalWrite(led_array[i], LOW);
  }
}

void sweepLR() {
  for(int i=8; i>=0;i--){
    digitalWrite(led_array[i], HIGH);
    delay(50);
    digitalWrite(led_array[i], LOW);
  }
}

void sweep() {
  sweepRL();
  sweepLR();
  sweepLR();
  sweepRL();
}

void sweepI() {
  for (int i=0; i<4; i++) {
    digitalWrite(led_array[i], HIGH);
    digitalWrite(led_array[8-i], HIGH);
    delay(50);
    digitalWrite(led_array[i], LOW);
    digitalWrite(led_array[8-i], LOW);
  }
  digitalWrite(led_array[4], HIGH);
  delay(50);
  digitalWrite(led_array[4], LOW);
  for (int i=0; i<4; i++) {
    digitalWrite(led_array[3-i], HIGH);
    digitalWrite(led_array[i+5], HIGH);
    delay(50);
    digitalWrite(led_array[3-i], LOW);
    digitalWrite(led_array[i+5], LOW);
  }
}
