#include <TTBOUNCE.h>

int delay_time = 0;
int mode1DelayA = 0, mode1DelayB = 0;
int mode = 0;
const uint8_t led_array[9] = {3,4,5,6,7,8,9,10,11};
const uint8_t button = 2;
uint8_t difficulty = 0;
uint8_t current_led = 0;
bool dir_flag = true; //true goes right, false goes left
bool game_ended = false;
bool is_win = false;
bool is_finished_mode = false;
bool is_finished_selecting = false;
bool isBegin = false;

//mode4 
int numbersOfPlay = 0;
int* patterns = new int[numbersOfPlay];
int select = -1;
bool inRound = true;
bool stillSelect = true;
bool correct = true;
int currentPos = 0;
int pos1 = 1;

TTBOUNCE b = TTBOUNCE(button);
int target = 0;
bool outOfBound = false;
int score=0;

void setup() {
  Serial.begin(9600);
  startUp();
  modeStart();
}

void loop() {
  modePlay();
  pressReset();
}
