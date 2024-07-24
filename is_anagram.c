#include <stdio.h>
#include <stdlib.h>
int my_strlen(char *str);

int is_anagram(char* param_1, char* param_2)
{
    int len1 = my_strlen(param_1); // length  of parameters
    int len2 = my_strlen(param_2);

    // int *ar1 = malloc(sizeof(int)); // mallocing the int frequency arrays
    // int *ar2 = malloc(sizeof(int)); 

    // 126 - 32 = 94 dif possible chars
    int ar1[94] = {0};
    int ar2[94] = {0};

    if (len1 != len2)  return 0; // dif len means false

    // printf("%s", param_1);

    // incrementing the chars frequency (ascii characters between 32 and 126 inclusive.)
    for (int i = 0; param_1[i]; i++) 
    {
        ar1[param_1[i]-32]++;
        ar2[param_2[i]-32]++;
        // printf("i: %d\n", i);
    }

    // printf("a1 a: %d\n", ar1[65]);
    // printf("a2 a: %d\n", ar2[65]);

    // printf("a2 b: %d\n", ar2[66]);
 
    
    for(int i = 0; i < 94; i++)
        if(ar1[i] != ar2[i]) return 0;
        
    return 1;
    
}

int my_strlen(char *str){int len = 0; while(str[len] != 0) len++; return len;}

// int main()
// {
//     char param_1[] = "ad";
//     char param_2[] = "bc";

//     int r = is_anagram(param_1, param_2);
//     printf("r: %d", r);
// }