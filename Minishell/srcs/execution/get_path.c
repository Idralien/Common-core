/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:02:15 by brsantsc          #+#    #+#             */
/*   Updated: 2024/09/29 17:21:22 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Retrieves the value associated with a given key from 
 * the environment variables. If the key is found, 
 * it splits the value by ':' and returns it as an array of strings.
 * Returns NULL if the key is not found. */
static char	**ft_getenv(char **env, char *key)
{
	size_t	i;

	while (env && *env)
	{
		i = 0;
		while (*(*env + i) == key[i])
			i++;
		if (*(*env + i) == '=')
			return (ft_split(*env + i + 1, ':'));
		env++;
	}
	return (NULL);
}

/* Joins a given path and file name into a single string.
*  Allocates memory for the new string and returns it.
*  The format will be "path/file". */
static char	*join_path(char *path, char *file)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new = malloc(ft_strlen(path) + ft_strlen(file) + 2);
	if (!new)
		return (NULL);
	while (path[i])
	{
		new[i] = path[i];
		i++;
	}
	new[i++] = '/';
	while (file[j])
	{
		new[i + j] = file[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

/* Resolves the full path of a given file by searching through 
 * the PATH environment variable.
*  If the file is executable, returns its path; otherwise, returns NULL. */
static char	*resolve_path(char *file, char **env)
{
	char	**paths;
	char	*output;
	size_t	i;

	if (!file || !env)
		return (NULL);
	if (access(file, X_OK) >= 0)
		return (ft_strdup(file));
	paths = ft_getenv(env, "PATH");
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		output = join_path(paths[i], file);
		if (access(output, X_OK) >= 0)
			break ;
		free(output);
		output = NULL;
		free(paths[i++]);
	}
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (output);
}

/* Gets the resolved path for the command in the block.
*  Stores the path in the provided pointer and handles errors. */
int	ft_get_path(t_block *block, char **path, t_data	*g_data)
{
	*path = resolve_path(block->cmd_name, g_data->env);
	if (!(*path) && ft_error('u', block) == 1)
	{
		if (block->outfile > 1)
			close(block->outfile);
		if (block->infile > 0)
			close(block->infile);
		g_data->exit_status = 127;
		free(*path);
		return (-1);
	}
	return (1);
}
