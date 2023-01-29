#include <Arduino.h>
#include "graphs.h"
#include <EasyNextionLibrary.h>


void setup(){
  EasyNex myNex(Serial);
}

void test_function(){
  delay(300);
  Serial.begin(9700);
  Serial.println(absolute(10));
}