#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void turn_right(char *direction); 
void turn_left(char *direction);

char* my_spaceship(char* param_1)
{
    // up = U
    // down = D
    // left = L
    // right = R

    int x = 0;
    int y = 0;
    char direction = 'U';
    char *final = (char*) malloc(sizeof(char)*30);
    // char final[30];

    int index = 0;

    while (index < strlen(param_1))
    {
        if (param_1[index] == 'A') // FIX IT!
        {
            if (direction == 'U')
            {
                y--;
            }
            else if (direction == 'L')
            {
                x--;
            }
            else if (direction == 'D')
            {
                y++;
            }
            else if (direction == 'R')
            {
                x++;
            }
        }
        else if (param_1[index] == 'R')
        {
            turn_right(&direction);
        }
        else if (param_1[index] == 'L')
        {
            turn_left(&direction);
        }
        index++;
    }

    if (direction == 'D') 
    {
        sprintf(final, "down");
    }else if (direction == 'R')
    {
        sprintf(final, "right");
    }else if (direction == 'U')
    {
        sprintf(final, "up");
    }else if (direction == 'L')
    {
        sprintf(final, "left");
    }

    // printf("x: %d, y: %d, direction: '%s'", x, y, final);
    char *result = (char*) malloc(sizeof(char)*30);
    sprintf(result, "{x: %d, y: %d, direction: '%s'}", x, y, final);
    return result;
}

void turn_right(char *direction)
{

    if (*direction == 'U')
    {
        *direction = 'R';
    }
    else if (*direction == 'L')
    {
        *direction = 'U';
    }
    else if (*direction == 'D')
    {
        *direction = 'L';
    }
    else if (*direction == 'R')
    {
        *direction = 'D';
    }
}
void turn_left(char *direction)
{
    
    if (*direction == 'U')
    {
        *direction = 'L';
    }
    else if (*direction == 'L')
    {
        *direction = 'D';
    }
    else if (*direction == 'D')
    {
        *direction = 'R';
    }
    else if (*direction == 'R')
    {
        *direction = 'U';
    }
}

// int main()
// {
//     char param_1[] = "RAALALL";
//     my_spaceship(param_1);
// }
