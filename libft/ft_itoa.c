/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:00:06 by odib              #+#    #+#             */
/*   Updated: 2024/06/14 16:57:37 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	get_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*nb;
	int		len;

	len = get_len(n);
	sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		sign = -1;
	n = n * sign;
	nb = (char *)malloc((len + 1) * sizeof(char));
	if (!nb)
		return (NULL);
	nb[len--] = '\0';
	while (len >= 0)
	{
		nb[len--] = '0' + (n % 10);
		n = n / 10;
	}
	if (sign == -1)
		nb[0] = '-';
	return (nb);
}
