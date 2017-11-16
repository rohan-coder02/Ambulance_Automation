#include <VirtualWire.h>

int reader1 = 0;
int reader2 = 0;
int reader3 = 0;
char* chardata;
const int straight = 12;
const int left = 11;
const int right = 9;

const int stlight = 13;
const int lelight = 5;
const int rilight = 6;

void setup() {
  Serial.begin(9600);

  pinMode(stlight, OUTPUT);
  pinMode(lelight, OUTPUT);
  pinMode(rilight, OUTPUT);
  
  pinMode(straight, INPUT);
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(10);
  vw_setup(4000);// speed of data transfer Kbps
}

void loop(){
  
  reader1 = digitalRead(straight);
  reader2 = digitalRead(left);
  reader3 = digitalRead(right);

  if(straight == 1){
    chardata = "00";
      digitalWrite(stlight, HIGH);
  }

  else if(left == 1){
    chardata = "10";
    igitalWrite(lelight, HIGH);

  }

  else if(right == 1){
    chardata = "01";
      digitalWrite(rilight, HIGH);
  }

  else{
    digitalWrite(stlight, LOW);
    digitalWrite(lelight, LOW);
    digitalWrite(rilight, LOW);
    chardata = "11";
  }
  vw_send((uint8_t *)chardata, strlen(chardata));
  vw_wait_tx(); // Wait until the whole message is gone
}

