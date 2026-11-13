# Egglab · Android 근태·업무 관리 UI

근로자의 출퇴근과 업무 정보를 한곳에서 확인할 수 있도록 구성한 **Java 기반 Android 앱 UI 프로토타입**입니다. 캡스톤디자인 프로젝트의 화면 구성과 사이드 메뉴 탐색 흐름을 담고 있습니다.

> 현재 `main` 브랜치 기준으로 홈 화면과 메뉴 전환이 구현되어 있습니다. 출퇴근 기록 저장, 근무시간 계산, 알림 발송, 서버 연동은 아직 구현되어 있지 않습니다.

## 화면 구성

### 홈 · 출퇴근 등록

- 근무시간 통계 및 알림 영역
- `YNC Center`와 출근·퇴근 시간 표시
- 출퇴근 등록 UI
- 이름, 사번, 근무조를 표시하는 사이드 메뉴 헤더

화면의 사용자 정보와 날짜는 XML에 작성된 예시 데이터입니다. 출퇴근 등록 영역은 현재 클릭 처리가 연결되지 않은 `TextView`입니다.

### 사이드 메뉴

`MainActivity`에서 `DrawerLayout`과 `NavigationView`를 사용하고, 메뉴 선택에 따라 `Fragment`를 교체합니다.

| 메뉴 | 연결 화면 | 구현 상태 |
| --- | --- | --- |
| 출/퇴근 등록 | `HomeFragment` | 홈 UI 구성 |
| 업무 신청 | `SettingsFragment` | 임시 화면 |
| 나의 스케줄 | `ShareFragment` | 임시 화면 |
| 급여 정산 정보 | `AboutFragment` | 임시 화면 |
| 전자근로계약서 | `AboutFragment` | 공통 임시 화면 연결 |
| 특수 건강검진 | `AboutFragment` | 공통 임시 화면 연결 |
| Logout | Toast 메시지 | 실제 인증 해제 미구현 |

## 기술 구성

| 항목 | 저장소 설정 |
| --- | --- |
| 앱 코드 | Java · Java 8 소스 호환성 |
| 화면 | Android XML Layout, Fragment |
| UI 라이브러리 | AndroidX AppCompat 1.6.1, Material Components 1.12.0, ConstraintLayout 2.1.4 |
| 빌드 설정 | Gradle Kotlin DSL |
| Android Gradle Plugin | 8.1.1 |
| Gradle Wrapper | 8.0 |
| 최소 지원 SDK | API 24 |
| Compile / Target SDK | API 34 |
| 앱 ID | `com.example.egglab` |

## 프로젝트 구조

```text
Android_Egglab/
├── app/
│   ├── build.gradle.kts            # 앱 모듈 설정과 의존성
│   └── src/main/
│       ├── AndroidManifest.xml    # 앱 및 시작 Activity 선언
│       ├── java/com/example/egglab/
│       │   ├── MainActivity.java  # 툴바, 사이드 메뉴, Fragment 전환
│       │   ├── HomeFragment.java
│       │   ├── SettingsFragment.java
│       │   ├── ShareFragment.java
│       │   └── AboutFragment.java
│       └── res/
│           ├── layout/            # Activity, Fragment, 메뉴 헤더 UI
│           ├── menu/              # 사이드 메뉴 항목
│           ├── drawable/          # 배경과 그래픽 리소스
│           ├── font/              # 화면용 글꼴
│           └── values/            # 문자열, 색상, 테마
├── gradle/wrapper/                # Gradle 실행 버전
├── build.gradle.kts               # 프로젝트 플러그인 설정
└── settings.gradle.kts            # 저장소 및 모듈 구성
```

## 실행 방법

1. 저장소를 복제합니다.

   ```bash
   git clone https://github.com/yanglilla/Android_Egglab.git
   ```

2. Android Studio에서 복제한 `Android_Egglab` 폴더를 엽니다.
3. Android SDK API 34를 설치하고 Gradle 동기화를 진행합니다.
4. API 24 이상의 에뮬레이터 또는 Android 기기를 선택합니다.
5. `app` 실행 구성을 선택하고 **Run**을 누릅니다.

명령줄에서 디버그 APK를 빌드하려면 Android SDK와 Gradle 실행용 JDK가 구성된 환경에서 실행합니다.

```powershell
# Windows PowerShell
.\gradlew.bat assembleDebug
```

```bash
# macOS / Linux
./gradlew assembleDebug
```

생성 위치: `app/build/outputs/apk/debug/app-debug.apk`

이 README는 소스와 설정 파일을 확인해 작성했으며, 문서 작성 과정에서 Android 빌드나 기기 실행을 검증하지는 않았습니다.

## 향후 구현 과제

- 출퇴근 등록 이벤트와 기록 저장
- 실제 근무시간 통계 및 알림 처리
- 업무 신청·스케줄·급여 화면 구현
- 전자근로계약서·건강검진 전용 화면 구성
- 로그인·로그아웃 및 서버 연동
- 작은 화면에서도 사용할 수 있도록 고정 크기 레이아웃 개선

## 원본 프로젝트

이 저장소는 [rohgibong/Android_Egglab](https://github.com/rohgibong/Android_Egglab)을 포크한 프로젝트입니다. 위 설명은 이 포크의 `main` 브랜치를 기준으로 하며, 원본 저장소의 최신 구현과 다를 수 있습니다.
