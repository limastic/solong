/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:46:39 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/08 21:07:53 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstcpy;
	unsigned char	*srccpy;

	srccpy = (unsigned char *) src;
	dstcpy = (unsigned char *) dst;
	if (srccpy < dstcpy)
		while (len-- > 0)
			dstcpy[len] = srccpy[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
