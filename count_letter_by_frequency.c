#include <stdio.h>
#include <string.h>

char* count_letter(char* param_1)
{
  int fre[26]; // int array, a number of accurance for each character.
  
  int len = strlen(param_1);

  for (int i = 0; i < 26; i++)
  {
    fre[i] = 0;
  }

  for(int i = 0; i < len; i++){
    if(param_1[i] <= 'z' && param_1[i] >= 'a'){
      fre[param_1[i] - 97]++;
    }
    else if(param_1[i] <= 'Z' && param_1[i] >= 'A'){
      fre[param_1[i] - 65]++;
    }
    
  }
  
  for(int i = 0; i < 26; i++)
  {
    if (fre[i] != 0)
    {
      printf("%d%c, ", fre[i] , i+97);
    }
    
  }
  
}

int main(){
  
//   count_letter("abbcc");

   count_letter("My Hyze 47y 7.");
  
  return 0;
}