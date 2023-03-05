#include <Arduino.h>
#include <EasyNextionLibrary.h>

void updateTachometer(uint32_t value,EasyNex myNex){
    
    uint32_t number_of_images = 208;     //There are actually 209 but the 0th image doesnt count

    uint32_t offset = 2;
    uint32_t image_number;
    if (value>16){
        image_number = number_of_images;
    }else{
        image_number = value * (16/number_of_images);
    }
    image_number += offset;

    myNex.writeNum("tachometer.pic",image_number);
}


void updateSpeedometer(uint32_t value,EasyNex myNex){
    uint32_t number_of_images = 270;     //There are actually 271 but the 0th image doesnt count
    uint32_t offset = 211;
    uint32_t image_number;
     
    if (value>120){
        image_number = number_of_images;
    }else{
        image_number = value * (120/number_of_images);
    }
    image_number += offset;

    myNex.writeNum("speedometer.pic",image_number);
}

void updateStickPosition(int position, EasyNex myNex){
    if ((position > 0) && (position < 7)){
        int offset = 481;
        int image_number = offset+position;
        myNex.writeNum("stick_pos.pic",image_number);
    }
}

void updateOilPressure(int value, EasyNex myNex){
    int in_red_bound = 90; //change this is not pressure but value on progress bar
    int in_orange_band = 80; //"" ""
    int max_val = 150; // The maximum value of oil pressure to be 100 on the progress bar

    int scaled_for_bar_value = value * (100/max_val);
    if (scaled_for_bar_value > 100){
        scaled_for_bar_value = 100;
    };
    myNex.writeNum("oil_guage.val",scaled_for_bar_value);
    
    int colour = 1024;  //Colour value for a visual warning on the guage
    if (scaled_for_bar_value > in_red_bound){
        colour = 40960;
    }else if (scaled_for_bar_value > in_orange_band){
        colour = 45504;
    };
    myNex.writeNum("oil_guage.pco",colour);
}

void updateTemp(int value, EasyNex myNex){
    int in_red_bound = 90; //change this is not temp but value on progress bar
    int in_orange_band = 80; //"" ""
    int max_val = 150; // The maximum value of temperature to be 100 on the progress bar

    int scaled_for_bar_value = value * (100/max_val);
    if (scaled_for_bar_value > 100){
        scaled_for_bar_value = 100;
    };
    myNex.writeNum("temp_guage.val",scaled_for_bar_value);
    
    int colour = 1024;  //Colour value for a visual warning on the guage -inital = green
    if (scaled_for_bar_value > in_red_bound){
        colour = 40960; //red
    }else if (scaled_for_bar_value > in_orange_band){
        colour = 45504; //orange
    };
    myNex.writeNum("temp_guage.pco",colour);
}
void updateCoolantTemp(int temp,EasyNex myNex){ //Turns warning light on/off
    int max_safe_val = 100;
    int min_safe_val = 0;
    int colour = 1024; //green
    if ((temp> max_safe_val)||(temp < min_safe_val)){
        colour = 40960; //red
    }
    myNex.writeNum("coolant_temp.pco",colour);

}

void updateAirPressure(int pressure, EasyNex myNex){ //Turns warning light on/of 
    int max_safe_val = 100;
    int min_safe_val = 10;
    int colour = 1024; //green
    if ((pressure> max_safe_val)||(pressure < min_safe_val)){
        colour = 40960; //red
    }
    myNex.writeNum("air_pressure.pco",colour);

}

void updateBatteryVoltage(int voltage, EasyNex myNex){ //Turns warning light on/off
    int max_safe_val = 12.5;
    int min_safe_val = 11.5;
    int colour = 1024; //green
    if ((voltage> max_safe_val)||(voltage < min_safe_val)){
        colour = 40960; //red
    }

    myNex.writeNum("battery_volts.pco",colour);
}
void setWarningLights(int battery_voltage,int coolant_temp, int air_pressure,EasyNex myNex){ //Just runs the updates only for simplification
    updateAirPressure(air_pressure, myNex);
    updateCoolantTemp(coolant_temp, myNex);
    updateBatteryVoltage(battery_voltage,myNex);
}



void updateHomePage(EasyNex myNex, int *engine_rpm, int* speed, int* stick_position,
                         int* oil_pressure, int* engine_temperature, int* air_pressure, int* coolant_temp,
                         int* battery_voltage){

      

        setWarningLights(*battery_voltage,*coolant_temp,*air_pressure, myNex);
        updateTachometer(*engine_rpm, myNex);
        updateSpeedometer(*speed, myNex);
        updateStickPosition(*stick_position,myNex);
        updateTemp(*engine_temperature,myNex);
        updateOilPressure(*oil_pressure,myNex);



}

