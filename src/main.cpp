#include <Arduino.h>
#include "graphs.h"
#include <EasyNextionLibrary.h>
#include "home_page.h"

EasyNex myNex(Serial);


void setup(){
  myNex.begin(9600);
}

void loop(){
  myNex.NextionListen();
  int page = myNex.readNumber("dp");
  if (page == 1){
    updateHomePage(myNex,10,10,10,10,10,10,10,10);
  }
}

