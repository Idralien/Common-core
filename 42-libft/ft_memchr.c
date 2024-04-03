void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t	i;

	i = 0;
	str = s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}
