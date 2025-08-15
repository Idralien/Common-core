/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:22:15 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/26 21:22:38 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_env
{
	char			*front;
	char			*back;
	struct s_env	*next;
}					t_env;

typedef struct s_expand
{
	char				*str;
	struct s_expand		*next;
}	t_expand;

typedef struct s_data
{
	t_env		*environmental;
	t_expand	*exp;
	int			exit_status;
	char		**env;
	int			**fd_pipe;
	int			fd_heredoc[2];
	int			block_cnt;
	char		*default_prompt;
}				t_data;

typedef struct s_block
{
	char	*cmd_name;
	char	**args;
	int		infile;
	int		outfile;
}	t_block;

#endif
