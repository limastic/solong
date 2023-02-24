/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:38:54 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/09 14:18:36 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	_min(int a, size_t b)
{
	size_t	acpy;

	acpy = (size_t) a;
	if (acpy > b)
		return (b);
	return (acpy);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	if (dstsize)
	{
		if (dstsize > 1)
			ft_memcpy(dst, src, _min(ft_strlen(src), dstsize - 1));
		dst[_min(ft_strlen(src), dstsize - 1)] = 0;
	}
	return (ft_strlen(src));
}
