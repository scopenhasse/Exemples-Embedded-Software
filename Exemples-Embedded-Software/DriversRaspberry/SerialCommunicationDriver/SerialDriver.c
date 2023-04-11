#include<fcntl.h> 
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<string.h> 
#include<sys/select.h> 
#include "SerialDriver.h" 

float getTemperature(){

    int fd;
    char buffer[1000];
    fd = open("/sys/bus/w1/devices/28-072170bed5aa/w1_slave", O_RDONLY);
    int len = read(fd, buffer, sizeof(buffer));
    char temp[10];
    strncpy(temp, buffer + len - 6, 5);
    float tt;
    tt = atof(temp) / 1000;
    close(fd);
    return tt;
    
}