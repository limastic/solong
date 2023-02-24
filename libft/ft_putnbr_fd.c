/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 02:29:35 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/16 02:35:47 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb_copy;

	nb_copy = n;
	if (nb_copy < 0)
	{
		ft_putchar_fd('-', fd);
		nb_copy *= -1;
	}
	if (nb_copy > 9)
	{
		ft_putnbr_fd(nb_copy / 10, fd);
		ft_putnbr_fd(nb_copy % 10, fd);
	}
	else
		ft_putchar_fd(nb_copy + '0', fd);
}
