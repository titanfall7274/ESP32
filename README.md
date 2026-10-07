# ESP32 - Embedded

ESP32로 임베디드 SW를 처음부터 공부하는 기록. 회로, 코드, 겪은 문제와 해결 과정을 날짜별로 남긴다.

## 환경

- ESP32 DevKit 30핀 (ESP-WROOM-32, USB-C, CP2102)
- Arduino IDE (보드: ESP32 Dev Module)
- 브레드보드 830 + 400 (ESP32를 두 보드에 걸쳐 꽂음)
- LED, 220Ω 저항, 4다리 택트 스위치, 점퍼선

## 시작하기

1. Arduino IDE 보드 매니저에서 `esp32` (Espressif) 설치
2. 보드: `ESP32 Dev Module`, 포트: CP2102가 잡힌 COM 포트 선택
3. `projects/<번호_이름>/` 폴더의 `.ino` 파일을 열고 업로드

Arduino IDE는 스케치 파일 이름과 폴더 이름이 같아야 열리기 때문에 실습마다 폴더를 하나씩 둔다.

## 폴더 구조

```
docs/        # 주제별 개념 정리
logs/        # 날짜별 학습 기록
projects/    # 실습 코드 (Arduino 스케치)
```

## 학습 기록

| 날짜 | 주제 | 실습 |
| --- | --- | --- |
| [2026-10-07](logs/2026-10-07.md) | 첫 회로, 폴링 → 인터럽트, 디바운싱 | [01](projects/01_led_button_polling) · [02](projects/02_button_interrupt) · [03](projects/03_interrupt_debounce) |

## 로드맵

- [x] GPIO 출력/입력: LED, 버튼, 내장 풀업
- [x] UART: 시리얼 모니터 출력 (`Serial.printf`)
- [x] 인터럽트: `attachInterrupt`, `IRAM_ATTR`, `volatile`
- [x] 바운싱과 디바운싱
- [ ] PWM으로 LED 밝기 조절 (`ledcAttach`, `ledcWrite`)
- [ ] I2C/SPI 센서 붙이기 + 데이터시트 읽기
- [ ] FreeRTOS: task 두 개 돌리고 데이터 주고받기
- [ ] ESP-IDF로 넘어가서 레지스터 직접 다루기
- [ ] DMA, 저전력(deep sleep), 메모리 정렬과 엔디언

## 커밋 컨벤션

- `feat:` 실습 코드 추가
- `docs:` 개념 문서, 학습 기록
- `fix:` 코드/회로 수정
- `chore:` 설정 관련
