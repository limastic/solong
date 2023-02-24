/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:26:15 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/17 23:33:50 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	i;
	size_t	dst_start_len;

	if (!dst && !dstsize)
		return (0);
	index = ft_strlen(dst);
	dst_start_len = index;
	if (index > dstsize || !dstsize)
		return (dstsize + ft_strlen(src));
	i = 0;
	while (index < dstsize - 1 && src[i])
		dst[index++] = src[i++];
	dst[index] = 0;
	return (dst_start_len + ft_strlen(src));
}
