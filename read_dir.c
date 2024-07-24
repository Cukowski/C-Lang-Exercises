#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char * argv[])
{
    DIR* dir = opendir(".");

    if (dir ==NULL) {
        return 1;
    }

    struct dirent* entity;
    entity = readdir(dir);

   
    int i = 0;

    while (entity != NULL) {
        printf("%s %d \n", entity->d_name, i);
        entity = readdir(dir);
        i++;
    }

    closedir(dir);
    return 0;
}