int	ft_toupper(int c)
{
	int	upper;

	if (c >= 'a' && c <= 'z')
		upper = c - 32;
	return (upper);
}
