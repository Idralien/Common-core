int	ft_tolower(int c)
{
	int	lower;

	if (c >= 'A' && c <= 'Z')
		lower = c + 32;
	return (lower);
}
