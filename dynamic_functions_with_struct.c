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
    radio_cb_t radio_1;
    radio_cb_t radio_2;
    radio_cb_t init_radio_1;
    radio_cb_t init_radio_2;
} radio_functions_t;



int main()
{
    printf("Hello World\n");
    radio_functions_t funcs;
    funcs.radio_1 = rad1;
    funcs.radio_2 = rad2;
    funcs.init_radio_1 = rad1_init;
    funcs.init_radio_2 = rad2_init;

    funcs.init_radio_1();
    funcs.radio_1();

    funcs.init_radio_2();
    funcs.radio_2();
    return 0;
}

