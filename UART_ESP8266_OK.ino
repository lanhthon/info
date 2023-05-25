#include <WiFiManager.h>// thư viện định cấu hình wifi của tzapu
#include <ESP8266WiFi.h>

#include <FirebaseESP8266.h>
#define FIREBASE_HOST "maiche-a5765-default-rtdb.firebaseio.com" //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "DRhi69XmlFjaqedVrxXefCxZnsGPaMq3t7bqGToa" //Your Firebase Auth Token
FirebaseData firebaseData;
#define LED 2
int wifimode=1,wifimodelast=1;
int Trangthaimaiche=3,Trangthaimaichelast=3;
const int buttonPin = 14;//D4
const int buttonThreshold = 1000; // Ngưỡng thời gian nhấn giữ (đơn vị: ms)
unsigned long buttonPressTime = 0; // Thời gian nút được nhấn (đơn vị: ms)
boolean buttonPressed = false; // Trạng thái nút được nhấn
boolean wifistate = false; 
boolean ledstate = false;
boolean ketnoi = false;
void setup() {
  Serial.begin(115200);  //Khởi tạo cổng serial
  pinMode(button,INPUT_PULLUP);
  pinMode(LED,OUTPUT);
   // Kết nối với mạng WiFi hoặc tạo mạng WiFi cấu hình nếu không có thông tin WiFi
  WiFiManager wifiManager;
  wifiManager.autoConnect("WiFiSetup_Maiche");
  delay(10);
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  delay(50);
}



void loop() {
  if (WiFi.status() != WL_CONNECTED){ 
    digitalWrite(LED,LOW);
  }
  else{ 
    digitalWrite(LED,HIGH);
  }


  // Đọc trạng thái của nút
  boolean buttonState = digitalRead(buttonPin);
  
  // Kiểm tra nút được nhấn
  if (buttonState == LOW && !buttonPressed) {
    buttonPressed = true;
  }
  
  // Kiểm tra nút được nhả
  if (buttonState == HIGH && buttonPressed) {
    unsigned long buttonHoldTime = millis();
    
    if (buttonHoldTime >= buttonThreshold) {
      WiFiManager wifiManager;
      wifiManager.resetSettings();
      delay(200);
      wifiManager.autoConnect("WiFiSetup_Maiche");
      //Led báo
      digitalWrite(LED,LOW);
      delay(200);
      digitalWrite(LED,HIGH);
      delay(200);
      digitalWrite(LED,LOW);
      delay(200);
      digitalWrite(LED,HIGH);
      delay(200);
      digitalWrite(LED,LOW);
    }
    
    buttonPressed = false;
  }
  

  //Gửi đi /0-vào/1-ra/3-dừng/4-wif/5-auto
  //NHận vào/ 6-Mưa/7-không mưa/8 mái che ra/9 mái che vào/10 mai che dung/ 11 ctht1 chưa chạm/12 ctht Đang chạm
  //13 ctht2 chưa chạm/14 ctht2 Đang chạm
if(Serial.available()){
 
    String c=Serial.readStringUntil('\n');//đọc giá trị giửi đến khi gặp xuống dòng
   
    if(c=="4" || c=="5"){
      Firebase.setString(firebaseData, "IOT_Control_4Load/P1", String(c));
    }else{
      Firebase.setString(firebaseData, "IOT_Control_4Load/L1", String(c));
    }
    
  
  }
  //nhận từ firebase
if(Firebase.get(firebaseData,"IOT_Control_4Load/P1")) {
 if (firebaseData.dataType() == "string") {
 wifimode = firebaseData.stringData().toInt();
    if(wifimodelast!=wifimode){//nếu khác giá trị thì mới giửi
     wifimodelast=wifimode;
    Serial.write(wifimode);
   }
 
 }
 }

 

if(Firebase.get(firebaseData,"IOT_Control_4Load/L4")) {
 if (firebaseData.dataType() == "string") {
 Trangthaimaiche = firebaseData.stringData().toInt();
 if(Trangthaimaichelast!=Trangthaimaiche){//nếu khác giá trị thì mới giửi
     Trangthaimaichelast=Trangthaimaiche;
    Serial.write(Trangthaimaiche);
   }

 }
  
 }
 
}

