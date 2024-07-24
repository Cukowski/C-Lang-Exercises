#include <stdio.h>
#include <stdlib.h>
int my_strlen(char *str);

char* my_strip(char* param_1)
{
    char* result = malloc(256 * sizeof(char));
    int len = my_strlen(param_1);

    for (int i = 0, j = 0; i < len; i++) 
    {
        if (param_1[i] != ' ' || (param_1[i] == ' ' && param_1[i+1] != ' '&& param_1[i+1] != '\0' && param_1[i-1] != '\0')) // if not space OR if space but not the one after AND the first one is not space
        {
            result[j] = param_1[i];
            j++;
        }
    }
    // printf("R: %s\n", result);
    // printf("E: this time it will be more complex .\n");
    return result;
}

int my_strlen(char *str){int len = 0; while(str[len] != 0) len++; return len;}

// int main() 
// {
//     my_strip(" this        time it      will     be    more complex  . ");
// }