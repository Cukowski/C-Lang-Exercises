char *my_strncat(char *dest, const char *src, size_t n) {
    char *dest_end = dest + strlen(dest); // Find the end of the destination string
    
    while (*src != '\0' && n > 0) {
        *dest_end++ = *src++; // Copy characters from src to dest
        n--;
    }
    
    *dest_end = '\0'; // Null-terminate the concatenated string
    
    return dest;
}