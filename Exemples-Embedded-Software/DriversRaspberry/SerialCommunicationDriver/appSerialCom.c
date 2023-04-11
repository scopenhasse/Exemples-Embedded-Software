#include <stdio.h>
#include <stdlib.h>
#include "SerialDriver.h"

int main() {
    float temperature = getTemperature();
    printf("Temperature: %f", temperature);
}