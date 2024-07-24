char * my_strndup(char * param_1, size_t n) 
{
    if (param_1 == NULL) return NULL;
    
    size_t len = my_strlen(param_1);
    
    if (n > len) return NULL;
    
    char* dup = (char*)malloc((n + 1) * sizeof(char));
    
    if (dup == NULL) return NULL;
    
    my_strncpy(dup, param_1, n);
    
    dup[n] = '\0';
    
    return dup;
}