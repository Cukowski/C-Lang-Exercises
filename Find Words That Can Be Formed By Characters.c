/*
**
** QWASAR.IO -- find_words_that_can_be_formed_by_characters
**
** @param {string_array*} param_1
** @param {char*} param_2
**
** @return {int}
**
*/
#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

#include <string.h>

int find_words_that_can_be_formed_by_characters(string_array* param_1, char* param_2)
{
    // Initialize an array to store character counts
    int char_count[26] = {0};

    // Count the characters in the param_2 string
    for (int i = 0; param_2[i]; ++i) {
        char_count[param_2[i] - 'a']++;
    }

    // Initialize the total sum
    int total_sum = 0;

    // Check each word in the array
    for (int i = 0; i < param_1->size; ++i) {
        int word_count[26];
        memcpy(word_count, char_count, sizeof(word_count)); // Create a copy of char_count for each word
        int valid_word = 1;

        // Decrement the count for each character in the word
        for (int j = 0; param_1->array[i][j]; ++j) {
            if (word_count[param_1->array[i][j] - 'a'] > 0) {
                word_count[param_1->array[i][j] - 'a']--;
            } else {
                valid_word = 0;
                break;
            }
        }

        if (valid_word) {
            total_sum += strlen(param_1->array[i]);
        }
    }

    return total_sum;
}