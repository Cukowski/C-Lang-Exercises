int my_isdigit(char param_1)
{
  
  	int a = param_1 - '0';
	if(a >= 0 && a <= 9)
    {
    return 1;
    } else 
    {
    return 0;
    }
}