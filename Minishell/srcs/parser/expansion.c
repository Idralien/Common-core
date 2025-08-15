/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:44:57 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/29 18:18:19 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Trims the line until a special character
   is encountered and returns the substring. */
static char	*trim_env(char *line, int *k)
{
	int		j;
	char	*env;

	j = 0;
	while (line[j] && line[j] != ' ' && line[j] != '"' && line[j] != '\''
		&& line[j] != '$')
		j++;
	env = (char *)malloc(sizeof(char) * (j + 1));
	j = 0;
	while (line[j] && line[j] != ' ' && line[j] != '"' && line[j] != '\''
		&& line[j] != '$')
	{
		env[j] = line[j];
		j++;
		if (line[0] == '?')
			break ;
	}
	env[j] = '\0';
	*k += j;
	return (env);
}

/* Retrieves environment variable value from a substring. */
static char	*ft_get_env(char *substr, int *indx, t_data *g_data)
{
	char	*env;
	char	*temp;

	temp = trim_env(substr + 1, indx);
	*indx += 1;
	if (temp[0] == '?')
	{
		env = ft_itoa(g_data->exit_status);
		free_string(temp);
		return (env);
	}
	env = ft_search_env(temp, g_data);
	free_string(temp);
	return (env);
}

/* Finds the total length of the line after expanding env variables. */
static int	find_len(char *line, t_data *g_data)
{
	int		i;
	int		len;
	char	*env;

	i = 0;
	len = 0;
	while (line[i] != '\0')
	{
		if (i_x(line[i], line[i + 1]) && !is_in_single_quote(line, i))
		{
			env = ft_get_env(line + i, &i, g_data);
			if (!env)
				continue ;
			len += ft_strlen(env);
			free_string(env);
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

/* Copies the line and expands any env variables found. */
static char	*ft_copier(char *line, int j, int k, t_data *g_data)
{
	int		len;
	char	*str;
	char	*env;

	len = find_len(line, g_data);
	str = (char *)ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	while (line[j])
	{
		if (i_x(line[j], line[j + 1]) && !is_in_single_quote(line, j))
		{
			env = ft_get_env(line + j, &j, g_data);
			if (env)
				str = ft_strjoin(str, env, len);
			k += ft_strlen(env);
			free_string(env);
		}
		else
		{
			str[k] = line[j++];
			str[++k] = '\0';
		}
	}
	return (str);
}

/* Expands all env variables found in the given lines. */
t_expand	*ft_expander(char **line, int i, int j, t_data *g_data)
{
	t_expand	*exp;
	char		*str;
	char		*indx;
	int			k;

	exp = NULL;
	while (line[i])
	{
		indx = ft_strchr(line[i], '$');
		j = 0;
		k = 0;
		if (!indx)
			exp = ft_add_tail_expander(exp, line[i]);
		else
		{
			str = ft_copier(line[i], j, k, g_data);
			exp = ft_add_tail_expander(exp, str);
			free_string(str);
		}
		i++;
	}
	return (exp);
}
