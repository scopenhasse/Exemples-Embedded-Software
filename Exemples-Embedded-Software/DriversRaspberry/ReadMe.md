# Raspberry Pi Drivers Exemples :

# GPIO In-Out Driver

This code provides functions to read and write to the General Purpose Input Output (GPIO) pins of a Raspberry Pi. These functions allow for controlling the input and output of the pins on the Raspberry Pi by modifying the relevant files in `/sys/class/gpio`.

## Functions

The following functions are provided by this code:

1. `load_gpio_line`: This function exports the GPIO pin specified by the user and creates a file to control it.
2. `set_gpio_direction`: This function sets the direction of the GPIO pin specified by the user, either as input or output.
3. `set_gpio_line`: This function writes a value to the GPIO pin specified by the user, allowing for control of output pins.
4. `get_gpio_line`: This function reads the value of the GPIO pin specified by the user, allowing for control of input pins.

## How to Use

1. Include the `in-out-driver.h` header file in your C code.
2. Call `load_gpio_line` to export the GPIO pin you want to use.
3. Call `set_gpio_direction` to set the direction of the GPIO pin you want to use.
4. Call `set_gpio_line` to write a value to the GPIO pin if it is set as an output pin.
5. Call `get_gpio_line` to read the value of the GPIO pin if it is set as an input pin.

# PWM Driver

This is a C code for controlling the PWM pins on a Raspberry Pi. It provides functions to initialize the PWM, enable/disable the PWM, set the period, and set the duty cycle.

## Functions

The following functions are provided by this code:

* `PWMinit`: This function initializes the PWM for a specified channel.
* `PWMenable`: This function enables or disables the PWM output.
* `PWMsetPeriod`: This function sets the period of the PWM.
* `PWMsetDutyCycle`: This function sets the duty cycle of the PWM.

## How to Use

To use this code:

1. Include `PWMDriver.h` header file in your C code.
2. Call `PWMinit` function to initialize the PWM for the desired channel.
3. Call `PWMenable` function to enable or disable the PWM output.
4. Call `PWMsetPeriod` function to set the period of the PWM.
5. Call `PWMsetDutyCycle` function to set the duty cycle of the PWM.

# Serial Driver

## Description

This code provides a function to read temperature data from a DS18B20 temperature sensor connected to a Raspberry Pi via the 1-wire interface. The function reads the temperature data from the file "/sys/bus/w1/devices/28-072170bed5aa/w1_slave" and returns the temperature value in degrees Celsius as a floating-point number.

## Dependencies

This code uses the following libraries:

* `fcntl.h`
* `stdio.h`
* `stdlib.h`
* `unistd.h`
* `string.h`
* `sys/select.h`
* `SerialDriver.h`

## Usage

To use this code, simply call the `getTemperature()` function. The function will return the temperature value as a floating-point number.

# License

This code is released under the MIT License.

# Disclaimer

This code is provided as-is and may not be suitable for all use cases. Please use caution when modifying system files and ensure you have the necessary permissions to do so. The authors are not responsible for any damage caused by the use of this code.
