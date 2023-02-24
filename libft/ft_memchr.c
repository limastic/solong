/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:09:37 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/15 00:26:21 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*str;
	int				i;

	str = (unsigned char *)s;
	ch = (unsigned char) c;
	i = -1;
	while ((size_t)++i < n)
		if (ch == str[i])
			return ((void *) str + i);
	return (NULL);
}
