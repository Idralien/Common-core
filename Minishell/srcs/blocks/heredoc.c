/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:49:17 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/29 13:11:34 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Global variable used to track signal interrupts */
int	g_sin;

/* Writes a line of text to the specified file descriptor (fd).
 * Appends a newline character after writing the line. */
static void	write_to_file(char *line, int fd)
{
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
}

/* Signal handler for heredoc, sets g_sin to -3 on SIGINT. */
static void	sig_heredoc(int sig)
{
	(void)sig;
	g_sin = -3;
}

/* Sets up a signal handler for SIGINT and exits if g_sin is -3. */
static void	ft_signl(void)
{
	signal(SIGINT, sig_heredoc);
	if (g_sin == -3)
		exit(1);
}

/* Reads lines for the heredoc input, 
 * writing each line to the provided file descriptor.
 * Terminates when the line matches the delimiter. 
 * Handles signals during input.*/
void	ft_get_heredoc_lines(char *delim, int fd, t_data *g_data)
{
	char	*line;
	char	*prompt;

	line = NULL;
	while (1)
	{
		ft_signl();
		prompt = ft_strdup("> ");
		line = readline(prompt);
		if (line)
		{
			if (!ft_strcmp(line, delim))
				break ;
			else
				write_to_file(line, fd);
			free_string(prompt);
			free_string(line);
		}
		else
			ft_signal(3, g_data);
	}
	free_string(prompt);
	free_string(line);
	close(fd);
}

/* Handles creating a heredoc file input for a block.
 * Uses fork to handle the child process that reads heredoc input 
 * and writes it to a pipe.
 * The parent process waits for the child to finish. */
void	handle_heredoc_file(t_block *block, char *delim, t_data *g_data)
{
	int	pid;

	pipe(g_data->fd_heredoc);
	block->infile = g_data->fd_heredoc[0];
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	if (pid == 0)
	{
		close(g_data->fd_heredoc[0]);
		ft_get_heredoc_lines(delim, g_data->fd_heredoc[1], g_data);
		exit(0);
	}
	else
	{
		close(g_data->fd_heredoc[1]);
		waitpid(pid, &g_data->exit_status, 0);
		g_data->exit_status = g_data->exit_status / 256;
	}
}
