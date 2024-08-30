# included "../../includes/minishell.h"

/* print error message with exit */
void    handle_ctl_d_error(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("exit\n", STDERR_FILENO);
}

int handle_ctl_d(char *prompt)
{
	int     len;
	char    *shift;
	char    *shift_len;

	len = ft_strlen(prompt);
	free(prompt);
	shift_len = ft_itoa(len);
	if (!shift_len)
		return (MALLOC_ERR);
	len = ft_strlen(shift_len) + 4;
	shift = ft_calloc(len, sizeof(char));
	if (!shift)
	{
		free(shift_len);
		return (MALLOC_ERR);
	}
	ft_strlcat(shift, "\033[", len);
	ft_strlcat(shift, shift_len, len);
	free(shift_len);
	ft_strlcat(shift, "C", len);
	printf("\033[1A]");
	printf("%s", shift);
	free(shift);
	printf("exit\n");
	return (SUCCESS);
}