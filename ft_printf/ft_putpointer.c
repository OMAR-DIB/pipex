/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:22:56 by odib              #+#    #+#             */
/*   Updated: 2024/06/22 10:09:04 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptrrecursion(unsigned long long num, int *len)
{
	if (num >= 16)
	{
		ptrrecursion(num / 16, len);
		ptrrecursion(num % 16, len);
	}
	else
	{
		if (num <= 9)
			*len += ft_putchar(num + '0');
		else
			*len += ft_putchar(num - 10 + 'a');
	}
}

int	ft_putpointer(void *pointer)
{
	int					len;
	unsigned long long	num;

	num = (unsigned long long)pointer;
	len = 0;
	if (num == 0)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	ptrrecursion(num, &len);
	return (len);
}
