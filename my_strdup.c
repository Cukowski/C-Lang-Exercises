char * my_strdup(char* param_1) 
{
    if (param_1 == NULL) return NULL;    
    
    size_t length = my_strlen(param_1);
    
    char* duplicate = (char*)malloc((length + 1) * sizeof(char));
    
    if (duplicate == NULL) return NULL;

    my_strcpy(duplicate, param_1);
    
    return duplicate;
}