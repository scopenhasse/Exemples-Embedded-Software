// we going to use the driver in the in-out-putDriver.c file to control the GPIO pins of the Raspberry
//
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include "in-out-driver.h"

int main()
{
    gpio_pin pin1;
    load_gpio_line(&pin1, PB0);
    set_gpio_direction(&pin1, OUT);
    set_gpio_line(&pin1, HIGH);
    get_gpio_line(&pin1);
    return 0;
}
