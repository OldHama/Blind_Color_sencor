#include <SD.h>                           //include SD module library
#include <TMRpcm.h>                       //include speaker control library

#define SD_ChipSelectPin 8                //define CS pin


TMRpcm tmrpcm;                            //crete an object for speaker library

void setup() {

  Serial.begin(9600);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
  
  tmrpcm.speakerPin = 9;                  //define speaker pin.
  //you must use pin 9 of the Arduino Uno and Nano
  //the library is using this pin

  if (!SD.begin(SD_ChipSelectPin)) {      //see if the card is present and can be initialized
    Serial.println("CAN'T READ TEH SDCARD");
    return;                               //don't do anything more if not
  }
  tmrpcm.setVolume(5);                    //0 to 7. Set volume level
}

void loop() {
    tmrpcm.play("Red.wav");
    delay(2000);
  
  delay(100);
}
