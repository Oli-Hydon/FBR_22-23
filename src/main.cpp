#include <Arduino.h>
#include <graphs.h>
#include <EasyNextionLibrary.h>
#include <home_page.h>
#include <can_manager.h>
EasyNex myNex(Serial);
int manifold_air_pressure = 0;
int engine_rpm = 0;
int coolant_temperature = 0;
int throttle_position = 0;
int main_pulse_width_bank_1 = 0;
int main_pulse_width_bank_2 = 0;
int manifold_air_temperature = 0;
int fuel_ignition_spark_advance = 0;
int bank1_afr_target = 0;
int speed = 0;
int oil_pressure = 0;
int engine_temperature = 0;
int battery_voltage = 0;


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
    updateHomePageData(&engine_rpm,&speed,&throttle_position, &oil_pressure, &engine_temperature, &manifold_air_pressure, &coolant_temperature, &battery_voltage);
    updateHomePage(myNex,&engine_rpm,&speed,&throttle_position, &oil_pressure, &engine_temperature, &manifold_air_pressure, &coolant_temperature, &battery_voltage);
  }
}

