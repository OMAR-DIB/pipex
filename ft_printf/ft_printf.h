/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:27:30 by odib              #+#    #+#             */
/*   Updated: 2024/06/22 11:10:52 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_printf(const char *form, ...);
int				ft_putstr(char *str);
int				ft_putchar(char c);
void			ft_putnbr(int nb, int *len);
void			ft_putnbrhexa(unsigned int nb, char c, int *len);
void			ft_putnbruns(unsigned int nb, unsigned int *len);
int				ft_putpointer(void *pointer);
void			ptrrecursion(unsigned long long num, int *len);
int				return_nr(int nb);
int				return_nrhexa(int nb, char c);
unsigned int	return_nruns(unsigned int nb);

#endif