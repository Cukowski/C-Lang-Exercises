#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY

typedef struct s_string_array {
    int size;
    char** array;
} string_array;
#endif

int my_strlen(char *str){int len = 0; while(str[len] != 0) len++; return len;}

// check for seperator on string
bool is_sep(char chr, char sep) {return chr == sep || chr == '\0';} // if chr is sep or no chr 1 else 0

int count_bits(char* input, char sep) // how many memory bit we need?
{
    if (!input) exit(1);

    int ret = !is_sep(input[0], sep);

    for (int i = 0; input[i]; i++)
        if (is_sep(input[i], sep) && !is_sep(input[i+1], sep))
            ret++;

    return ret;
}

// {[], [], [], []}
string_array* my_split(char* param_1, char* param_2)
{
    int len1 = my_strlen(param_1);
    int len2 = my_strlen(param_2);    
    string_array *s = malloc(sizeof(string_array));
    char sep = param_2[0];

    // loop for input bits
    s->size = count_bits(param_1, sep);

    // allocate space s->array[i]
    s->array = malloc(sizeof(char*) * s->size + 1);

    // allocate space s->array[i][j]
    for (int i = 0; i < s->size; i++) s->array[i] = malloc(sizeof(char*));
    
    for (int i = 0, j = 0, a = 0; i < len1 && j < s->size; i++)
    {  
        if (param_1[i] != sep) // s->array[]
        {
            s->array[j][a] = param_1[i];
            a++;
        }
        if (param_1[i] == sep) 
        {
            j++;
            a = 0;
        }
    }

    // printf("ar 0: %s\n", s->array[0]);
    // printf("ar 1: %s\n", s->array[1]);
    // printf("ar 2: %s\n", s->array[2]);
    // printf("ar 3: %s\n", s->array[3]);
    
    return s;
}

// int main()
// {
//     // char* str = "abc def gh-!";
//     // char* sep = "-";
//     // ["abc def gh", "!"]

//     char* str = "abc def gh-!";
//     char* sep = " ";
//    // ["abc", "def", "gh-!"]


//     my_split(str, sep);

// }