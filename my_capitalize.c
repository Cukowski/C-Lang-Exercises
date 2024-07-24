#include <stdio.h>

char* my_capitalize(char* param_1) 
{
    if (param_1 == NULL) return param_1;
    
    int len = strlen(param_1);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int pos = 0;

    int start_index = 0;
    while (start_index < len) {
        if(param_1[start_index]  == ' ')
            start_index++;
        else break;
    }

    for (int i = 0; i < len; i++) 
    {
        if (i == start_index && (param_1[i] >= 'a' && param_1[i] <= 'z'))
        {
            result[pos] = param_1[i] - 32;
            pos++;
        }
        else if ((i !=  start_index) && (param_1[i] >= 'A' && param_1[i] <= 'Z'))
        {
            result[pos] = param_1[i] + 32;
            pos++;
        }
        else
        {
            result[pos] = param_1[i];
            pos++;
        }
            
    }

    result[pos] = '\0';

    return result;
}

int main() {
    char input1[] = "aBc";
    printf("Input: \"%s\"\n", input1);
    printf("Output: \"%s\"\n", my_capitalize(input1)); // Output: "Abc"

    char input2[] = "    AbcE     Fgef1    ";
    printf("Input2: \"%s\"\n", input2);
    printf("Output: \"%s\"\n", my_capitalize(input2)); // Output: ""

    char input3[] = "AbcE Fgef1";
    printf("Input: \"%s\"\n", input3);
    printf("Output: \"%s\"\n", my_capitalize(input3)); // Output: "Abce fgef1"

    return 0;
}
