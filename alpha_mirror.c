
char* alpha_mirror(char* abc)
{
 char *result = (char*) malloc(sizeof(char)*30);

for (int i = 0; i < strlen(abc); i++)
  {
    if (abc[i] >= 'A' && abc[i] <= 'Z')
    {
      // A = 65, Z = 90 25
      // B = 66, Y = 89 23
      // C = 67, X = 88 21
      // M = 77, N = 78 1
      // N = 78, M = 77 -1

      result[i] = abc[i] + 25 - (2 * (abc[i] - 65));
    }
    else if (abc[i] >= 'a' && abc[i] <= 'z')
    {
      // a = 97, z = 122 25
      // b = 98, y = 121 23
      // c = 99, x = 120 21
      // m = 109, n = 110 1
      // n = 110, m = 109

      result[i] = abc[i] + 25 - (2 * (abc[i] - 97));
    }
 	else
      result[i] = abc[i];
  }
  return result;
}


