// 01. 폴링: 버튼을 누르는 동안 LED 켜기
// 회로: D26 → 220Ω → LED → GND, D27 → 버튼 → GND (내장 풀업)
// 시리얼 모니터 115200: 안 누르면 1, 누르면 0

const int LED = 26;
const int BTN = 27;

void setup() {
  Serial.begin(115200);
  Serial.println("부팅됨");

  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);  // 내장 풀업: 평소 1, 누르면 0
}

void loop() {
  int b = digitalRead(BTN);  // loop가 계속 버튼 상태를 물어봄 (폴링)
  Serial.println(b);

  digitalWrite(LED, b == LOW ? HIGH : LOW);  // == (비교), = 아님!
  delay(200);
}
