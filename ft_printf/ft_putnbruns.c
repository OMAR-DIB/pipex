/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbruns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:16:04 by odib              #+#    #+#             */
/*   Updated: 2024/06/22 11:11:36 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbruns(unsigned int nb, unsigned int *len)
{
	if (nb > 9)
	{
		ft_putnbruns(nb / 10, len);
		ft_putnbruns(nb % 10, len);
	}
	else
		*len += ft_putchar(nb + '0');
}

unsigned int	return_nruns(unsigned int nb)
{
	unsigned int	len;

	len = 0;
	ft_putnbruns(nb, &len);
	return (len);
}
