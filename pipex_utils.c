/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:58:32 by odib              #+#    #+#             */
/*   Updated: 2024/07/11 18:14:51 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

int	open_files(char *file, int flag)
{
	int	fd;

	fd = open(file, flag, 0644);
	if (fd == -1)
	{
		ft_printf("open error");
		return (EXIT_FAILURE);
	}
	return (fd);
}

void	get_access(char *check, int flag)
{
	if (access(check, flag) == -1)
		perror_exit("access error");
}

void	parent_process(char *cmd_arg, char *file_name, int pipedf[])
{
	char	**cmd;
	int		fd;
	char	*c;

	close(pipedf[1]);
	dup2(pipedf[0], 0);
	waitpid(-1, NULL, 0);
	cmd = ft_split(cmd_arg, ' ');
	if (!cmd)
		exit(EXIT_FAILURE);
	fd = open_files(file_name, O_CREAT | O_RDWR | O_TRUNC);
	close(1);
	dup2(fd, 1);
	c = ft_strjoin("/bin/", cmd[0]);
	get_access(c, X_OK);
	if (execve(c, cmd, NULL) == -1)
		perror_exit("execve error");
	free(c);
	free(cmd);
}

void	child_process(char *cmd_arg, char *file_name, int pipedf[])
{
	char	**cmd;
	int		fd;
	char	*c;

	cmd = ft_split(cmd_arg, ' ');
	if (!cmd)
		exit(EXIT_FAILURE);
	get_access(file_name, R_OK | F_OK);
	fd = open_files(file_name, O_RDONLY);
	close(pipedf[0]);
	dup2(fd, 0);
	dup2(pipedf[1], 1);
	c = ft_strjoin("/bin/", cmd[0]);
	get_access(c, X_OK);
	if (execve(c, cmd, NULL) == -1)
		perror_exit("execve error");
	free(c);
	free(cmd);
	close(fd);
}
