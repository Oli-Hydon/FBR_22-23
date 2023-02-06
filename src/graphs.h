#include <Arduino.h>
#include <EasyNextionLibrary.h>


int convert_to_graph_value(int min, int max, int value){
    int max_return_value = 5*256/6;

    max -= min;



    value = value * (max_return_value/max);
    value += min;
    return value;
}