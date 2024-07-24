int my_strlen(char *str);

int hidenp(char* param_1, char* param_2)
{
	int len1 = my_strlen(param_1);
	int i, j = 0;
	for (i, j; i < param_2[i] && j < param_1[j]; i++)
		if (param_2[i] == param_1[j])
			j++;

	if (j == len1) return 1; // return(j == len1);
	else return 0;			
}

int my_strlen(char *str){int len = 0; while(str[len] != 0) len++; return len;}