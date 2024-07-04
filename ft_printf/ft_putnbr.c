/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:13:21 by odib              #+#    #+#             */
/*   Updated: 2024/06/22 10:14:59 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *len)
{
	if (nb == -2147483648)
	{
		*len += (write(1, "-2147483648", 11));
	}
	else if (nb < 0)
	{
		*len += ft_putchar('-');
		nb *= -1;
		ft_putnbr(nb, len);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
	else
		*len += ft_putchar(nb + '0');
}

int	return_nr(int nb)
{
	int	len;

	len = 0;
	ft_putnbr(nb, &len);
	return (len);
}
