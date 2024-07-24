#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

int chr_appears(char *str ,string_array* param_1, int param_2)
{
  for (int i = 1; i < param_2; i++) 
  {
    if (strstr(param_1->array[i], str) == NULL) 
    {
      return 0;
    }
  }
  return 1;
}

char* str_maxlenoc(string_array* param_1, int param_2)
{
  if (param_2 == 0) return "";
  
  char *first = param_1->array[0];
  int len = strlen(first);
  char *result = (char*)malloc(len + 1);
  strcpy(result, "");
  
  for (int i = 0; i < len; i++)
  {
    char current[2] = {first[i], '\0'};
    if (chr_appears(current, param_1, param_2))
    {
      printf("%s\n", current);
      strcat(result, current);
    }
  }
  return result;
}

int main() {
    string_array arr1;
    arr1.size = 3;
    arr1.array = (char**)malloc(3 * sizeof(char*));
    arr1.array[0] = "xoxAoxo";
    arr1.array[1] = "xoxAox";
    arr1.array[2] = "oxAox";

    printf("%s\n", str_maxlenoc(&arr1, 3)); // Output: "oxAox"

    /*
    string_array arr2;
    arr2.size = 4;
    arr2.array = (char**)malloc(4 * sizeof(char*));
    arr2.array[0] = "bonjour";
    arr2.array[1] = "salut";
    arr2.array[2] = "bonjour";
    arr2.array[3] = "bonjour";

    printf("%s\n", str_maxlenoc(&arr2, 4)); // Output: "u"

    free(arr2.array);
    */
    free(arr1.array);
    

    return 0;
}
