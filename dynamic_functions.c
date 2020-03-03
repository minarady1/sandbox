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

int main()
{
    printf("Hello World\n");
    radio_cb_t radio_1 = rad1;
    radio_cb_t radio_2 = rad2;
    radio_1();
    radio_2();
    return 0;
}
