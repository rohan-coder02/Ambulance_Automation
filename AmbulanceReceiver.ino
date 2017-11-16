#include <VirtualWire.h>
#include <string.h>


//Green lights
const int stgreen = 12;
const int legreen = 11;
const int rigreen = 9;
const int bagreen = 7;
//Red lights
const int stred = 13;
const int lered = 5;
const int rired = 6;
const int bared = 3;

void setup()
{
  Serial.begin(9600);
  
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(12);
  vw_setup(4000); // Bits per sec

  //Green lights as outputs
  pinMode(stgreen, OUTPUT);
  pinMode(legreen, OUTPUT);
  pinMode(rigreen, OUTPUT);
  pinMode(bagreen, OUTPUT);


  //Red lights as outputs
  pinMode(stred, OUTPUT);
  pinMode(lered, OUTPUT);
  pinMode(rired, OUTPUT);
  pinMode(bared, OUTPUT);


  vw_rx_start(); // Start the receiver PLL running
}


void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen)){ // Non-blocking
    digitalWrite(13, 0);

    if(strcmp(buf, "00")){
      digitalWrite(stgreen, 1);
      digitalWrite(legreen, 0);
      digitalWrite(rigreen, 0);
      digitalWrite(stred, 0);
      digitalWrite(lered, 1);
      digitalWrite(rired, 1);
      digitalWrite(bared, 1);

    }

    if(strcmp(buf, "10")){
      digitalWrite(stgreen, 0);
      digitalWrite(legreen, 1);
      digitalWrite(rigreen, 0);
      digitalWrite(stred, 1);
      digitalWrite(lered, 0);
      digitalWrite(rired, 1);
      digitalWrite(bared, 1);


    }

    if(strcmp(buf, "01")){
      digitalWrite(stgreen, 0);
      digitalWrite(legreen, 0);
      digitalWrite(rigreen, 1);
      digitalWrite(stred, 1);
      digitalWrite(lered, 1);
      digitalWrite(rired, 0);
      digitalWrite(bared, 1);

    }
  }
}


