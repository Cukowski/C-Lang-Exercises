int is_power_of_(unsigned int param_1)
{
  	if(param_1 <= 1) // 1 is power of 2 but gandalf does not accept
      	return 0;
  
	while (param_1 > 1)
    {
    	if(param_1 % 2 != 0)
        	return 0;
      	param_1 /= 2;
    }
  	return 1;
}