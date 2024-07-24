#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char* remove_duplicate_letters(char* param_1) 
{
    // Array to keep track of character frequency
    int count[26] = {0};
    // Array to keep track of whether a character is visited in the result
    bool visited[26] = {false};
    // Stack to store characters in the result
    char stack[26];
    int top = -1;

    // Count the frequency of each character
    for (int i = 0; param_1[i] != '\0'; i++) {
        count[param_1[i] - 'a']++;
    }

    // Iterate through the string
    for (int i = 0; param_1[i] != '\0'; i++) {
        // Decrement the frequency of the current character
        count[param_1[i] - 'a']--;

        // If the character is already visited, skip
        if (visited[param_1[i] - 'a']) {
            continue;
        }

        // Pop characters from the stack if they are greater than the current character and still occur later in the string
        while (top >= 0 && param_1[i] < stack[top] && count[stack[top] - 'a'] > 0) {
            visited[stack[top] - 'a'] = false;
            top--;
        }

        // Push the current character onto the stack and mark it as visited
        stack[++top] = param_1[i];
        visited[param_1[i] - 'a'] = true;
    }

    // Null terminate the result string
    stack[top + 1] = '\0';

    // Copy the result string to dynamically allocated memory
    char* result = (char*)malloc((top + 2) * sizeof(char));
    strcpy(result, stack);

    return result;
}

char* my_strcpy(char* param_1, char* param_2);

char* remove_duplicate_letters(char* param_1) 
{
    int count[26] = {0};
    bool visited[26] = {false};
    char stack[26];
    int top = -1;

    for (int i = 0; param_1[i] != '\0'; i++) {
        count[param_1[i] - 'a']++;
    }

    for (int i = 0; param_1[i] != '\0'; i++) 
    {
        count[param_1[i] - 'a']--;

        if (visited[param_1[i] - 'a']) {
            continue;
        }

        while (top >= 0 && param_1[i] < stack[top] && count[stack[top] - 'a'] > 0) {
            visited[stack[top] - 'a'] = false;
            top--;
        }

        stack[++top] = param_1[i];
        visited[param_1[i] - 'a'] = true;
    }

    stack[top + 1] = '\0';

    char* result = (char*)malloc((top + 2) * sizeof(char));
    my_strcpy(result, stack);

    return result;
}


size_t my_strlen(const char* str) {
    size_t length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

char* my_strcpy(char* param_1, char* param_2)
{
    for (int i = 0; i < my_strlen(param_2); i++)
        param_1[i] = param_2[i];
    return param_1;
}

