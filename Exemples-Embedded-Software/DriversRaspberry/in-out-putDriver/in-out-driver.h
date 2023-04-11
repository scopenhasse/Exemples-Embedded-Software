// in this file we have the prototype of the functions to read and write to the GPIO pins of the Raspberry 
// in order to control the input and the output of the pin in the Raspberry, we need to modify the file /sys/class/gpio/export
// in order to export the pin we want to use, and then we need to modify the file /sys/class/gpio/gpioXX/direction
// in order to set the direction of the pin, and finally we need to modify the file /sys/class/gpio/gpioXX/value


// we gonna need 4 functions to control the GPIO pins of the Raspberry
// 1. load_gpio_line
// 2. set_gpio_direction
// 3. set_gpio_line
// 4. get_gpio_line

#ifndef IO_H_
#define IO_H_


#define PB0 "17"
#define PB1 "18"   
#define PB2 "22"   
#define PB3 "23"   
#define PB4 "24"   
#define PB5 "25"   
#define PB6 "26" 
#define PB7 "27"       

#define LOW  0
#define HIGH 1
#define IN   1
#define OUT  0

struct gpio_pin {
    char pin[4];
    int direction;
    int value;
};
typedef struct gpio_pin gpio_pin;

// prototype of the functions
int load_gpio_line(gpio_pin *pin, char pin_id[4]);
int set_gpio_direction(gpio_pin *pin, int direction_desired);
int set_gpio_line(gpio_pin *pin, int value);
int get_gpio_line(gpio_pin *pin);

#endif

