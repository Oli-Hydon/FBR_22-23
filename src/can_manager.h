#include <mcp_can.h>
#include <SPI.h>

long unsigned int rxID;
unsigned char len=0;
unsigned char rxBuf[8];


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



void set_data(int data_buffer[48]){
    int pointer_offset = (rxID - 1512)*8;
    int * pointer;
    pointer = data_buffer;
    pointer += pointer_offset;
    const char * temp = reinterpret_cast<const char *>(rxBuf);
    *pointer = atoi(temp);
}


void updateHomePageData(int data_buffer[48]){

                         
    CAN0.readMsgBuf(&rxID, &len, rxBuf);
    set_data(data_buffer);
    
}
