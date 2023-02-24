/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:38:57 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/09 16:48:24 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;

	ch = (char) c;
	i = ft_strlen(s);
	while (1)
	{
		if (i < 0)
			return (NULL);
		else if (s[i--] == ch)
			break ;
	}
	return ((char *) s + i + 1);
}
