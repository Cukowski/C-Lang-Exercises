#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char ** argv) {

    int fd;   // file descriptor
    int ch;  
    
    for (int i=1; i<argc; i++){
        fd =  open(argv[i], O_RDONLY);  // Open for reading only. (SUPPORTED BY fcntl.h)
        
        while(read(fd, &ch, 1 == 1))
        {
            write(STDOUT_FILENO, &ch,1);  // Write supported by stdio.h
        }  
    close(fd);   // don't forget to close.
    }
}