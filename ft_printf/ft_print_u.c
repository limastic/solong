/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 08:53:14 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/14 04:57:01 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_u(unsigned int nbr, int check)
{
	int		write_len;

	write_len = 0;
	if (nbr > 9)
	{
		check = ft_putnbr(nbr / 10, check);
		if (check < 0)
			return (-1);
		write_len += check;
	}
	check = ft_putchar((nbr % 10) + '0');
	if (check < 0)
		return (-1);
	write_len += check;
	return (write_len);
}
