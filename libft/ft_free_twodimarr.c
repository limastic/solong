/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_twodimarr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:53:34 by nfaust            #+#    #+#             */
/*   Updated: 2023/01/10 12:32:04 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_twodimarr(char **twodimarr)
{
	int	i;

	i = 0;
	while (twodimarr[i])
		free(twodimarr[i++]);
	free(twodimarr);
}
