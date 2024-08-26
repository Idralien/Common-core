#include "../../../includes/libft.h"

void    ft_free_2d_array(void *ptr)
{
	void    **arr;
	size_t  i;

	arr = (void**)ptr;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}