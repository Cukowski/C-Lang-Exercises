#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *trim_string(char *str)
{
  	//take spaces in the beginning
    while (isspace(*str)) 
        str++;
    if (*str == '\0') return 
        str;
  	
  	//get last character
    char *end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) 
        end--;
    end[1] = '\0';
    return str;
}

char *rostring(char *param_1)
{
    // if (param_1 == NULL) return NULL;
    param_1 = trim_string(param_1);
    int len = strlen(param_1);
    int pos = 0;
    while (isalpha(param_1[pos])) 
        pos++;
    if (pos == len) 
        return param_1;
    char *first = malloc(sizeof(char) * (len + 1));
    strncpy(first, param_1, pos);
    while (isalpha(*param_1)) 
        param_1++;
    param_1++;
    strcat(param_1, " ");
    strcat(param_1, first);
    param_1[len] = '\0';
    return param_1;
}