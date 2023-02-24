/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 02:54:07 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/18 03:10:02 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_elt;

	last_elt = lst;
	while (last_elt)
	{
		if (!last_elt->next)
			return (last_elt);
		last_elt = last_elt->next;
	}
	return (last_elt);
}
