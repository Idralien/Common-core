int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (c);
	else
		return (0);
}
