void	*ft_calloc(size_t counter, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(counter * size);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr,counter);
	return (ptr);
}
