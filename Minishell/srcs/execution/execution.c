/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:43:40 by brsantsc          #+#    #+#             */
/*   Updated: 2024/09/29 17:05:29 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Checks if the provided command string matches any built-in commands.
*  Returns 1 if the command is built-in, 0 otherwise. */
static int	ft_is_built_in(char *str)
{
	if (ft_strcmp(str, "echo") == 0)
		return (1);
	if (ft_strcmp(str, "cd") == 0)
		return (1);
	if (ft_strcmp(str, "pwd") == 0)
		return (1);
	if (ft_strcmp(str, "export") == 0)
		return (1);
	if (ft_strcmp(str, "unset") == 0)
		return (1);
	if (ft_strcmp(str, "env") == 0)
		return (1);
	if (ft_strcmp(str, "exit") == 0)
		return (1);
	return (0);
}

/* Duplicates the file descriptors for input and output redirection.
*  Closes the original file descriptors after duplication. */
static void	ft_dup_fds(t_block *block, t_data *g_data)
{
	int	i;

	i = 0;
	if (block->infile > 0)
	{
		dup2(block->infile, 0);
		close(block->infile);
	}
	if (block->outfile > 1)
	{
		dup2(block->outfile, 1);
		close(block->outfile);
	}
	while (i < g_data->block_cnt)
	{
		close(g_data->fd_pipe[i][0]);
		close(g_data->fd_pipe[i][1]);
		i++;
	}
}

/* Executes the built-in commands by redirecting input and output as needed.
*  Updates the global exit status in the g_data structure. */
static void	ft_execute_builtin(t_block *block, int tmp_in, int tmp_out,
		t_data *g_data)
{
	tmp_in = dup(0);
	tmp_out = dup(1);
	ft_dup_fds(block, g_data);
	if (ft_strcmp(block->cmd_name, "echo") == 0)
		g_data->exit_status = ft_echo(block);
	if (ft_strcmp(block->cmd_name, "cd") == 0)
		g_data->exit_status = ft_cd(block, g_data);
	if (ft_strcmp(block->cmd_name, "pwd") == 0)
		g_data->exit_status = ft_pwd();
	if (ft_strcmp(block->cmd_name, "export") == 0)
		g_data->exit_status = ft_export(block, g_data);
	if (ft_strcmp(block->cmd_name, "unset") == 0)
		g_data->exit_status = ft_unset(block, g_data);
	if (ft_strcmp(block->cmd_name, "env") == 0)
		g_data->exit_status = ft_env(g_data);
	if (ft_strcmp(block->cmd_name, "exit") == 0)
	{
		ft_putstr_fd("exit\n", 1);
		ft_exit_b(block, g_data);
	}
	dup2(tmp_in, 0);
	dup2(tmp_out, 1);
	close(tmp_in);
	close(tmp_out);
}

/* Handles built-in commands, executing them in a child process if necessary.
*  Manages file descriptor duplication and process creation for built-ins. */
static int	ft_handle_builtin(t_block *block, t_data *g_data)
{
	int	pid;
	int	tmp_in;
	int	tmp_out;

	tmp_in = 0;
	tmp_out = 1;
	if (g_data->block_cnt > 1)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_execute_builtin(block, tmp_in, tmp_out, g_data);
			exit(127);
		}
		if (block->outfile > 1)
			close(block->outfile);
		if (block->infile > 0)
			close(block->infile);
		waitpid(pid, &g_data->exit_status, 0);
	}
	else
		ft_execute_builtin(block, tmp_in, tmp_out, g_data);
	return (1);
}

/* Executes a command by checking if it is built-in or an external command.
*  Handles process creation and file descriptor management for both types. */
int	exec_ft(t_block *block, int indx, t_data *g_data)
{
	char	*path;
	int		pid;

	if (ft_is_built_in(block->cmd_name))
		return (ft_handle_builtin(block, g_data));
	if (ft_get_path(block, &path, g_data) == -1)
		return (-1);
	pid = fork();
	if (pid == 0)
	{
		ft_dup_fds(block, g_data);
		execve(path, block->args, g_data->env);
		ft_error('d', block);
		exit(g_data->exit_status);
	}
	if (block->outfile > 1)
		close(block->outfile);
	if (block->infile > 0)
		close(block->infile);
	if (indx > 0)
		close(g_data->fd_pipe[indx - 1][1]);
	waitpid(pid, &g_data->exit_status, 0);
	g_data->exit_status /= 256;
	free(path);
	return (1);
}
