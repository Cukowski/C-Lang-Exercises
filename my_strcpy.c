char* my_strcpy(char* param_1, char* param_2)
{
    int i = 0;
    int len = strlen(param_2);

    while (i < len) 
    {
        param_1[i] = param_2[i];
        i++;
    }

    return param_1;
}

char* my_strcpy(char* param_1, char* param_2)
{
    for (int i = 0; i < my_strlen(param_2); i++)
        param_1[i] = param_2[i];
    return param_1;
}