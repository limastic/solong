/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:24:03 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/15 00:05:12 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	alloc = malloc(size * count);
	if (alloc == NULL)
		return (NULL);
	ft_bzero(alloc, size * count);
	return (alloc);
}
