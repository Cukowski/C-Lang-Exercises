#include <stdio.h>
#include <stdlib.h>

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif

int longest_arithmetic_subsequence_of_given_difference(integer_array* param_1, int param_2) {
    int n = param_1->size;
    int *dp = (int *)malloc(n * sizeof(int));
    int maxLength = 1; // At least the subsequence contains one element

    // Initialize dp array with 1
    for (int i = 0; i < n; i++)
        dp[i] = 1;

    // Dynamic Programming
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (param_1->array[i] - param_1->array[j] == param_2) {
                dp[i] = dp[j] + 1;
                if (dp[i] > maxLength)
                    maxLength = dp[i];
            }
        }
    }

    free(dp);
    return maxLength;
}

int main() {
    integer_array arr1;
    arr1.size = 4;
    arr1.array = (int*)malloc(4 * sizeof(int));
    arr1.array[0] = 1;
    arr1.array[1] = 2;
    arr1.array[2] = 3;
    arr1.array[3] = 4;

    printf("%d\n", longest_arithmetic_subsequence_of_given_difference(&arr1, 1)); // Output: 4

    integer_array arr2;
    arr2.size = 4;
    arr2.array = (int*)malloc(4 * sizeof(int));
    arr2.array[0] = 1;
    arr2.array[1] = 3;
    arr2.array[2] = 5;
    arr2.array[3] = 7;

    printf("%d\n", longest_arithmetic_subsequence_of_given_difference(&arr2, 1)); // Output: 1

    integer_array arr3;
    arr3.size = 9;
    arr3.array = (int*)malloc(9 * sizeof(int));
    arr3.array[0] = 1;
    arr3.array[1] = 5;
    arr3.array[2] = 7;
    arr3.array[3] = 8;
    arr3.array[4] = 5;
    arr3.array[5] = 3;
    arr3.array[6] = 4;
    arr3.array[7] = 2;
    arr3.array[8] = 1;

    printf("%d\n", longest_arithmetic_subsequence_of_given_difference(&arr3, -2)); // Output: 4

    free(arr1.array);
    free(arr2.array);
    free(arr3.array);

    return 0;
}
