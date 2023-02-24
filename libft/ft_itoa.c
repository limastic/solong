/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:46:50 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/22 19:16:42 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*_allocate_str(int n)
{
	size_t	int_len;
	long	counter;
	char	*str;

	int_len = 0;
	counter = (long) n;
	if (counter < 0)
	{
		int_len++;
		counter *= -1;
	}
	if (!n)
		int_len = 1;
	while (counter > 0)
	{
		counter /= 10;
		int_len++;
	}
	str = malloc(sizeof(char) * (int_len + 1));
	if (!str)
		return (NULL);
	return (str);
}

static char	*_rev_str(char *str)
{
	int		i;
	int		j;
	char	save;

	j = 0;
	i = ft_strlen(str) - 1;
	if (str[j] == '-')
		j++;
	while (i > j)
	{
		save = str[j];
		str[j++] = str[i];
		str[i--] = save;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		last_figure;
	long	n_cpy;

	i = 0;
	str = _allocate_str(n);
	if (!str)
		return (NULL);
	if (!n)
		str[i++] = 0 + '0';
	n_cpy = (long) n;
	if (n < 0)
	{
		str[i++] = '-';
		n_cpy *= -1;
	}
	while (n_cpy > 0)
	{
		last_figure = n_cpy % 10;
		str[i++] = last_figure + '0';
		n_cpy /= 10;
	}
	str[i] = 0;
	return (_rev_str(str));
}
