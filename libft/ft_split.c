/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:18:53 by odib              #+#    #+#             */
/*   Updated: 2024/06/14 16:15:16 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//size_t	count_tokens(char const *s, char limit)
//{
//	size_t	token;
//	int		tru;
//	int		i;

//	i = 0;
//	tru = 1;
//	token = 0;
//	while (*s)
//	{
//		tru = 0;
//		while (s[i] == limit && s[i] != '\0')
//			i++;
//		while (s[i] != limit && s[i] != '\0')
//		{
//			if (tru == 0)
//			{
//				token++;
//				tru = 1;
//			}
//			i++;
//		}
//	}
//	return (token);
//}

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
