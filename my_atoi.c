#include <stdio.h>
#include <stdlib.h>

int my_atoi(char* param_1)
{
    int num = 0;
    int i = 0;

    if (param_1[0] == '-')
        i++;

    for (i; param_1[i] != '\0' && param_1[i] != '-'; ++i)
        num = num * 10 + param_1[i] - '0';
    
    if (param_1[0] == '-')
        num *= -1;

    return num;
}
