/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:39:20 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/22 19:45:42 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_count_words(char const *s, char c)
{
	size_t	i;
	int		count;
	int		char_found;
	size_t	s_len;

	s_len = ft_strlen(s);
	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		char_found = 0;
		while (s[i] == c && i < s_len - 1)
		{
			i++;
			char_found = 1;
		}
		if ((char_found || i == 0) && s[i] && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static void	*_free_tab(char **strtab, int ind)
{
	while (ind >= 0)
		free(strtab[ind--]);
	free(strtab);
	return (NULL);
}

static int	_allocate_str(char **strtab, char const *s, char c)
{
	int	i;
	int	j;
	int	tabind;

	i = -1;
	tabind = 0;
	if (!strtab || !s)
		return (0);
	while (s[++i])
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i] && s[i++] != c)
			j++;
		i--;
		if (j)
		{
			strtab[tabind] = malloc((j + 1) * sizeof(char));
			if (!strtab[tabind])
				return (tabind);
			tabind++;
		}
	}
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**strtab;
	int		i;
	int		tabind;
	int		j;

	strtab = malloc((_count_words(s, c) + 1) * sizeof(char *));
	i = _allocate_str(strtab, s, c);
	if (!strtab || i != -1)
		return (_free_tab(strtab, i - 1));
	i = -1;
	tabind = -1;
	while (s[++i])
	{
		if (s[i] && s[i] != c)
		{
			tabind++;
			j = 0;
			while (s[i] != c && s[i])
				strtab[tabind][j++] = s[i++];
			i--;
			strtab[tabind][j] = 0;
		}
	}
	strtab[++tabind] = 0;
	return (strtab);
}
