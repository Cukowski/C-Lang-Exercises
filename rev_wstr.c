#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* rev_wstr(char* param_1) {
    int len = strlen(param_1);

    char* result = (char*)malloc((len + 1) * sizeof(char)); // Allocate space for the null terminator

    int word[20] = {0};
    int word_l = 0;

    for (int i = 0; i < len; i++) {
        if (param_1[i] == ' ') {
            word[word_l] = i;
            word_l++;
        }
    }

    word[word_l] = len;
    word_l++;
    word[word_l] = '\0'; // Fix null-termination index

    int res_len = 0;

    for (int i = word_l - 1; i > 0; i--) { // Fixed loop condition
        for (int j = word[i - 1] + 1; j < word[i]; j++) { // Fixed start index
            result[res_len] = param_1[j];
            res_len++;
        }
        result[res_len] = ' '; // Add space between words
        res_len++;
    }

    // Copy the first word
    for (int j = 0; j < word[0]; j++) {
        result[res_len] = param_1[j];
        res_len++;
    }

    result[res_len] = '\0'; // Null-terminate the string

    return result;
}

int main() {
    char* p = rev_wstr("You hate people! But I love gatherings. Isn't it ironic?");

    printf("%s", p);

    free(p); // Free the allocated memory

    return 0;
}
