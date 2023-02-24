/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:45:03 by nfaust            #+#    #+#             */
/*   Updated: 2023/01/18 17:56:10 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, size_t end_index)
{
	size_t	i;
	size_t	src_len;
	char	*dst;

	if (!src)
		return (NULL);
	src_len = ft_strlen(src);
	if (end_index > src_len)
		end_index = src_len;
	dst = malloc(sizeof(char) * (end_index + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i] && i < end_index)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
