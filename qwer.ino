int piezoPin = A0; // 압전 센서를 아두이노의 A0 핀에 연결
int threshold = 100; // 압전 센서 출력 임계값
int count = 1; // 출력할 숫자의 시작 값
bool sensorActive = false; // 센서 활성화 상태를 추적하는 변수

void setup() {
  pinMode(piezoPin, INPUT); // 압전 센서 핀을 입력으로 설정
  Serial.begin(9600); // 시리얼 통신 시작
}

void loop() {
  int sensorValue = analogRead(piezoPin); // 압전 센서에서 값을 읽음

  if (sensorValue <= threshold) { // 센서 값이 임계값 이하인 경우
    if (!sensorActive) {
      sensorActive = true; // 센서 비활성화 상태를 true로 설정
      Serial.println("헬멧씀!!");
    }
    delay(1000); // 다음 동작 전에 1초 대기
  } else {
    if (sensorActive) {
      sensorActive = false; // 센서 비활성화 상태를 false로 재설정
      Serial.println("헬멧 벗음");
    }
    Serial.println(count); // 현재 숫자를 시리얼 모니터에 출력
    count++; // 숫자를 증가
    delay(1000); // 다음 숫자 증가 전에 1초 대기
  }
}
