/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:03:14 by eraad             #+#    #+#             */
/*   Updated: 2025/01/06 11:03:14 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printaddr(unsigned long n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_printaddr(n / 16);
		count += ft_printaddr(n % 16);
	}
	else
		count += ft_putchar_fd(base[n], 1);
	return (count);
}

int	ft_putaddr(void *adress)
{
	if (!adress)
		return (ft_putstr_fd("(nil)", 1));
	ft_putstr_fd("0x", 1);
	return (2 + ft_printaddr((unsigned long)adress));
}
