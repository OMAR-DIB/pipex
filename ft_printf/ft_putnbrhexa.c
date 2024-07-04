/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:14:27 by odib              #+#    #+#             */
/*   Updated: 2024/06/22 10:13:31 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrhexa(unsigned int nb, char c, int *len)
{
	char	*hexa;

	if (c == 'X')
		hexa = "0123456789ABCDEF";
	else if (c == 'x')
		hexa = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_putnbrhexa (nb / 16, c, len);
		ft_putnbrhexa (nb % 16, c, len);
	}
	else
		*len += ft_putchar(hexa[nb]);
}

int	return_nrhexa(int nb, char c)
{
	int	len;

	len = 0;
	ft_putnbrhexa(nb, c, &len);
	return (len);
}
