#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strstr(char* param_1, char* param_2) 
{
    if (*param_2 == '\0')
        return param_1;

    int len1 = strlen(param_1);
    int len2 = strlen(param_2);

    for (int j, i = 0; i <= len1 - len2; i++) 
    {
        for (j = 0; j < len2; j++) 
            if (param_1[i + j] != param_2[j])
                break;

        if (j == len2)
            return param_1 + i;
    }

    return NULL;
}

int main() {
    char param_1[] = "Hello, world!";
    char param_2[] = "world";
    char* result = my_strstr(param_1, param_2);
    
    if (result != NULL) {
        printf("param_2 found at index: %ld\n", result - param_1);
    } else {
        printf("param_2 not found.\n");
    }

    return 0;
}
