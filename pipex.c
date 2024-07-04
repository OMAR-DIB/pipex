/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:54:23 by odib              #+#    #+#             */
/*   Updated: 2024/07/04 18:31:40 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//void	check_arg(int ac)
//{
//	if (ac != 5)
//	{
//		ft_ft_printf("argument ERROR!");
//		exit(1);
//	}
//}
int main(int ac, char *av[])
{
    if(ac != 5)
    {
        ft_printf("error");
        exit(1);
    }
    int pipedf[2];
    __pid_t pid;
    char **cmd;
    int fd;
    if(pipe(pipedf) == -1)
    {
        ft_printf("error pipe");
        exit(1);
    }
    pid = fork();
    if(pid == -1)
    {
        ft_printf("error fork");
        exit(1);
    }
    if(pid)
    {
        close(0);
        close(pipedf[1]);
        dup2(pipedf[0],0);
        waitpid(pid, NULL, 0);
        cmd = ft_split(av[3],' ');
        if(!cmd)
            return(EXIT_FAILURE);
        fd = open(av[4],O_CREAT | O_RDWR | O_TRUNC, 0777);
        if (fd == -1)
        {
            ft_printf("open error");
            return (EXIT_FAILURE);
        }
        close(1);
        dup2(fd,1);
        char *c = ft_strjoin("/bin/",cmd[0]);
        
        if(execve(c,cmd,NULL) == -1)
            return EXIT_FAILURE;
        free(cmd);
        return (EXIT_SUCCESS);
    }
    cmd = ft_split(av[2],' ');
    if(!cmd)
        return(EXIT_FAILURE);
    fd = open(av[1],O_RDONLY);
    if (fd == -1)
    {
        ft_printf("open error");
        return (EXIT_FAILURE);
    }
    close(0);
    close(1);
    dup(fd);
    close(pipedf[0]);
    dup2(pipedf[1],1);
    char *c = ft_strjoin("/bin/",cmd[0]);
    
    if(execve(c,cmd,NULL) == -1)
        return EXIT_FAILURE;
    free(cmd);
    close(fd);
    return (EXIT_SUCCESS);
}

