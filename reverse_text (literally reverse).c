#include <string.h>

char* rev_wstr(char* param_1)
{
  	int len = strlen(param_1);
    
    // Reverse the entire string
    int start = 0;
    int end = len - 1;
    while (start < end) {
        char temp = param_1[start];
        param_1[start] = param_1[end];
        param_1[end] = temp;
        start++;
        end--;
    }
  
 
  	return param_1;
}
