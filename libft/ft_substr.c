/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:14:43 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/22 19:12:48 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	int		i;

	if (!s)
		return (NULL);
	if (!len || start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	subs = malloc((len + 1) * (size_t) sizeof(char));
	if (!subs)
		return (NULL);
	start -= 1;
	i = 0;
	while (s[++start] && (size_t) i < len)
		subs[i++] = s[start];
	subs[i] = 0;
	return (subs);
}
