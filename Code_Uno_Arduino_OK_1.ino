const int irSensorPin = A0; // Đầu vào analog của cảm biến hồng ngoại

void setup() {
  Serial.begin(9600); // Khởi tạo cổng Serial với baud rate 9600
}

void loop() {
  int sensorValue = analogRead(irSensorPin); // Đọc giá trị từ cảm biến hồng ngoại
  
  Serial.print("Giá trị cảm biến: ");
  Serial.println(sensorValue); // In giá trị cảm biến lên cổng Serial

  delay(100); // Chờ 1 giây trước khi đọc lại giá trị
}
