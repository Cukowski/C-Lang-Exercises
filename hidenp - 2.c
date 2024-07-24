#include <stdio.h>

int my_strlen(char *str);
int my_string_index(char* param_1, char param_2);

int hidenp(char* param_1, char* param_2)
{
    int len1 = my_strlen(param_1);
    int len2 = my_strlen(param_2);
    int a = 0;
    char test[20] = {};

    for (int i = 0; i < len1; i++) 
    {
        for (int j = a; j < len2; j++)
        {
            if (param_1[i] == param_2[j] && my_string_index(test, param_1[i]) < 0)
            {
                test[a] = param_1[i];
                a++;
            }
        }
    }
    
    // printf("%s\n", test);
    // printf("%d, %d\n", a, len1);

    if (len1 == a) return 1;
    else return 0;
}

int my_strlen(char *str){int len = 0; while(str[len] != 0) len++; return len;}

int my_string_index(char* param_1, char param_2) // to find the first appearance
{
    for (int i = 0; i < my_strlen(param_1); i++)
        if (param_1[i] == param_2) return i;
    return -1;
}

// int main()
// {
//     int a = hidenp("fgex.;", "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6");
//     // int a = hidenp("abc", "btarc");

//     printf("%d\n", a);

//     return 0;
// }