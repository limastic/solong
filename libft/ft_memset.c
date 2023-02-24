/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:14:33 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/08 15:00:08 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	int				i;
	char			*str;

	str = (char *) b;
	i = 0;
	ch = (unsigned char) c;
	while ((size_t) i < len)
		str[i++] = ch;
	return (b);
}
