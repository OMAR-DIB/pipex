/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:36:15 by odib              #+#    #+#             */
/*   Updated: 2024/06/20 10:56:50 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	ss1 = (unsigned char *)dest;
	ss2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ss1[i] = ss2[i];
		i++;
	}
	return (dest);
}
