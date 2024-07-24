#include <stdbool.h>
bool valid_anagram(char* param_1, char* param_2)
{
    int len1 = strlen(param_1); // length  of parameters
    int len2 = strlen(param_2);

    // 126 - 32 = 94 dif possible chars
    int ar1[94] = {0};
    int ar2[94] = {0};

    if (len1 != len2)  return 0; // dif len means false

    // incrementing the chars frequency (ascii characters between 32 and 126 inclusive.)
    for (int i = 0; param_1[i]; i++) 
    {
        ar1[param_1[i]-32]++;
        ar2[param_2[i]-32]++;
    }
    
    for(int i = 0; i < 94; i++)
        if(ar1[i] != ar2[i]) return 0;
        
    return 1;
}
