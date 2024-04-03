char	*strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	if (s[i] == (char)c)
		return ((char)s[i]);
	else
		return (0);
}
