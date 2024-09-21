/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:05:12 by odib              #+#    #+#             */
/*   Updated: 2024/07/11 18:14:48 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

void	perror_exit(const char *msg);
int		open_files(char *file, int flag);
void	get_access(char *check, int flag);
void	parent_process(char *cmd_arg, char *file_name, int pipedf[]);
void	child_process(char *cmd_arg, char *file_name, int pipedf[]);
#endif