#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_string_index(char* param_1, char param_2);

char* my_union(char* param_1, char* param_2)
{
    char* both = malloc(256 * sizeof(char));
    char* result = malloc(256 * sizeof(char));
    int len1 = strlen(param_1);
    int len2 = strlen(param_2);

    // takes param1 and para2 to make a joined string
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            both[i] = param_1[i];   
            both[i+j+1] = param_2[j];    
        }
    }

    int lenR = len1 + len2 + 1;
    both[lenR] = '\0';
    int a1 = 0;

    // checks recursive chars
    for (int i = 0; i < len1; i++) 
    {
        int a = my_string_index(both, param_1[i]);
        // printf("a: %d, i: %d \n", a ,i);
        if (a == i){
            result[a1] = param_1[i];
            // printf("a1: %d\n", a1);
            a1++;
        }
    } 
    int b1 = 0;
    for (int i = 0; i < len2; i++) 
    {
        int b = my_string_index(both, param_2[i]);
        // printf("b: %d, i: %d\n", b ,i);
        if (b == i+len1) {
            result[b1+a1] = param_2[i];
            // printf("b1: %d\n", b1);
            b1++;
        }
    }
    return result;

}

int my_string_index(char* param_1, char param_2)
{
    for (int i = 0; i < strlen(param_1); i++) {
        if (param_1[i] == param_2) {
            return i;
        }
    }
    return -1;
}


// int main()
// {
//     printf("%s\n", my_union("ddf6vewg64f", "gtwthgdwthdwfteewhrtag6h4ffdhsd")); // df6vewg4thras
// }