#include <WiFiManager.h>// thư viện định cấu hình wifi của tzapu
#include <ESP8266WiFi.h> 
#include <FirebaseESP8266.h>
#define FIREBASE_HOST "maiche-a5765-default-rtdb.firebaseio.com" //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "DRhi69XmlFjaqedVrxXefCxZnsGPaMq3t7bqGToa" //Your Firebase Auth Token

FirebaseData firebaseData;
// Chế độ điều khiển
const int CbAsang=A0;
const int CbMua=D2;
const int ctht1=D0;
const int ctht2=D1;

// Chân điều khiển động cơ
const int ENA=D6;
const int IN1=D7;
const int IN2=D8;
//nút nhấn điều khiển đông cơ
const int nutnhanra=9;//sd2
const int nutnhanvao=10;//sd3
// Chân nút nhấn chuyển đổi chế độ
const int MODE=D5;

// Chân nút nhấn kết nối WiFi và điều khiển qua Firebase
const int WIFI_CONTROL=D4;

// Biến chế độ điều khiển
int controlMode = 0;
// trạng thái nút nhấn chế độ WiFi. 0-bật,1-tắt
int wifiControlButtonState=0;
int powerwifi=0;
// Biến lưu trữ trạng thái nút nhấn điều khiển tay
int RaButtonState = LOW;
int VaoButtonState = LOW;
// trạng thái mái che 1 đóng 0 mở
int Trangthaimaiche=0;


void setup() {
  // Động cơ
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  //cảm biến
  pinMode(CbAsang,INPUT);
  pinMode(CbMua,INPUT);
  pinMode(ctht1,INPUT);
  pinMode(ctht2,INPUT);
  //nút nhấn
  pinMode(nutnhanra,INPUT_PULLUP);
  pinMode(nutnhanra,INPUT_PULLUP);
  pinMode(MODE, INPUT_PULLUP);
  pinMode(WIFI_CONTROL, INPUT_PULLUP);

  Serial.begin(115200);
  delay(10);

 // Kết nối với mạng WiFi hoặc tạo mạng WiFi cấu hình nếu không có thông tin WiFi
  WiFiManager wifiManager;
  wifiManager.autoConnect("WiFiSetup");

  // Hiển thị thông tin kết nối WiFi
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  delay(10);
  //Kết nối với Firebase
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
delay(50);
}

void loop() {
  if (WiFi.status() != WL_CONNECTED){ 
    Serial.println("WiFi Not Connected");
    
  }
  else{ 
    Serial.println("WiFi Connected");
    
}
  // Đọc trạng thái nút nhấn chuyển đổi chế độ
  int modeSwitchState = digitalRead(MODE);
  // Đọc trạng thái ctht
  int trangthaict1 = digitalRead(ctht1);
  int trangthaict2 = digitalRead(ctht2);
 

  // Kiểm tra chế độ điều khiển và xử lý tương ứng
  if (controlMode == 1) {
    // Đọc trạng thái nút nhấn điều khiển tay
    RaButtonState = digitalRead(nutnhanra);
    VaoButtonState = digitalRead(nutnhanvao);

    // Điều khiển động cơ dựa trên trạng thái nút nhấn
    if (RaButtonState == LOW && VaoButtonState == HIGH) {
      if(trangthaict2!=0){
          vao();
           Trangthaimaiche=0;
          update_Maiche();
      }else{
            dung();
      }
    
    } else if (RaButtonState == HIGH && VaoButtonState == LOW) {
    if(trangthaict1!=0){
          ra();
           Trangthaimaiche=1;
          update_Maiche();
      }else{
            dung();
      }
} else {
dung();
}
} else if (controlMode == 0) {
// Đọc giá trị từ cảm biến mưa và cảm biến ánh sáng
int MuaValue = digitalRead(CbMua);
int sangValue = analogRead(CbAsang);
Serial.println(sangValue);

// Điều khiển động cơ dựa trên giá trị cảm biến
if (sangValue > 500 ) {//trời sáng
  if(MuaValue==0){//có mưa
    if(trangthaict1!=0){//nếu mái che đang mở
          ra();
           Trangthaimaiche=1;
          update_Maiche();
      }else{
            dung();
      }
  }else{//không mưa
    if(trangthaict2!=0){// mái che đang đóng thì vào
          vao();
           Trangthaimaiche=0;
          update_Maiche();
      }else{
            dung();
      }
  }
  
} else {//trời tối
  if(trangthaict1!=0){//nếu mái che đang mở
          ra();
           Trangthaimaiche=1;
          update_Maiche();
      }else{
            dung();
      }
}
}

// Đọc trạng thái nút nhấn kết nối WiFi và điều khiển qua Firebase
 wifiControlButtonState = digitalRead(WIFI_CONTROL);

// Nếu nút nhấn được nhấn, 
if (wifiControlButtonState!=powerwifi) {
  if(wifiControlButtonState == HIGH){
    powerwifi=1-powerwifi;
  }
  
  
  delay(50);
  update_power_status();
}

if(Firebase.get(firebaseData,"IOT_Control_4Load/P1")) {
 if (firebaseData.dataType() == "string") {
 powerwifi = firebaseData.stringData().toInt();
 }
}


if(Firebase.get(firebaseData,"IOT_Control_4Load/L4")) {
 if (firebaseData.dataType() == "string") {
 Trangthaimaiche = firebaseData.stringData().toInt();
  }
 }
 // điều khiển bằng wifi
if(powerwifi==0){
    if(Trangthaimaiche==0){
         if(trangthaict2!=0){
            Trangthaimaiche=0;
          vao();
          update_Maiche();
      }else{
            dung();
      }
    }else if(Trangthaimaiche==1){
        if(trangthaict1!=0){
           Trangthaimaiche=1;
          ra();
          update_Maiche();
      }else{
            dung();
      }
    }else{
        dung();
          }
  }else{
   dung();
        }
delay(100); 
}
void vao() {
 
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
analogWrite(ENA, 255);
}

void ra() {
  
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
analogWrite(ENA, 255); 
}

void dung() {
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
analogWrite(ENA, 0);
}
// Hàm cập nhật chế độ wifi lên firebase
void update_power_status(){
if(Firebase.setString(firebaseData, "IOT_Control_4Load/P1", String(powerwifi))){
    Serial.println("PASSED");
   
}else{
    Serial.println("FAILED");
    
}   
}
void update_Maiche(){
  if(Firebase.setString(firebaseData, "IOT_Control_4Load/L4", String(Trangthaimaiche))){
    Serial.println("PASSED");
    
 }else{
    Serial.println("FAILED");
    
  }
delay(100);
}
