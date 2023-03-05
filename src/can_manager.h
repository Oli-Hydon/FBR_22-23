#include <mcp_can.h>
#include <SPI.h>

long unsigned int rxID;
unsigned char len=0;
unsigned char rxBuf[8];
char msgString[128];


#define CAN0_INT 2
MCP_CAN CAN0(10);


bool startCan(){
    if(!(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ)==CAN_OK)){
        return 0;
    }
    else{
        CAN0.setMode(MCP_NORMAL);
        pinMode(CAN0_INT, INPUT);
        return 1;
    };
}

void updateHomePageData(int *engine_rpm, int* speed, int* stick_position,
                         int* oil_pressure, int* engine_temperature, int* air_pressure, int* coolant_temp,
                         int* battery_voltage){

                         
    CAN0.readMsgBuf(&rxID, &len, rxBuf);
    if (rxID == 0x5E8){
        set_data_0x5E8();
    }
    else if (rxID == 0x5E9){
        set_data_0x5E9();
    }
    else if (rxID == 0x5EA){
        set_data_0x5EA();
    }
    else if (rxID == 0x5EB){
        set_data_0x5EB();
    }
    else if (rxID == 0x5EC){
        set_data_0x5EC();
    }
    else if (rxID == 0x5ED){
        set_data_0x5ED();
    }
    
}


void set_data_0x5E8(){

}
void set_data_0x5E9(){

}
void set_data_0x5EA(){

}
void set_data_0x5EB(){

}
void set_data_0x5EC(){

}
void set_data_0x5ED(){

}