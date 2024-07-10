#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strdup(const char *s)
{
	char	*arr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		i++;
	}
	arr = malloc(sizeof(char) * (i + 1));
	if (arr == NULL)
		return (NULL);
	while (j < i)
	{
		arr[j] = s[j];
		j++;
	}
	arr[j] = '\0';
	return (arr);
}
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n)
	{
		*p = 0;
		p++;
		n--;
	}
}
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	if ((int)nmemb < 0 && (int)size < 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	j;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	arr = ft_calloc(len + 1, sizeof(char));
	if (!arr)
		return (NULL);
	j = start;
	while (j - start < len)
	{
		arr[j - start] = s[j];
		j++;
	}
	return (arr);
}
char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	ch = c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == '\0' && s[i] == c)
		return ((char *)s + i);
	return (NULL);
}
size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**lst;
	size_t	word_len;

	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	arr = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (arr == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		arr[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		arr[i] = s2[j];
		i++;
		j++;
	}
	arr[i] = '\0';
	return (arr);
}

int open_files(char *file, int flag)
{
	int fd;

	fd = open(file, flag, 0644);
	if (fd == -1)
    {
        printf("open error");
        return (EXIT_FAILURE);
    }
	return (fd);
}

void get_access(char *check,int flag)
{
	if (access(check, flag) == -1)
    {
        perror("exec error");
        exit(EXIT_FAILURE);
    }
}

void parent_process(char *cmd_arg, char *file_name, int pipedf[])
{
    char **cmd;
    int fd;

    close(pipedf[1]);
    dup2(pipedf[0], 0);
    waitpid(-1, NULL, 0);
    cmd = ft_split(cmd_arg, ' ');
    if (!cmd)
        exit(EXIT_FAILURE);
	get_access(file_name,F_OK);
    fd = open_files(file_name, O_CREAT | O_RDWR | O_TRUNC);
    close(1);
    dup2(fd, 1);
    char *c = ft_strjoin("/bin/", cmd[0]);
    get_access(c,X_OK);
    if (execve(c, cmd, NULL) == -1)
    {
        perror("execve error");
        exit(EXIT_FAILURE);
    }
    free(c);
    free(cmd);
}

void child_process(char *cmd_arg, char *file_name, int pipedf[])
{
    char **cmd;
    int fd;

    cmd = ft_split(cmd_arg, ' ');
    if (!cmd)
        exit(EXIT_FAILURE);
    get_access(file_name,R_OK);
    fd = open_files(file_name, O_RDONLY);
    close(pipedf[0]);
    dup2(fd, 0);
    dup2(pipedf[1], 1);
    char *c = ft_strjoin("/bin/", cmd[0]);
    get_access(c,X_OK);
    if (execve(c, cmd, NULL) == -1)
    {
        perror("execve error");
        exit(EXIT_FAILURE);
    }
    free(c);
    free(cmd);
    close(fd);
}

int main(int ac, char *av[])
{
    if (ac != 5)
    {
        printf("error\n");
        exit(1);
    }

    int pipedf[2];
    __pid_t pid;

    if (pipe(pipedf) == -1)
    {
        perror("pipe error");
        exit(1);
    }
    pid = fork();
    if (pid == -1)
    {
        perror("fork error");
        exit(1);
    }
    if (pid)
        parent_process(av[3], av[4], pipedf);
    else
        child_process(av[2], av[1], pipedf);
    return 0;
}
