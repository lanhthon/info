#include <WiFiManager.h>// thư viện định cấu hình wifi 
#include <ESP8266WiFi.h> 
#include <FirebaseESP8266.h>
#define FIREBASE_HOST "maiche-a5765-default-rtdb.firebaseio.com" //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "DRhi69XmlFjaqedVrxXefCxZnsGPaMq3t7bqGToa" //Your Firebase Auth Token
FirebaseData firebaseData;
char value; 
char kytu="";
String chuoi="";
String chuoidk="dk";
unsigned long timer;
int load4=0;
int in1=D7;
int in2=D8;
int ENA=D6;
int nutnhanvao=10;
int nutnhanra=9;
int ctht1=D0;
int ctht2=D1;
int cbmua=D2;
int cbanhsang=A0;
int nuttrangthai=D5;

void setup() {
	Serial.begin(9600); 
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(nutnhanvao, INPUT_PULLUP);
  pinMode(nutnhanra, INPUT_PULLUP);
  pinMode(nuttrangthai, INPUT_PULLUP);
  pinMode(ctht1,INPUT);
  pinMode(ctht2,INPUT);
 pinMode(cbmua,INPUT);
 pinMode(cbanhsang,INPUT);
 // Kết nối với mạng WiFi hoặc tạo mạng WiFi cấu hình nếu không có thông tin WiFi
  WiFiManager wifiManager;
  wifiManager.autoConnect("WiFiSetup");

  // Hiển thị thông tin kết nối WiFi
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  delay(10);
Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
delay(50);
}
void loop()
{
    analogWrite(ENA,255);
    int trangthainutvao=digitalRead(nutnhanvao);
    int trangthainutra=digitalRead(nutnhanra);
    int trangthai=digitalRead(nuttrangthai);
    int trangthaict1=digitalRead(ctht1);
    int trangthaict2=digitalRead(ctht2);
    int gtcbmua=digitalRead(cbmua);
    int gtcbanhsang=digitalRead(cbanhsang);
    //Serial.print(trangthaict1);
    //Serial.print(trangthaict2);
    //Serial.print(trangthainutvao);
    //Serial.print(trangthainutra);
    //Serial.print(gtcbmua);
    //Serial.print(gtcbanhsang);
    Serial.println(trangthai);
    delay(100);

if(Firebase.get(firebaseData,"IOT_Control_4Load/L4")) {
 if (firebaseData.dataType() == "string") {
 load4 = firebaseData.stringData().toInt();
  }
 }
 if(load4==1){
 chuoi="td";
 }else{
 chuoi="dk";
 }
      if(chuoi.indexOf("td")>=0)
	      { chuoi="";
	      chuoidk="td";}
      else if(chuoi.indexOf("dk")>=0)
	    {chuoi="";
      	chuoidk="dk";
      }
    	}
   }
if(chuoidk.equals("dk"))
   { 
   if(load4==1){
 chuoi="kéo ra";
 }else{
 chuoi="kéo vào";
 }
   if((chuoi.indexOf("kéo ra")>=0)  )
      {
        if(trangthaict1!=0) //mái che đang mở
            {ra();delay(7000);dung();}
         else {dung();}
         chuoi="";
    	}
  if((chuoi.indexOf("kéo vào")>=0) )
     {
    	  if(trangthaict2!=0) //mái che đang đóng
            {vao();delay(7000);dung();}
          else {dung();}
          chuoi="";
      }  
  if((chuoi.indexOf("dừng")>=0) )
    {
    dung();
    chuoi="";
    }
 }
 
if(chuoidk.equals("td"))
 {
  if (trangthai!=0)   //không nhấn nút trạng thái
  {
      if(gtcbanhsang!=1)      //trời sáng 
        {
        if(gtcbmua==0 )   //có mưa
          {
            if(trangthaict1!=0) //mái che đang mở
                {ra();}
            else {dung();}
          }
        else  //không mưa
        {
          if(trangthaict2!=0) //mái che đang đóng
            {vao();}
          else {dung();}
        }
      }
    else
      { if(trangthaict1!=0) //mái che đang mở
                {ra();}
            else {dung();}
      }
  }
else    //nhấn nút trạng thái
  {
      if (trangthainutvao==0 && trangthainutra!=0)
          {
              if (trangthaict2!=0)
                {vao();
                //delay(2000);
                }
              else {dung();}
          }
      else 
        {
          if (trangthainutvao!=0 && trangthainutra==0)
            {
                if (trangthaict1!=0) 
                  {ra();
                  //delay(2000);
                  }
                else {dung();}
            }
           else
           {
            if (trangthainutvao!=0 && trangthainutra!=0)
              {dung();}
           }
        }
    }
  

void vao(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
    }
 void ra(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
    }
 void dung(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
    }
