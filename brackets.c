#include <stdio.h>

int brackets(char* param_1) {
    char stack[1000]; // Assuming a maximum length for the stack
    int top = -1; // Initialize top of stack

    // Traverse the string
    for (int i = 0; param_1[i] != '\0'; i++) {
        // If current character is an opening bracket, push it onto the stack
        if (param_1[i] == '(' || param_1[i] == '[' || param_1[i] == '{') {
            stack[++top] = param_1[i];
        }
        // If current character is a closing bracket
        else if (param_1[i] == ')' || param_1[i] == ']' || param_1[i] == '}') {
            // If the stack is empty or if the top of stack does not match the corresponding opening bracket
            if (top == -1 || 
                (param_1[i] == ')' && stack[top] != '(') ||
                (param_1[i] == ']' && stack[top] != '[') ||
                (param_1[i] == '}' && stack[top] != '{')) {
                return 0; // Not correctly bracketed
            }
            top--; // Pop the top of stack
        }
    }

    // If stack is empty, all brackets are matched
    return (top == -1) ? 1 : 0;
}

int main() {
    printf("%d\n", brackets("(johndoe)")); // Output: 1
    printf("%d\n", brackets("([)]")); // Output: 0
    printf("%d\n", brackets("{[(0 + 0)(1 + 1)](3*(-1)){()}}")); // Output: 1
    printf("%d\n", brackets("")); // Output: 1
    return 0;
}
