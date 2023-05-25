#include <NewPing.h>
#include <Servo.h>

// Khai báo chân kết nối cảm biến siêu âm
#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define MAX_DISTANCE 20

// Khai báo chân kết nối cảm biến hồng ngoại
#define IR_PIN 4

// Khai báo chân kết nối còi báo
#define BUZZER_PIN 5

// Khai báo chân kết nối servo
#define SERVO_PIN 6

// Khai báo thời gian mở nắp (1 phút = 60000ms)
#define OPEN_TIME 60000

// Khởi tạo đối tượng cảm biến siêu âm
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Khởi tạo đối tượng servo
Servo lidServo;

// Biến lưu trữ trạng thái của nắp thùng rác
bool isOpen = false;
// Biến lưu trữ thời gian mở nắp
unsigned long openTime = 0;

void setup() {
  // Khởi tạo cổng Serial để giao tiếp với máy tính
  Serial.begin(9600);

  // Thiết lập chân cảm biến hồng ngoại là INPUT
  pinMode(IR_PIN, INPUT);

  // Thiết lập chân còi báo là OUTPUT
  pinMode(BUZZER_PIN, OUTPUT);

  // Đặt chân kết nối servo
  lidServo.attach(SERVO_PIN);

  // Đặt góc ban đầu của servo (nắp đóng lại)
  lidServo.write(0);
}

void loop() {
  // Đọc giá trị từ cảm biến siêu âm
  int distance = sonar.ping_cm();

  // Kiểm tra nếu tay gần thùng rác
  if (distance > 0 && distance <= 10) {
    // Mở nắp thùng rác nếu chưa mở
    if (!isOpen) {
      openLid();
    }
  } else {
    // Đóng nắp thùng rác nếu đã mở và đã đủ thời gian mở
    if (isOpen && (millis() - openTime >= OPEN_TIME)) {
      closeLid();
    }
  }

  // Kiểm tra trạng thái của cảm biến hồng ngoại
  if (digitalRead(IR_PIN) == HIGH) {
    // Thùng rác đã đầy, phát âm báo
    activateBuzzer();
  } else {
    // Thùng rác chưa đầy, tắt âm báo (nếu đang phát)
    deactivateBuzzer();
  }
}

// Hàm mở nắp thùng rác
void openLid() {
  // Gửi tín hiệu điều khiển servo để mở nắp
  lidServo.write(90);
  isOpen = true;
  // Lưu thời gian mở nắp
  openTime = millis();
}

// Hàm đóng nắp thùng rác
void closeLid() {
  // Gửi tín hiệu điều khiển servo để đóng nắp
  lidServo.write(0);
  isOpen = false;
}

// Hàm kích hoạt còi báo
void activateBuzzer() {
  digitalWrite(BUZZER_PIN, HIGH);
}

// Hàm tắt còi báo
void deactivateBuzzer() {
  digitalWrite(BUZZER_PIN, LOW);
}