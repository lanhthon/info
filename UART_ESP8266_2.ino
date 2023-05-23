#include <WiFiManager.h>// thư viện định cấu hình wifi của tzapu
#include <ESP8266WiFi.h>

#include <FirebaseESP8266.h>
#define FIREBASE_HOST "maiche-a5765-default-rtdb.firebaseio.com" //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "DRhi69XmlFjaqedVrxXefCxZnsGPaMq3t7bqGToa" //Your Firebase Auth Token
FirebaseData firebaseData;
#define button 14
#define LED 2
int wifimode=1;
int wifimodelast=0;
int Trangthaimaiche;
int Trangthaimaichelast=0;

  //Định nghĩa chân 2 là Led
 //Chống dội và đè phím
boolean wifistate = false; 
boolean ledstate = false;
boolean ketnoi = false;

   String myString; // complete message from arduino, which consistors of snesors data

   
void setup() {
  Serial.begin(115200);  //Khởi tạo cổng serial
  pinMode(button,INPUT_PULLUP);
   pinMode(LED,OUTPUT);
  //SPIFFS.begin();
  //doctrangthai();
   // Kết nối với mạng WiFi hoặc tạo mạng WiFi cấu hình nếu không có thông tin WiFi
WiFiManager wifiManager;
  wifiManager.autoConnect("WiFiSetup_Maiche");

  // Hiển thị thông tin kết nối WiFi
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  delay(10);
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  delay(50);
}

/// luu du lieu
/*void ghitrangthai(){
  DynamicJsonDocument doc(1024);
  doc["wifimode"]=wifimode;
  File file=SPIFFS.open("/log.json","w");
  if(file){
    serializeJson(doc,file);
    file.close();
  }
 

}
void doctrangthai(){
   File file=SPIFFS.open("/log.json","r");
if(file){
  StaticJsonDocument<200> doc;
  DeserializationError error=deserializeJson(doc,file);
  if(error){

  }else{
    wifimode=doc["wifimode"];
    
  }
  file.close();
}
}
*/
void loop() {


  
  if (WiFi.status() != WL_CONNECTED){ 
    Serial.println("WiFi Not Connected");
    digitalWrite(LED,LOW);
  }
  else{ 
    Serial.println("WiFi Connected");
    digitalWrite(LED,HIGH);
}


  
  
 int buttonstate=digitalRead(button);
  if(buttonstate==0){
    
    ledstate=!ledstate;
    if(ledstate){
        wifimode=ledstate;
      Serial.write(4);
        update_power_status();
        
      }else{
        
        wifimode=ledstate;
      Serial.write(5);
        update_power_status();
        
      }
    

    delay(200);
  }

  //Gửi đi /0-vào/1-ra/3-dừng/4-wif/5-auto
  //NHận vào/ 6-Mưa/7-không mưa/8 mái che ra/9 mái che vào/10 mai che dung/ 11 ctht1 chưa chạm/12 ctht Đang chạm
  //13 ctht2 chưa chạm/14 ctht2 Đang chạm
if(Serial.available()){
 
    String c=Serial.readString();
   
  
      Firebase.setString(firebaseData, "IOT_Control_4Load/L1", String(c));
     
    
  
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
void update_power_status(){
if(Firebase.setString(firebaseData, "IOT_Control_4Load/P1", String(wifimode))){
    Serial.println("PASSED");
   
}else{
    Serial.println("error");
    
}   
}
