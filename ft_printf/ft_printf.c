/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:28:39 by odib              #+#    #+#             */
/*   Updated: 2024/06/27 10:27:59 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	check_content(char c, va_list args)
{
	int		len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len += return_nr(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		len += return_nrhexa(va_arg(args, unsigned int), c);
	else if (c == 'u')
		len += return_nruns(va_arg(args, unsigned int));
	else if (c == 'p')
		len += ft_putpointer(va_arg(args, void *));
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *form, ...)
{
	int		len;
	int		i;
	va_list	args;

	va_start (args, form);
	i = 0;
	len = 0;
	while (form[i])
	{
		if (form[i] == '%' && form[i + 1])
		{
			len += check_content(form[i + 1], args);
			i++;
		}
		else
			len += write(1, &form[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
