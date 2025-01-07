/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:44:38 by eraad             #+#    #+#             */
/*   Updated: 2024/12/03 15:44:38 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;
	int			count;

	if (fd < 0)
		return (-1);
	count = 0;
	nbr = n;
	if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr / 10)
		count += ft_putnbr_fd(nbr / 10, fd);
	count += ft_putchar_fd((nbr % 10) + '0', fd);
	return (count);
}
