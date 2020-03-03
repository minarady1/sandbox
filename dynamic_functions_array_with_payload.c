/******************************************************************************
Template for dynamic radio allocation for openwsn
@minarady1
mina1.rady@orange.com
*******************************************************************************/

#include <stdio.h>

// radio functions callback types declaration
typedef void                (*radio_cb_t)(void);
typedef void                (*radio_tx_cb_t)(char * str);
// ... more types to be added in accordance with the API

// the template for radio function callbacks
// inspired from release FW_807 bsp/common/openradio.h
typedef struct {
    radio_tx_cb_t tx_radio;
    radio_cb_t init_radio;
} radio_functions_t;

// 807 release defined these two parameters in board_info.h
// this will be used to create the matrix size
#define MAX_RADIOS  3
enum radios
{
    RADIO_1,
    RADIO_2,
    RADIO_3
};

// select which radio to use for this slot
// this will be used locally but will be initialized in ti1ORri1
int SELECTED_RADIO = RADIO_1;

//function call back matrix
radio_functions_t dyn_funcs [MAX_RADIOS];

// Radio specific functions. These will be placed in separate .c files
// such as radio_RADIO1.c and radio_RADIO2.c

//======= RADIO 1 Driver ================
void rad1_init()
{
    printf("Initializing  Radio 1\n");
}

void tx_radio_rad1(char * str)
{
    printf("Tx from Radio 1\n");
    printf(str);
}

//======= RADIO 2 Driver ================
void rad2_init()
{
    printf("Initializing  Radio 2\n");
}

void tx_radio_rad2(char * str)
{
    printf("Tx from Radio 2\n");
    printf(str);
}

//======= RADIO 3 Driver ================
void rad3_init()
{
    printf("Initializing  Radio 3\n");
}

void tx_radio_rad3(char * str)
{
    printf("Tx from Radio 3\n");
    printf(str);
}

// ================ Bootstrapping ==========

// initializing the lookup table for radio function callbacks
void bootstrap()
{
    printf("Bootstrapping radios\n");
    dyn_funcs [0].init_radio    =   rad1_init;
    dyn_funcs [1].init_radio    =   rad2_init;   
    dyn_funcs [2].init_radio    =   rad3_init;   
    
    dyn_funcs [0].tx_radio      =   tx_radio_rad1;
    dyn_funcs [1].tx_radio      =   tx_radio_rad2;
    dyn_funcs [2].tx_radio      =   tx_radio_rad3;
    printf("Bootstrapping finished\n");
}

int main ()
{
    bootstrap();
    // Initialize and transmit from selected radio
    for (int i =0; i< MAX_RADIOS; i++)
    {
        SELECTED_RADIO = i; //will be configured from ti1ORri1
        
        dyn_funcs [SELECTED_RADIO].init_radio();
        char payload [12]= "\tmy packet\n";
        dyn_funcs [SELECTED_RADIO].tx_radio(payload);   
    }

    return 0;
}

