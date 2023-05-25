int LED=A0;
int in1=9,in2=10,ENA=3;//Động cơ
int nutnhanvao=6,nutnhanra=7,nuttrangthai=12;//nút nhấn
int ctht1=4,ctht2=5,cbmua=8; cbanhsang=11;//cảm biến

int trangthaimaiche=3,trangthaimaichelast=3;//dừng
int trangthaict1last=1,trangthaict2last=1;//ctht 1,2 chưa chạm
int gtcbmualast=1,gtcbanhsanglast=0;//1 là không mưa 
int delaysend=200;
int value; 
boolean chuoidk=1,chuoidklast=0;//1 tự động 0 wifi
boolean ledstate = false;
//#define button A1
void setup() {
  Serial.begin(115200);
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
    //Serial.println(trangthai);
    //delay(100);


char Rxesp8266="";

  if(Serial.available()){
    
    while(Serial.available()){
      Rxesp8266 = Serial.read();//Đọc tất cả bộ đệm
    }
    if(Rxesp8266==5){    //Kiểm tra chuỗi nhận
      digitalWrite(LED,LOW);
    chuoidk=1;
    }else if(Rxesp8266==4){
      digitalWrite(LED,HIGH);
    chuoidk=0;
    }
    
   
  }

//giửi cho chế độ cho app
 if(chuoidklast!=chuoidk){//nếu khác giá trị thì mới giửi
     chuoidklast=chuoidk;
     if(chuoidk==0){
      Serial.println(4);
      delay(delaysend);
     }else{
       Serial.println(5);
       delay(delaysend);
     }
      
     }
   }

 


if(chuoidk==0) { 
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
if(chuoidk==1)
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
    
  
   
    if(trangthaict1last!=trangthaict1){//nếu khác giá trị thì mới giửi
     trangthaict1last=trangthaict1;
     if(trangthaict1==1){
      Serial.println("11");
      delay(delaysend);
     }else{
       Serial.println("12");
       delay(delaysend);
     }
   }
   
   if(trangthaict2last!=trangthaict2){//nếu khác giá trị thì mới giửi
     trangthaict2last=trangthaict2;
     if(trangthaict2==1){
      Serial.println("13");
      delay(delaysend);
     }else{
       Serial.println("14");
       delay(delaysend);
     }
   }
   if(trangthaimaichelast!=trangthaimaiche){//nếu khác giá trị thì mới giửi
     trangthaimaichelast=trangthaimaiche;
    if(trangthaimaiche==0){
      Serial.println("9");
      delay(delaysend);
     }else{
      Serial.println("8");
      delay(delaysend);
     
   }
   }
     if(gtcbmualast!=gtcbmua){//nếu khác giá trị thì mới giửi
     gtcbmualast=gtcbmua;
     if(gtcbmua==1){
      Serial.println("7");
      delay(delaysend);
     }else{
       Serial.println("6");
       delay(delaysend);
     }
   }
   
  
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
   
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
    }
