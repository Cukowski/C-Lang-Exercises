#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int sort_words(const void *a, const void *b)
{
    const char* string_1 = *(const char**)a;
    const char* string_2 = *(const char**)b;

    // Compare lengths first
    int cmp_len = strlen(string_1) - strlen(string_2);

    if (cmp_len != 0)
        return cmp_len;

     // Compare alphabetically
    while(*string_1 && *string_2)
    {
        char first = tolower(*string_1);
        char second = tolower(*string_2);

        if(first != second)
            return first - second;
        
        string_1++;
        string_2++;
    }
}

char* ord_alphlong(char* param_1)
{     
   if (param_1[0] == '\0') 
   {
        char* result = (char*)malloc(sizeof(char));
        result[0] = '\0';
        return result;
    }
  
    int len = strlen(param_1);
    char* temp = (char*)malloc((len + 1) * sizeof(char));
    strcpy(temp, param_1);

    int words_num = 1;

    // Count words
    while (*param_1) 
    {
        if (*param_1 == ' ')
            words_num++;
      param_1++;
    }

    // Split string and store words into array
    char** storage_words = (char**)malloc((words_num + 1) * sizeof(char*));
    char* word = strtok(temp, " \t");
    int i = 0;

    while (word != NULL) 
    {
        storage_words[i] = word;
        i++;
        word = strtok(NULL, " \t");
    }

    storage_words[words_num] = NULL; 

    qsort(storage_words, words_num, sizeof(char*), sort_words);

    // Store result
    char* result = (char*)malloc((len + 1) * sizeof(char));
    
    for (int index = 0; index < words_num; index++)
    {
       	strcat(result, storage_words[index]);
      
      	if(index < words_num - 1)
        {
          if (strlen(storage_words[index]) == strlen(storage_words[index + 1])) 
          {
              strcat(result, " ");
          } 
          else
          {
              strcat(result, "^");  
          }
      	}
    }

	free(storage_words);
  	free(temp);
    return result;
}
