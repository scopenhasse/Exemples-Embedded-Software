#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "PWMDriver.h"


// choisir le canal pwm0 ou pwm1

int PWMinit(PWM * pwm, char id_canal[2]){

    FILE *pwmfile;

    if ((pwmfile = fopen("/sys/class/pwm/pwmchip0/export", "w")) == NULL) //declarer fichier p_pwm pour acceder au fichier export et on lui donne le droit d'ecrire
    {
        printf("Cannot open export file.\n");//si ma3ndich droit d 'acces cannot open
        exit(1);
    }

    rewind(pwmfile);//pointer sur le debut du fichier
    strcpy(pwm->id_canal, id_canal);//copier de la structure pswm l'id canal de la structure et on la pose dans id du canal du fichier export
    fwrite(&pwm->id_canal, sizeof(char), 1, pwmfile); 
    fclose(pwmfile);
  
    return 0;
}

//activer ou désactiver pwm

int PWMenable(PWM *pwm, int i_enable)
{

    FILE *pwmenablefile;
    char pwm_enable[50];
    char c_enable[2];
    
    sprintf(pwm_enable, "/sys/class/pwm/pwmchip0/pwm%s/enable", pwm->id_canal);
        
    if ((pwmenablefile = fopen(pwm_enable, "w")) == NULL){
        printf("Cannot open enable file.\n");
        exit(1);
    }

    rewind(pwmenablefile);
    sprintf(c_enable, "%d", i_enable);
    pwm->enable = i_enable;
    fwrite(&c_enable, sizeof(char), 1, pwmenablefile);
    fclose(pwmenablefile);

    return 0;
}

//définir la periode 

int PWMsetPeriod(PWM *pwm, long long int i_period){

    FILE *pwmperiodfile;
    char pwm_period[50];
    char c_period[8];
    
    PWMenable(pwm,0);
    sprintf(pwm_period, "/sys/class/pwm/pwmchip0/pwm%s/period", pwm->id_canal);
    
    if ((pwmperiodfile = fopen(pwm_period, "w")) == NULL){
        printf("Cannot open period file.\n");
        exit(1);
    }
        
    rewind(pwmperiodfile);
    sprintf(c_period, "%lli", i_period);
    pwm->period = i_period;
    fwrite(&c_period, sizeof(char), 8, pwmperiodfile);
    fclose(pwmperiodfile);
    PWMenable(pwm,1);
  
    return 0;
}


//définir le rapport cyclique 

int PWMsetDutyCycle(PWM *pwm, long long int i_duty_cycle){

    FILE * pwmdutycyclefile;
    char pwm_duty_cycle[50];
    char c_duty_cycle[8];
    
    PWMenable(pwm,0);
    sprintf(pwm_duty_cycle, "/sys/class/pwm/pwmchip0/pwm%s/duty_cycle", pwm->id_canal);

    if ((pwmdutycyclefile = fopen(pwm_duty_cycle, "w")) == NULL){
        printf("Cannot open duty cycle file.\n");
        exit(1);
    }
        
    rewind(pwmdutycyclefile);
    sprintf(c_duty_cycle, "%lli", i_duty_cycle);
    pwm->duty_cycle = i_duty_cycle;
    fwrite(&c_duty_cycle, sizeof(char), 8, pwmdutycyclefile);
    fclose(pwmdutycyclefile);
    PWMenable(pwm,1);
  
    return 0;
}
