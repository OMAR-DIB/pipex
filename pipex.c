/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:54:23 by odib              #+#    #+#             */
/*   Updated: 2024/07/11 18:13:14 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[])
{
	int		pipedf[2];
	__pid_t	pid;

	if (ac != 5)
	{
		ft_putendl_fd("argument error\nex :./pipex file1 \"cmd1\" \"cmd2\" file2",1);
		exit(1);
	}
	if (pipe(pipedf) == -1)
		perror_exit("pipe error");
	pid = fork();
	if (pid == -1)
		perror_exit("fork error");
	if (pid)
		parent_process(av[3], av[4], pipedf);
	else
		child_process(av[2], av[1], pipedf);
	return (0);
}
