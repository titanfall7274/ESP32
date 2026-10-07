// 02. 인터럽트: 버튼을 누를 때마다 LED 토글 (디바운싱 없음)
// 바운싱 관찰용. 한 번 눌러도 인터럽트가 여러 번 들어와 토글이 랜덤해 보인다.

const int LED = 26;
const int BTN = 27;

// volatile: ISR에서 바뀌는 변수는 매번 메모리에서 다시 읽게 함
volatile bool pressed = false;  // ISR → loop로 "눌렸다" 전달
volatile int isrCount = 0;      // 인터럽트가 실제로 들어온 횟수

bool ledOn = false;
int handledCount = 0;           // loop가 처리한 횟수 (bool이라 여러 인터럽트가 합쳐질 수 있음)

// IRAM_ATTR: ISR을 플래시가 아니라 RAM에 올려둠
void IRAM_ATTR onPress() {
  isrCount++;
  pressed = true;  // 깃발만 세우고 바로 끝
}

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);

  // FALLING: 1→0 되는 순간 (풀업이라 누르는 순간)
  attachInterrupt(digitalPinToInterrupt(BTN), onPress, FALLING);
}

void loop() {
  if (pressed) {
    pressed = false;
    ledOn = !ledOn;
    digitalWrite(LED, ledOn);

    Serial.printf("처리 %d번 / 인터럽트 %d번\n", ++handledCount, isrCount);
  }
}
