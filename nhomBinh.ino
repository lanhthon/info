#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <MFRC522.h>
#include <TimerOne.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Tạo đối tượng MFRC522

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Địa chỉ I2C và kích thước LCD (16x2)
Servo servo1;
Servo servo2;

bool isCardValid = false;
unsigned long previousMillis = 0;
unsigned long interval = 60000;  // Thời gian trôi qua trước khi cả hai servo quay về góc 0

void setup() {
  Serial.begin(9600);  // Khởi động kết nối Serial
  lcd.begin(16, 2);   // Khởi động màn hình LCD
  lcd.print("   RFID Door   ");
  lcd.setCursor(0, 1);
  lcd.print("    Security   ");
  delay(2000);
  lcd.clear();
  servo1.attach(8);    // Chân điều khiển servo1
  servo2.attach(7);    // Chân điều khiển servo2
  servo1.write(0);     // Đặt góc ban đầu của servo1 là 0 độ
  servo2.write(0);     // Đặt góc ban đầu của servo2 là 0 độ

  SPI.begin();        // Khởi động SPI
  mfrc522.PCD_Init(); // Khởi động MFRC522

  Timer1.initialize(interval);  // Khởi tạo bộ định thời
  Timer1.attachInterrupt(resetServos);  // Gắn ngắt thời gian
}

void loop() {
  // Kiểm tra xem có thẻ được đưa vào hay không
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    String cardUID = getCardUID();  // Lấy UID của thẻ

    // So sánh với UID mẫu (thẻ hợp lệ)
    if (cardUID == "F3 0D F7 A7") {
      isCardValid = true;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Thẻ hợp lệ");
      delay(2000);
      lcd.clear();
      lcd.print("Mở cửa...");
      servo1.write(180);  // Quay servo1 180 độ
      servo2.write(90);   // Quay servo2 90 độ
      delay(2000);
      lcd.clear();
      lcd.print("Cửa đã mở");
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Sai thẻ");
      delay(2000);
      lcd.clear();
    }

    mfrc522.PICC_HaltA(); // Tắt thẻ
}
}

String getCardUID() {
String cardUID = "";
for (byte i = 0; i < mfrc522.uid.size; i++) {
cardUID += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" + String(mfrc522.uid.uidByte[i], HEX) : String(mfrc522.uid.uidByte[i], HEX));
}
cardUID.toUpperCase(); // Chuyển đổi thành chữ hoa
return cardUID;
}

void resetServos() {
if (isCardValid) {
servo1.write(0); // Quay servo1 về góc 0 độ
servo2.write(0); // Quay servo2 về góc 0 độ
isCardValid = false;
}
} 