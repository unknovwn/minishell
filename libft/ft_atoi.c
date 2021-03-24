int		ft_atoi(char *num)
{
	int		result;
	int		sign;
	int		i;

	i = 0;
	if ((sign = (*num == '-')))
		i++;
	result = 0;
	while (num[i])
	{
		result *= 10;
		result += (num[i++] - '0');
	}
	if (sign)
		result = -result;
	return (result);
}
