/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

typedef void                (*radio_cb_t)(void);


void rad1()
{
    printf("Tx from Radio 1\n");
}

enum radios
{
    RADIO_1,
    RADIO_2
};
int MAX_RADIOS = 2;
int SELECTED_RADIO = RADIO_2;

void rad2()
{
    printf("Tx from Radio 2\n");
}

void rad1_init()
{
    printf("Initializing  Radio 1\n");
}


void rad2_init()
{
    printf("Initializing  Radio 2\n");
}
typedef struct {
    radio_cb_t tx_radio;
    radio_cb_t init_radio;
} radio_functions_t;

int main()
{
    radio_functions_t dyn_funcs [MAX_RADIOS];
    
    dyn_funcs [0].tx_radio=rad1;
    dyn_funcs [1].tx_radio=rad2;
    dyn_funcs [0].init_radio=rad1_init;
    dyn_funcs [1].init_radio=rad2_init;

    dyn_funcs [SELECTED_RADIO].init_radio();
    dyn_funcs [SELECTED_RADIO].tx_radio();

    return 0;
}

