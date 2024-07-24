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

integer_array* find_duplicates(integer_array* param_1, int param_2, integer_array* param_3, int param_4) 
{
    int* result = (int*)malloc(sizeof(int) * (param_2 < param_4 ? param_2 : param_4)); 
    int result_size = 0;

    int i = 0, j = 0;
    while (i < param_2 && j < param_4) 
    {
        if (param_1->array[i] < param_3->array[j]) 
        {
            i++;
        } 
        else if (param_1->array[i] > param_3->array[j]) 
        {
            j++;
        } 
        else 
        {
            result[result_size++] = param_1->array[i];
            i++;
            j++;
        }
    }

    integer_array* duplicates = (integer_array*)malloc(sizeof(integer_array));
    duplicates->size = result_size;
    duplicates->array = result;

    return duplicates;
}

int main() {
    // Example usage
    int arr1[] = {1, 2, 10, 15};
    int arr2[] = {2, 20, 40, 70};
    integer_array* array1 = (integer_array*)malloc(sizeof(integer_array));
    array1->size = 4;
    array1->array = arr1;
    integer_array* array2 = (integer_array*)malloc(sizeof(integer_array));
    array2->size = 4;
    array2->array = arr2;

    integer_array* result = find_duplicates(array1, array1->size, array2, array2->size);
    for (int i = 0; i < result->size; i++) {
        printf("%d ", result->array[i]);
    }
    printf("\n");
    
    return 0;
}
