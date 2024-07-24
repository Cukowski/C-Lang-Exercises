#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *str);

char* rcapitalize(char* param_1)
{
    int len = my_strlen(param_1);
    char* temp = malloc(256 * sizeof(char));

    for (int i = 0; i < len; i++) 
    {
        if (i == len-1 && param_1[i] < 123 && param_1[i] > 96) temp[i] = param_1[i] - 32;
        else if (i == len-1 && param_1[i] < 91 && param_1[i] > 64) temp[i] = param_1[i];
        else if (param_1[i+1] == 32 && param_1[i] < 123 && param_1[i] > 96) // checks if there is a space and the char before space is a to z
        {
            temp[i] = param_1[i] - 32; // transforms a-z to A-Z
            temp[i+1] = param_1[i+1];
        }
        else if (param_1[i+1] == 32 && param_1[i] < 91 && param_1[i] > 64) // if there is space but i-1 already capital case
            temp[i] = param_1[i];
        else if (param_1[i] < 91 && param_1[i] > 64) // cheks if chars between A and Z
            temp[i] = param_1[i] + 32; // transforms to A-Z to a - z
        else temp[i] = param_1[i]; // param_1 but if in lowercase no need to translate
    }
    temp[len] = '\0'; // end of string

    return temp;
}


int my_strlen(char *str){int len = 0; while(str[len] != 0) len++; return len;}

// int main(){
//     printf("%s", rcapitalize("SecONd teST A LITtle BiT   Moar comPLEX")); 

//     return 0;
// }