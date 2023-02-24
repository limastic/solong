/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 02:42:12 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/07 20:08:38 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*lst_temp;

	lst_temp = lst;
	i = 0;
	while (lst_temp)
	{
		i++;
		lst_temp = lst_temp->next;
	}
	return (i);
}
