static char	**free_split(char **str, int i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
	return (0);
}


char	**ft_split(char const *s, char c)
{
}
