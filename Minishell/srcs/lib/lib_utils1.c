/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 22:14:09 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/26 22:27:28 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_isdigit(int c)
{
	if ((c <= '9' && c >= '0'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t			i;
	unsigned int	res;
	int				sign;
	size_t			sign_nbr;

	i = 0;
	res = 0;
	sign = 1;
	sign_nbr = 0;
	while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 14)))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		sign_nbr++;
		i++;
	}
	if (sign_nbr > 1)
		return (0);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - 48);
	if (sign_nbr == 1 && sign == -1)
		return (-res);
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	c;
	size_t	f;

	f = 0;
	c = start;
	if (s == 0)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	while (f < len && s[f + start] != '\0')
		f++;
	str = malloc((f + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < len && s[c] != '\0')
		str[i++] = s[c++];
	str[i] = '\0';
	return (str);
}
