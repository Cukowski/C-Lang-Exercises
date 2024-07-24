#include <stdlib.h>

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif

// Comparator function for sorting integers in ascending order
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Custom sorting function (bubble sort)
void custom_sort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int maximum_gap(integer_array* param_1) {
    if (param_1->size < 2)
        return 0;

    // Sort the array
    custom_sort(param_1->array, param_1->size);

    int max_difference = 0;

    for (int i = 1; i < param_1->size; i++) 
    {
        int difference = param_1->array[i] - param_1->array[i - 1];
       
        if (difference > max_difference) 
        {
            max_difference = difference;
        }
    }

    return max_difference;
}

/*
Description
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

Example 1:

**Input:** [3,6,9,1]

**Output:** 3

**Explanation:** The sorted form of the array is [1,3,6,9], either   (3,6) or (6,9) has the maximum difference 3.
Example 2:

**Input:** [10]

**Output:** 0

**Explanation:** The array contains less than 2 elements, therefore return 0.
*/