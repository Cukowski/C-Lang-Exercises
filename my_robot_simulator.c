#include <stdlib.h>
#include <string.h>

void turn_right(char *direction); 
void turn_left(char *direction);

char* my_robot_simulator(char* param_1)
{
    int x = 0;
    int y = 0;
    char direction = 'U';
    char *final = (char*) malloc(sizeof(char)*30);

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

// north, east, south, or west)
    if (direction == 'D') 
    {
        sprintf(final, "south");
    }
    else if (direction == 'R')
    {
        sprintf(final, "east");
    }
    else if (direction == 'U')
    {
        sprintf(final, "north");
    }
    else if (direction == 'L')
    {
        sprintf(final, "west");
    }

    char *result = (char*) malloc(sizeof(char)*30);
    sprintf(result, "{x: %d, y: %d, bearing: '%s'}", x, y, final);
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