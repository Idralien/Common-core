/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:24:14 by brsantsc          #+#    #+#             */
/*   Updated: 2024/07/16 15:35:49 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>


/*lay-out of the map*/
# define EMPTY_SPACE	'0'
# define WALL					'1'
# define COLLECTIBLE	'C'
# define EXIT					'E'
# define START				'P'

/*Keys to move the player*/
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_Z				122
# define KEY_Q				113

# define KEY_UP				65362
# define KEY_DOWN			65364
# define KEY_LEFT			65361
# define KEY_RIGHT		65363

/*Colours*/
# define BLACK 				"\033[0;30m"
# define RED					"\033[0;31m"
# define GREEN				"\033[0;32m"
# define YELLOW				"\033[0;33m"
# define BLUE					"\033[0;34m"
# define PURPLE				"\033[0;35m"
# define CYAN					"\033[0;36m"
# define WHITE				"\033[0;37m"
# define RESET				"\033[0m"

#endif
