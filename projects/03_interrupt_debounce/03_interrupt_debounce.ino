// 03. 인터럽트 + 디바운싱: 한 번 누르면 정확히 한 번 토글
// 1단계 (ISR): 마지막 인정 시점에서 200ms 안의 인터럽트는 무시
// 2단계 (loop): 20ms 기다린 뒤 아직 눌려 있을 때만 인정 → 뗄 때 튀는 것도 걸러짐

const int LED = 26;
const int BTN = 27;

volatile bool pressed = false;        // ISR → loop로 "눌렸다" 전달
volatile int isrCount = 0;            // 인터럽트가 실제로 들어온 횟수
volatile unsigned long lastTime = 0;  // 마지막으로 인정한 눌림 시각(ms)

bool ledOn = false;
int pressCount = 0;                   // 인정된 누름 횟수

void IRAM_ATTR onPress() {
  isrCount++;

  unsigned long now = millis();       // 지금 시각(부팅 후 ms)
  if (now - lastTime > 200) {         // 200ms 안의 반복은 튄 걸로 보고 무시
    pressed = true;
    lastTime = now;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(BTN), onPress, FALLING);
}

void loop() {
  if (pressed) {
    pressed = false;
    delay(20);                        // 튀는 게 잦아들 때까지 잠깐 대기 (loop에서는 OK)
    if (digitalRead(BTN) == LOW) {    // 아직 눌려 있을 때만 인정
      ledOn = !ledOn;
      digitalWrite(LED, ledOn);
      Serial.printf("누름 %d번 / 인터럽트 %d번\n", ++pressCount, isrCount);
    }
  }
}
