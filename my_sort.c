#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for integer array
typedef struct s_integer_array {
    int size;
    int* array;
} integer_array;

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort in ascending order
void bubbleSortAsc(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function to perform bubble sort in descending order
void bubbleSortDesc(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function to sort the array based on order
integer_array* my_sort(integer_array* param_1, char* param_2) {
    if (strcmp(param_2, "asc") == 0) {
        bubbleSortAsc(param_1->array, param_1->size);
    } else if (strcmp(param_2, "desc") == 0) {
        bubbleSortDesc(param_1->array, param_1->size);
    }
    return param_1;
}

// Function to print the array
void printArray(integer_array* arr) {
    printf("[");
    for (int i = 0; i < arr->size; i++) {
        printf("%d", arr->array[i]);
        if (i < arr->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    // Example usage
    int arr0[] = {1, 2, 1};
    integer_array param_1_0 = {3, arr0};
    printf("Input: ");
    printArray(&param_1_0);
    printf("Order: asc\nOutput: ");
    integer_array* result_0 = my_sort(&param_1_0, "asc");
    printArray(result_0);

    int arr1[] = {2, 1, -1};
    integer_array param_1_1 = {3, arr1};
    printf("\nInput: ");
    printArray(&param_1_1);
    printf("Order: asc\nOutput: ");
    integer_array* result_1 = my_sort(&param_1_1, "asc");
    printArray(result_1);

    int arr2[] = {2, 1, -1};
    integer_array param_1_2 = {3, arr2};
    printf("\nInput: ");
    printArray(&param_1_2);
    printf("Order: desc\nOutput: ");
    integer_array* result_2 = my_sort(&param_1_2, "desc");
    printArray(result_2);

    int arr3[] = {1, 7, 9, 2, -1};
    integer_array param_1_3 = {5, arr3};
    printf("\nInput: ");
    printArray(&param_1_3);
    printf("Order: blahblah\nOutput: ");
    integer_array* result_3 = my_sort(&param_1_3, "blahblah");
    printArray(result_3);

    return 0;
}
