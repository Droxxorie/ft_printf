/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:45:12 by eraad             #+#    #+#             */
/*   Updated: 2024/12/03 15:45:12 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd < 0)
		return (-1);
	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
	return (i);
}
/*
int main(void)
{
	ft_putstr_fd("Hello World\n", 1);
}
*/