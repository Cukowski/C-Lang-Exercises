

int jewels_and_stones(char* param_1, char* param_2)
{
	int len1 = strlen(param_1);
	int len2 = strlen(param_2);

    int count = 0;

    for (int i = 0; i < len2; i++)
    {
        for (int j = 0; j < len1; j++) 
        {
            if (param_2[i] == param_1[j]) 
            {
                count++;
                break; // Move to the next character in S
            }
        }
    }
    return count;
}

/*
Example 1:

**Input:** J = "aA", S = "aAAbbbb"

**Output:** 3
Example 2:

**Input:** J = "z", S = "ZZ"

**Output:** 0
*/