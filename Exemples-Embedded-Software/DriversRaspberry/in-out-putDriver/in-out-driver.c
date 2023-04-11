// in this file we have the functions to read and write to the GPIO pins of the Raspberry 
// in order to control the input and the output of the pin in the Raspberry, we need to modify the file /sys/class/gpio/export
// in order to export the pin we want to use, and then we need to modify the file /sys/class/gpio/gpioXX/direction
// in order to set the direction of the pin, and finally we need to modify the file /sys/class/gpio/gpioXX/value


// we gonna need 4 functions to control the GPIO pins of the Raspberry
// 1. load_gpio_line
// 2. set_gpio_direction
// 3. set_gpio_line
// 4. get_gpio_line

#include "in-out-driver.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int load_gpio_line(gpio_pin *pin_t, char pin_id[4]){
    // we going to act on the file /sys/class/gpio/export
    FILE *p_gpio_line; // pointer to the file /sys/class/gpio/export
    p_gpio_line = fopen("/sys/class/gpio/export", "w"); // open the file /sys/class/gpio/export in write mode
    rewind(p_gpio_line); // set the pointer to the beginning of the file
    strcpy(pin_t->pin, pin_id); // copy the id_number of the pin to the structure
    fwrite(&pin_t->pin, sizeof(char), 2, p_gpio_line); // write the id_number of the pin to the file
    fclose(p_gpio_line); // close the file
    return 0;
}

int set_gpio_direction(gpio_pin *pin, int direction_desired){

    // we going to act on the file /sys/class/gpio/gpioXX/direction
    FILE *p_gpio_direction; // pointer to the file /sys/class/gpio/gpioXX/direction
    char gpio_direction[35]; // string to store the path to the file /sys/class/gpio/gpioXX/direction

    sprintf(gpio_direction, "/sys/class/gpio/gpio%s/direction", pin->pin); // create the path to the file /sys/class/gpio/gpioXX/direction
    p_gpio_direction = fopen(gpio_direction, "w+"); // open the file /sys/class/gpio/gpioXX/direction in write mode
    rewind(p_gpio_direction); // set the pointer to the beginning of the file

    if(direction_desired){
        fputc((int)'i', p_gpio_direction);
        fputc((int)'n', p_gpio_direction); // write in to the file
        pin->direction = 1;
    }
    else{
        fputc((int)'o', p_gpio_direction);
        fputc((int)'u', p_gpio_direction);
        fputc((int)'t', p_gpio_direction);        
        pin->direction = 0;
    }
    fclose(p_gpio_direction); // close the file
    return 0;
}

int set_gpio_line(gpio_pin *pin, int value){
    // we going to act on the file /sys/class/gpio/gpioXX/value
    FILE *p_gpio_value; // pointer to the file /sys/class/gpio/gpioXX/value
    char gpio_value[35]; // string to store the path to the file /sys/class/gpio/gpioXX/value
    char c_value[2] ;
    if(pin->direction == 0){
        sprintf(gpio_value, "/sys/class/gpio/gpio%s/value", pin->pin); // create the path to the file /sys/class/gpio/gpioXX/value
        p_gpio_value = fopen(gpio_value, "w"); // open the file /sys/class/gpio/gpioXX/value in write mode
        rewind(p_gpio_value); // set the pointer to the beginning of the file
        sprintf(c_value, "%d", value);
        pin->value = value; // write the value of the pin
        fwrite(&c_value, sizeof(char), 1, p_gpio_value);
        fclose(p_gpio_value); // close the file
    }
    else{
        printf("The pin is set as input, you can't write to it");
        exit(1);
    }
    return 0;
}

int get_gpio_line(gpio_pin *pin){
    // we going to act on the file /sys/class/gpio/gpioXX/value
    FILE *p_gpio_value; // pointer to the file /sys/class/gpio/gpioXX/value
    char gpio_value[35]; // string to store the path to the file /sys/class/gpio/gpioXX/value
    int value = 0;
    if (pin->direction == 1){
        sprintf(gpio_value, "/sys/class/gpio/gpio%s/value", pin->pin); // create the path to the file /sys/class/gpio/gpioXX/value
        p_gpio_value = fopen(gpio_value, "r"); // open the file /sys/class/gpio/gpioXX/value in read mode
        rewind(p_gpio_value); // set the pointer to the beginning of the file
        pin->value = fgetc(p_gpio_value); // read the value of the pin
        value = fgetc(p_gpio_value);
        fclose(p_gpio_value); // close the file
    }    
    return value;
}
