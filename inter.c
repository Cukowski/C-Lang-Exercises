#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* 
Write a function that takes two strings and return, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.
*/
int my_string_index(char* param_1, char param_2);

char* inter(char* param_1, char* param_2)
{
    int len1 = strlen(param_1);
    int len2 = strlen(param_2);
    char* result = malloc(256 * sizeof(char));
    char* temp1 = malloc(256 * sizeof(char));

    // check if p1 has same chars as p2
    // check if p1 has duplicate strings
    // print common chars

    int a1 = 0; // len of temp1
    for (int i = 0; i < len1; i++) 
    {
        int a = my_string_index(param_1, param_1[i]);
        if (a == i)
        {
            temp1[a1] = param_1[i];
            a1++;
        }
    } 
    // temp1 has the non repead p1 values in it
    //check if temp1 has values of p2
    // printf("temp1: \t%s\n", temp1);

    int b1 = 0;
    for (int i = 0; i < a1; i++) // temp1[1] = f
    {
        for(int j = 0; j < len2; j++) // p2[12] = f
        {
            if (temp1[i] == param_2[j] && my_string_index(result, temp1[i]) < 0) // does temp1 has p2 chars? does this value is already in result? 
            {
                result[b1] = temp1[i]; 
                b1++;
            }
        }
    }


    return result;
}

int my_string_index(char* param_1, char param_2) // to find the first appearance
{
    for (int i = 0; i < strlen(param_1); i++) {
        if (param_1[i] == param_2) return i;
    }
    return -1;
}

// int main()
// {
//     printf("result: \t%s\n", inter("ddf6vewg64f", "gtwthgdwthdwfteewhrtag6h4ffdhsd")); // df6ewg4
//     printf("expected: \tdf6ewg4\n");
//     // printf("%s\n", inter("aaaaa", "a")); // df6ewg4

//     // inter("ddf6vewg64f", "gtwthgdwthdwfteewhrtag6h4ffdhsd");
//     return 0;
// }