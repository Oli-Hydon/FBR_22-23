#include <Arduino.h>
#include <graphs.h>
#include <EasyNextionLibrary.h>
#include <home_page.h>
#include <can_manager.h>
EasyNex myNex(Serial);
int data_buffer[48] = { 0 };



void setup(){
  while (!startCan()){
    Serial.begin(10);
    Serial.println("Waiting for CAN");
  };
  delay(500);
  myNex.begin(9600);

}

void loop(){
  myNex.NextionListen();
  int page = myNex.readNumber("dp");
  if (page == 1){
    updateHomePageData(data_buffer);
    updateHomePage(myNex,data_buffer);
    };
}
