#ifndef PWM_H_
#define PWM_H_

#define PWM0 "0"
#define PWM1 "1"

#define ENABLE 1
#define DISABLE 0

struct PWM {
    char id_canal[2];
    int enable;
    long long int period;
    long long int duty_cycle;
};
typedef struct PWM PWM;

int PWMinit(PWM *ps_pwm, char id_canal[2]);
int PWMenable(PWM *ps_pwm, int i_enable);
int PWMsetPeriod(PWM *ps_pwm, long long int period);
int PWMsetDutyCycle(PWM *ps_pwm, long long int duty_cycle);

#endif 
