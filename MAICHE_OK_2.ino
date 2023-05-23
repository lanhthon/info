//#include <SoftwareSerial.h>
 
//#define RX_PIN      2 //Chân TX trên bluetooth
//#define TX_PIN      13 //Chân rx trên ble
int value; 

String chuoi="";
String chuoidk="td";
unsigned long timer,t1=0;
int LED=A0;
//SoftwareSerial esp8266(RX_PIN, TX_PIN);
//int baudRate[] = {300, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200};

int in1=9;
int in2=10;
int ENA=3;
int nutnhanvao=6;
int nutnhanra=7;
int ctht1=4;
int ctht2=5;
int cbmua=8;
int cbanhsang=11;
int nuttrangthai=12;
int trangthaimaiche=3;
int trangthaimaichelast=3;//dừng
int trangthaict1last=1;//ctht 1 chưa chạm
int trangthaict2last=1;//ctht 2 chưa chạm
int gtcbmualast=1;//Không mưa


boolean ledstate = false;
#define button A1
void setup() {
	Serial.begin(115200);
 
 	/*while (!Serial) {}
   	Serial.println("Configuring, please wait...");
    	for (int i = 0 ; i < 9 ; i++) {
     		bluetooth.begin(baudRate[i]);
     		String cmd = "AT+BAUD4";
     		bluetooth.print(cmd);
     		bluetooth.flush();
     		delay(100);
  }
  bluetooth.begin(9600);
  Serial.println("Config done");
  while (!bluetooth) {}
    Serial.println("Enter AT commands:");
  */
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(nutnhanvao, INPUT_PULLUP);
  pinMode(nutnhanra, INPUT_PULLUP);
  pinMode(nuttrangthai, INPUT_PULLUP);
  pinMode(ctht1,INPUT_PULLUP);
  pinMode(ctht2,INPUT_PULLUP);
 pinMode(cbmua,INPUT_PULLUP);
 pinMode(cbanhsang,INPUT_PULLUP);
 pinMode(button,INPUT_PULLUP);
}
void loop()
{
    analogWrite(ENA,150);
  
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
    //Serial.println(trangthai);
    //delay(100);


char Rxesp8266="";

  if(Serial.available()){
    
    while(Serial.available()){
      Rxesp8266 = Serial.read();//Đọc tất cả bộ đệm
    }
    if(Rxesp8266==5){    //Kiểm tra chuỗi nhận
      digitalWrite(LED,LOW);
    chuoidk="td";
    }else if(Rxesp8266==4){
      digitalWrite(LED,HIGH);
    chuoidk="dk";
    }
  }






if(chuoidk.equals("dk")) { 
   if(Rxesp8266==0){
      if(digitalRead(ctht2)!=0){
        vao();
        value=0;
        
         }    
    }
  if(Rxesp8266==1){
    if(digitalRead(ctht1)!=0){
      ra();
      value=1;
      
       }
       
    }
  if(digitalRead(ctht1)==0 && value==1){
    dung();
  }else if(digitalRead(ctht2)==0 && value==0){
    dung();
  }
    
  if(Rxesp8266==3){
     dung();
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
  }
  //Nhận vào /0-vào/1-ra/3-dừng/4-wif/5-auto
  //Giửi đi/ 6-Mưa/7-không mưa/8 mái che ra/9 mái che vào/10 mai che dung/ 11 ctht1 chưa chạm/12 ctht Đang chạm
  //13 ctht2 chưa chạm/14 ctht2 Đang chạm
    
     if(gtcbmualast!=gtcbmua){//nếu khác giá trị thì mới giửi
     gtcbmualast=gtcbmua;
     if(gtcbmua==1){
      Serial.print("7");
      delay(200);
     }else{
       Serial.print("6");
        delay(200);
     }
   }
   /*
    if(trangthaict1last!=trangthaict1){//nếu khác giá trị thì mới giửi
     trangthaict1last=trangthaict1;
     if(trangthaict1==1){
      Serial.print("11");
     }else{
       Serial.print("12");
     }
   }
   
   if(trangthaict2last!=trangthaict2){//nếu khác giá trị thì mới giửi
     trangthaict2last=trangthaict2;
     if(trangthaict2==1){
      Serial.print("13");
     }else{
       Serial.print("14");
     }
   }
   if(trangthaimaichelast!=trangthaimaiche){//nếu khác giá trị thì mới giửi
     trangthaimaichelast=trangthaimaiche;
    if(trangthaimaiche==0){
      Serial.print("9");
     }else if(trangthaimaiche==1){
      Serial.print("8");
     }else{
      Serial.print("10");
     }
   }
     if(gtcbmualast!=gtcbmua){//nếu khác giá trị thì mới giửi
     gtcbmualast=gtcbmua;
     if(gtcbmua==1){
      Serial.print("7");
     }else{
       Serial.print("6");
     }
   }
   */
  
 }

void vao(){
  trangthaimaiche=0;
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
    }
 void ra(){
   trangthaimaiche=1;
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
    }
 void dung(){
   trangthaimaiche=3;
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
    }
