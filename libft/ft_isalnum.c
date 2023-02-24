/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:02:23 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/07 17:37:52 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int i)
{
	unsigned char	c;

	c = (unsigned char) i;
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
