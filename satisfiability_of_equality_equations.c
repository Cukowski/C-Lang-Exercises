#include <stdbool.h>
#include <string.h>
#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

bool are_equal(char a, char b, int* parent);
void union_sets(char a, char b, int* parent);

bool satisfiability_of_equality_equations(string_array* param_1)
{
    int parent[26]; // for each character
    for (int i = 0; i < 26; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < param_1->size; i++) 
    {
        char a = param_1->array[i][0];
        char b = param_1->array[i][3];
        bool is_equal = param_1->array[i][1] == '=';
        if (is_equal) {
            union_sets(a, b, parent);
        }
    }

    for (int i = 0; i < param_1->size; i++) 
    {
        char a = param_1->array[i][0];
        char b = param_1->array[i][3];
        bool is_equal = param_1->array[i][1] == '=';
        if (!is_equal && are_equal(a, b, parent)) {
            return false;
        }
    }
  
    return true;
}

bool are_equal(char a, char b, int* parent) 
{
    while (parent[a - 'a'] != a - 'a') {
        a = parent[a - 'a'] + 'a';
    }
    while (parent[b - 'a'] != b - 'a') {
        b = parent[b - 'a'] + 'a';
    }
    return a == b;
}

void union_sets(char a, char b, int* parent) 
{
    while (parent[a - 'a'] != a - 'a') {
        a = parent[a - 'a'] + 'a';
    }
    while (parent[b - 'a'] != b - 'a') {
        b = parent[b - 'a'] + 'a';
    }
    parent[a - 'a'] = b - 'a';
}