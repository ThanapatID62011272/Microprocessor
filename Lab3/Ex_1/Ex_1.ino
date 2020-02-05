int clk_pin = 6; //SHCP
int latch_pin = 4; //STCP
int data_pin = 5; //DS

int data;
int i=0;
int toggle=0;

uint8_t segment_no[8] = { 0x3F ,
 0x06,                          
                           0x5B,
                          0x4F,
                          0x66,
                          0x6D,
                          0x7D,
                          0x7F
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
}

void loop()
{
  data= 0b00000111;
  setLed(segment_no[8]);
}
