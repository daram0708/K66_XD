#include <PS2X_lib.h>  // Thư viện điều khiển tay cầm PS2
PS2X ps2x; // Khai báo đối tượng tay cầm

// Các chân kết nối
#define PS2_DAT 10
#define PS2_CMD 11
#define PS2_SEL 12
#define PS2_CLK 13
int out4 = 7;
int  out3=6 ;
int out2= 7;
int  out1=6 ;
int setspeed1 = 3;
int setspeed2 =2;
void setup() {
  Serial.begin(9600);

  delay(300);  // Đợi tay cầm ổn định

  int error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, true, true);

  if (error == 0) {
    Serial.println("PS2 Controller Connected Successfully!");
  } else if (error == 1) {
    Serial.println("Không tìm thấy tay cầm.");
  } else if (error == 2) {
    Serial.println("Tay cầm tìm thấy nhưng không phản hồi.");
  } else if (error == 3) {
    Serial.println("Không thể vào chế độ Analog.");
  }
  delay(1000);
}// 1 4 len 2 3 xuong
  void dichuyen(int ly , int lx){
    if(lx>0&&lx<255&&ly==0){//tien
      digitalWrite(out1,1);
    digitalWrite(out2,0);
  digitalWrite(out3,0);
  digitalWrite(out4,1);
    }

  else if(lx == 255&&ly>0&&ly<255){//sang phai

digitalWrite(out1,0);
    digitalWrite(out2,1);
  digitalWrite(out3,0);
  digitalWrite(out4,1);
    
  }
  else if(ly>0&&ly<255&&lx==0 ){//sang trai
        digitalWrite(out2,0);
    digitalWrite(out1,1);
  digitalWrite(out3,1);
  digitalWrite(out4,0);
    
  }
  else if(ly==255&&lx>0&&lx<255){//lui
      digitalWrite(out2,1);
    digitalWrite(out1,0);
  digitalWrite(out3,1);
  digitalWrite(out4,0);
    
  }
  else {//dung 3
      digitalWrite(out1,0);
    digitalWrite(out2,0);
  digitalWrite(out3,0);
  digitalWrite(out4,0);
    
  }
  }

void loop() {
  ps2x.read_gamepad();  // Đọc trạng thái tay cầm

analogWrite(setspeed1,255);
analogWrite(setspeed2,255);
int lx = ps2x.Analog(PSS_LX);
int ly = ps2x.Analog(PSS_LY);
if(lx==128&&ly==127){
  dichuyen(ly,lx);
  }else{
    
  digitalWrite(out1,0);
  digitalWrite(out2,0);
  digitalWrite(out3,0);
  digitalWrite(out4,0);
  }
  delay(1000);
  }
