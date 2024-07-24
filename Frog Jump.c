#include <stdio.h>
#include <stdbool.h>

// Define the integer_array structure
typedef struct s_integer_array {
    int size;
    int* array;
} integer_array;

bool frog_jump(integer_array* stones) {
    int n = stones->size;

    // Create an array to store the maximum jump distance for each stone
    bool max_jump[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            max_jump[i][j] = false;
        }
    }
    max_jump[0][0] = true;  // The frog starts on the first stone with a jump of 0 units

    for (int i = 0; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            int dist = stones->array[i] - stones->array[j];
            if (dist <= j + 1) {
                max_jump[i][dist] = max_jump[j][dist - 1] || max_jump[j][dist] || max_jump[j][dist + 1];
            }
        }
    }

    // If the last stone has any valid jumps, the frog can cross the river
    for (int i = 0; i < n; ++i) {
        if (max_jump[n - 1][i]) {
            return true;
        }
    }
    return false;
}

int main() {
    // Example usage:
    int arr[] = {0, 1, 3, 5, 6, 8, 12, 17};
    integer_array stones = {sizeof(arr) / sizeof(arr[0]), arr};

    if (frog_jump(&stones)) {
        printf("The frog can cross the river.\n");
    } else {
        printf("The frog cannot cross the river.\n");
    }
    return 0;
}
