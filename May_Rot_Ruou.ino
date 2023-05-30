#include <Servo.h>

// Khai báo đối tượng Servo
Servo servoMotor;

// Khai báo chân kết nối động cơ servo
const int servoPin = 9;
bool trangthai=false;

// Khai báo chân kết nối giữa Arduino và mô đun L298
const int ENA = 9;  // Chân Enable A
const int IN1 = 8;  // Chân Input 1
const int IN2 = 10;  // Chân Input 2

// Khai báo chân kết nối cảm biến siêu âm
const int trigPin = 4;  // Chân Trigger
const int echoPin = 5;  // Chân Echo
const int trigPin2 = 6;  // Chân Trigger
const int echoPin2 = 7;  // Chân Echo
int motorSpeed = 255;
void setup() {
  pinMode(servoPin, OUTPUT);

  // Khởi tạo động cơ servo
  servoMotor.attach(servoPin);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
   servoMotor.write(180);
}

void loop() {
 
  int khoangcach = measureDistance();  // Đo khoảng cách từ cảm biến
  int khoangcach2 = measureDistance2();  // Đo khoảng cách từ cảm biến
 
  // In giá trị khoảng cách lên Serial Monitor

 
    Serial.println(khoangcach2);
    if(khoangcach>5){
      trangthai=false;
    
    }else{
      delay(200);
    }

 if(khoangcach<=5 && trangthai==false &&  khoangcach2<=557  ){
    delay(1000);// xem trạng thái cái ly hay cái tay
    if(measureDistance2()==11 ||measureDistance2()==10){
    trangthai=true;
    servoMotor.write(100);
      delay(1000);
    servoMotor.write(170);
    }else{
      trangthai=true;
    servoMotor.write(150);
      delay(1000);
    servoMotor.write(170);
    }
  }
  // Chuyển đổi khoảng cách thành tốc độ quay của động cơ
  
  // Điều khiển động cơ bằng mô đun L298
  
  delay(200); // Đợi 500ms trước khi đo khoảng cách mới
}

int measureDistance() {
  // Gửi xung siêu âm để đo khoảng cách
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Đọc thời gian mà sóng siêu âm mất để quay lại
  long duration = pulseIn(echoPin, HIGH);
  
  // Tính toán khoảng cách dựa trên thời gian
  int khoangcach = duration * 0.034 / 2; // Tính theo đơn vị cm
  
  return khoangcach;
}
int measureDistance2() {
  // Gửi xung siêu âm để đo khoảng cách
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  
  // Đọc thời gian mà sóng siêu âm mất để quay lại
  long duration2 = pulseIn(echoPin2, HIGH);
  
  // Tính toán khoảng cách dựa trên thời gian
  int khoangcach2 = duration2 * 0.034 / 2; // Tính theo đơn vị cm
  
  return khoangcach2;
}
void bom(){
  analogWrite(ENA, motorSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
}
void dung(){
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  
}
