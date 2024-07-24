char* rotone(char* param_1)
{
  	int len = strlen(param_1);

  for(int i = 0; i < len; i++)
    {
		if((param_1[i] < 90 && param_1[i] >= 65) || (param_1[i] < 122 && param_1[i] >= 97))
          param_1[i]++;
      	else if(param_1[i] == 90 || param_1[i] == 122)
          param_1[i] -= 25;
    }
  return param_1;
}
