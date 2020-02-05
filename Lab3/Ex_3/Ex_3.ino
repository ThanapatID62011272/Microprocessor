int clk_pin = 6; //SHCP
int latch_pin = 4; //STCP
int data_pin = 5; //DS

int i=0;
int toggle=0;
int a=0;

uint8_t segment_no[10] = { 0x3F ,
                          0x06,                          
                          0x5B,
                          0x4F,
                          0x66,
                          0x6D,
                          0x7D,
                          0x07,
                          0x7F,
                          0x6F
                          };

void setLed(uint8_t _state){
digitalWrite(latch_pin,LOW);
  
for(int i = 0 ; i < 8 ; i++){
digitalWrite(data_pin,(_state >> (7-i)) & 0x01);
digitalWrite(clk_pin,HIGH); //
digitalWrite(clk_pin,LOW); //
}
digitalWrite(latch_pin,HIGH);
}

void setup()
{
DDRD = 0b01110000;//PD4-6
DDRB = 0b00000000;
}

void loop()
{
  //PINB |= 0b00000011;
  //PINB &= 0b00000011;

  //((PINB >>1) & 0x01) == 1// 0b1100 0000 -> >>6 -> 0b0000 0011 -> & 0x01 -> 0b0000 0001
  /*if(PINB == 0b00000001){
    a++;
    if(a>9){
      a=0;
    }
  }
  if(PINB == 0b00000010){
    a--;
    if(a<0){
      a=9;
    }
  }*/
  if(digitalRead(8)==0){
    a++;
    delay(300);
    if(a>9){
      a=0;
    }
  }
  if(digitalRead(9)==0){
    a--;
    delay(300);
    if(a<0){
      a=9;
    }
  }
  setLed(segment_no[a]);
  
}
