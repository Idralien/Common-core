void	*ft_memset(void *s, int c, size_t n)
{
	char	*buffer;

	if (!s)
		return (NULL);
	while (n > 0)
	{
		*buffer = c;
		buffer++;
		n--;
	}
	return (s);
}
