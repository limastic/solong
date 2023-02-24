/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isempty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:16:43 by nfaust            #+#    #+#             */
/*   Updated: 2023/01/12 12:47:33 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isempty(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		if (str[i++] != ' ')
			return (0);
	return (1);
}
