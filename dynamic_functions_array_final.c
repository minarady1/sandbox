/******************************************************************************
Template for dynamic radio allocation for openwsn
@minarady1
mina1.rady@orange.com
*******************************************************************************/

#include <stdio.h>

typedef void                (*radio_cb_t)(void);
// ... more types to be added in accordance with the API

enum radios
{
    RADIO_1,
    RADIO_2
};
// 807 release defined these two parameters in board_info.h
int MAX_RADIOS = 2;
int SELECTED_RADIO = RADIO_2;

// Radio specific functions. These will be placed in separate .c files
// such as radio_RADIO1.c and radio_RADIO2.c
void rad1_init()
{
    printf("Initializing  Radio 1\n");
}

void tx_radio_rad1()
{
    printf("Tx from Radio 1\n");
}

void rad2_init()
{
    printf("Initializing  Radio 2\n");
}

void tx_radio_rad2()
{
    printf("Tx from Radio 2\n");
}


typedef struct {
    radio_cb_t tx_radio;
    radio_cb_t init_radio;
} radio_functions_t;

int main()
{
    radio_functions_t dyn_funcs [MAX_RADIOS];

    dyn_funcs [0].init_radio    =   rad1_init;
    dyn_funcs [1].init_radio    =   rad2_init;   
    dyn_funcs [0].tx_radio      =   tx_radio_rad1;
    dyn_funcs [1].tx_radio      =   tx_radio_rad2;
    
    // Initialize and transmit from selected radio
    dyn_funcs [SELECTED_RADIO].init_radio();
    dyn_funcs [SELECTED_RADIO].tx_radio();

    return 0;
}

