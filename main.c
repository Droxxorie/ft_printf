/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:15:02 by eraad             #+#    #+#             */
/*   Updated: 2025/01/07 14:15:02 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("Original printf :\n");
	printf("Hello %s%c %i%% %d %x %X\n", "Wordl", '!', 42, -42, 42, 42);
	ft_printf("Libft ft_printf :\n");
	ft_printf("Hello %s%c %i%% %d %x %X\n", "Wordl", '!', 42, -42, 42, 42);
	return (0);
}
