#include <stdio.h>

int my_iterative_factorial(int param_1)
{
    int result = 1;

    for (int i = param_1; i > 0; i--) {
        result = i * result;
    }

    return result;
}