/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:47:52 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/23 00:02:12 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char		*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	start = s1;
	while (*s1)
		s1++;
	if (s1 == start)
		return (ft_calloc(1, 1));
	s1--;
	while (ft_strchr(set, *s1))
		s1--;
	s1++;
	str = ft_calloc((s1 - start + 1), sizeof(char));
	if (!str)
		return (NULL);
	return (ft_memcpy(str, start, s1 - start));
}
