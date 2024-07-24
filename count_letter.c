#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* count_letter(char *param_1) {
    int counts[26] = {0}; // Assuming only lowercase letters
    int len = strlen(param_1);
    char chars[26] = {0}; // Store characters as they occur
    int charCount = 0;
    
    // Count occurrences of alphabetical characters
    for (int i = 0; i < len; i++) 
    {
        char c = param_1[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
        {
            if (c >= 'A' && c <= 'Z') 
            {
                c += ('a' - 'A'); // Convert uppercase to lowercase
            }
            int index = c - 'a';
            if (counts[index] == 0) 
            {
                chars[charCount++] = c;
            }
            counts[index]++;
        }
    }
    
    // Construct the result string
    char* result = (char*)malloc(100 * sizeof(char)); // Allocate memory for the result
    int pos = 0;
    
    for (int i = 0; i < charCount; i++) 
    {
        int index = chars[i] - 'a';
        pos += sprintf(result + pos, "%d%c, ", counts[index], chars[i]);
    }
    if (pos > 0) {
        result[pos - 2] = '\0'; // Remove the last ", " from the string
    } else {
        result[0] = '\0'; // Empty string
    }
    
    return result;
}

int main() {
    // Example usage:
    char* result1 = count_letter("abbcc");  // Output: "1a, 2b, 2c"
    printf("%s\n", result1);
    free(result1);
    
    char* result2 = count_letter("My Hyze 47y 7.");  // Output: "1m, 3y, 1h, 1z, 1e"
    printf("%s\n", result2);
    free(result2);
    
    char* result3 = count_letter("");  // Output: ""
    printf("%s\n", result3);
    free(result3);
    
    return 0;
}
