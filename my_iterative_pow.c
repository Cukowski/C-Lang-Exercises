int my_iterative_pow(int param_1, int param_2)
{
	int number = 1;
  
  for(int i = 0; i < param_2; i++){
  number *= param_1;
  }
  return number;
}
