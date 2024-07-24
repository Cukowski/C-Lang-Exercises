#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* capitalize(char* param_1)
{
    int len = strlen(param_1);
    char* result = (char*)malloc((len + 1) * sizeof(char));

    for (int i = 0; i < len; i++) 
    {
        // printf("%c\t", param_1[i]);
        if (i == 0 || param_1[i-1] == ' ') // if the first letter or the first letter iof the new sentance
        {
            if (param_1[i] >= 'a' && param_1[i] <= 'z') // if a lowercase letter
            {
                result[i] = param_1[i] - 32;
            }
            else
                result[i] = param_1[i];    
        }
        else // not the first char
        {
            if (param_1[i] >= 'A' && param_1[i] <= 'Z') // if a uppercase letter
            {
                result[i] = param_1[i] + 32;
            }
            else
                result[i] = param_1[i];     
        }
        // printf("%c\n", result[i]); 

    }

    result[len] = '\0';
    printf("%s", result);
    return result;
}

int main()
{
    char * test1 = "a FiRSt LiTTlE TESt";
    // Output: "A First Little Test"
    char * test2 = "__second Test A Little Bit   Moar Complex";
    char * test3 = "   But... This iS not THAT COMPLEX";
    char * test4 = "     Okay, this is the last 1239809147801 but not    the least    t";

    capitalize(test2);

    return 0;
}