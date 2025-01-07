/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:58:26 by eraad             #+#    #+#             */
/*   Updated: 2025/01/06 12:58:26 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(const char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'p')
		return (ft_putaddr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthexa_tolower(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_puthexa_toupper(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		temp;
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	i = 0;
	temp = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			temp = ft_format(format[++i], args);
		else
			temp = ft_putchar_fd(format[i], 1);
		if (temp >= 0)
			count += temp;
		else
			count = -1;
		i++;
	}
	va_end(args);
	return (count);
}
