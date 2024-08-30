/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_redirects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:23:18 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/26 11:23:22 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int prepare_heredocs(char ***redirs, int *hd_num, t_minishell *minish);
static char *get_hd_name(int *hd_num);
static void rm_hd_files(int *hd_num);

int prepare_redirects(char *redirects_line, int *hd_num, char ***redirs,
					  t_minishell *minish)
{
	int status;

	if (redirects_line == NULL)
	{
		*redirs = NULL;
		return (SUCCESS);
	}
	*redirs = ft_split(redirects_line, SEPERATOR);
	free(redirects_line);
	if (!*redirs)
		return (MALLOC_ERR);
	status = prepare_heredocs(redirs, hd_num, minish);
	if (status != SUCCESS)
	{
		ft_free_2d_array(*redirs);
		rm_hd_files(hd_num);
	}
	if (status == SIGINT + 128)
		status = 1;
	return (status);
}

static int prepare_heredocs(char ***redirs, int *hd_num, t_minishell *minish)
{
	int     i;
	int     hd_counter;
	int     status;
	char    *hd_name;

	hd_name = get_hd_name(hd_num);
	if (!hd_name)
		return (MALLOC_ERR);
	i = 0;
	hd_counter = 0;
	status = 0;
	while ((*redirs)[i] && status == 0)
	{
		if (ft_strncmp("<<", (*redirs)[i], 2) == 0)
		{
			hd_counter++;
			status = prepare_heredoc(*redirs + i, hd_name, minish);
		}
		i++;
	}
	if (hd_counter > 0)
		(*hd_num)++;
	remove_hd_dups(redirs, hd_name, hd_counter);
	return (status);
}

static char *get_hd_name(int *hd_num)
{
	char *filename;
	char *num;

	num = ft_itoa(*hd_num);
	if (!num)
		return (NULL);
	filename = ft_strjoin(HEREDOC_NAME, num);
	free(num);
	return (filename);
}

// bro create the print_err_msg function tmrw
// create unlink....
static void rm_hd_files(int *hd_num)
{
	char    *file_name;
	char    *num;
	int     i;

	i = -1;
	while (++i < *hd_num)
	{
		num = ft_itoa(i);
		if (!num)
		{
			print_err_msg("unlink", ": malloc error occured");
			continue;
		}
		file_name = ft_strjoin(&(HEREDOC_NAME[2]), num);
		free(num);
		if (!file_name)
		{
			print_err_msg("unlink", ": malloc error occured");
			continue;
		}
		if (unlink(file_name) != 0)
			perror_err_msg("unlink: ", file_name);
		free(file_name);
	}
}
