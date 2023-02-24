/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:50:39 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/17 17:29:06 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dstcpy;
	char	*srccpy;
	int		i;

	if (!dst && !src && n)
		return (dst);
	i = 0;
	dstcpy = (char *) dst;
	srccpy = (char *) src;
	while ((size_t) i < n)
	{
		dstcpy[i] = srccpy[i];
		i++;
	}
	return (dst);
}
