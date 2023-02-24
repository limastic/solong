/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:50:06 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/22 19:14:27 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1len;
	char	*s1cpy;

	s1len = ft_strlen(s1);
	s1cpy = malloc((s1len + 1) * sizeof(char));
	if (!s1cpy)
		return (NULL);
	if (!s1len)
	{
		s1cpy[0] = 0;
		return (s1cpy);
	}
	ft_memcpy(s1cpy, s1, ft_strlen(s1) + 1);
	return (s1cpy);
}
