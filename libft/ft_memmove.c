/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:08:20 by odib              #+#    #+#             */
/*   Updated: 2024/06/20 10:27:51 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*s;
	size_t			i;

	if (!dest && !src)
		return (dest);
	dst = (unsigned char *)dest;
	s = (unsigned char *) src;
	i = 0;
	if (dst < s)
	{
		while (i < n)
		{
			dst[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			dst[n] = s[n];
	}
	return (dst);
}
