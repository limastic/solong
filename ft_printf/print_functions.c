/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:29:30 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/14 04:57:08 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putnbr(long nbr, int check)
{
	int		write_len;

	write_len = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		check = write (1, "-", 1);
		if (check < 0)
			return (-1);
		write_len += check;
	}
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

int	ft_puthex(unsigned int nbr, char *base, int check)
{
	int	write_len;

	write_len = 0;
	if (nbr >= 16)
	{
		check = ft_puthex(nbr / 16, base, check);
		if (check < 0)
			return (-1);
		write_len += check;
		check = ft_puthex(nbr % 16, base, check);
		if (check < 0)
			return (-1);
		write_len += check;
	}
	else
	{
		check = ft_putchar(base[nbr]);
		if (check < 0)
			return (-1);
		write_len += check;
	}
	return (write_len);
}

int	ft_putptr(uintptr_t nbr, char *base, int check)
{
	int	write_len;

	write_len = 0;
	if (nbr >= 16)
	{
		check = ft_putptr(nbr / 16, base, check);
		if (check < 0)
			return (-1);
		write_len += check;
		check = ft_putptr(nbr % 16, base, check);
		if (check < 0)
			return (-1);
		write_len += check;
	}
	else
	{
		check = ft_putchar(base[nbr]);
		if (check < 0)
			return (-1);
		write_len += check;
	}
	return (write_len);
}
