#include "PWMDriver.h"

int main()
{
    PWM pwm;
    PWMinit(&pwm, PWM0);
    PWMenable(&pwm, ENABLE);
    PWMsetPeriod(&pwm, 1000000);
    PWMsetDutyCycle(&pwm, 500000);
    PWMenable(&pwm, DISABLE);
    return 0;
}
