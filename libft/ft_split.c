/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:11:59 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/22 12:12:01 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_tab(char **tab, size_t len_tab);
void	alloc_tab(char **tab, char const *s, char c);
void	fill_tab(char **tab, char const *s, char c);
void	alloc_row(char **tab, size_t row, size_t col);

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	quantity_words;

	if (!s)
		return (NULL);
	quantity_words = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	i++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			quantity_words++;
		i++;
	}
	quantity_words++;
	tab = malloc(sizeof(char *) * (quantity_words + 1));
	if (!tab)
		return (NULL);
	alloc_tab(tab, s, c);
	fill_tab(tab, s, c);
	return (tab);
}

void	alloc_tab(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	row;
	size_t	col;

	col = 0;
	row = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
			row++;
		else if (s[i] == c && s[i - 1] != c)
		{
			alloc_row(tab, row, col);
			col++;
			row = 0;
		}
		if (s[i] != c && s[i + 1] == '\0')
			alloc_row(tab, row, col);
		i++;
	}
}

void	free_tab(char **tab, size_t len_tab)
{
	size_t	i;

	i = 0;
	while (i < (len_tab))
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	fill_tab(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	row;
	size_t	col;

	i = 0;
	row = 0;
	col = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
			tab[col][row++] = s[i];
		else if (s[i] == c && s[i - 1] != c)
		{
			tab[col++][row] = '\0';
			row = 0;
		}
		if (s[i] != c && s[i + 1] == '\0')
			tab[col++][row] = '\0';
		i++;
	}
	tab[col] = NULL;
}

void	alloc_row(char **tab, size_t row, size_t col)
{
	tab[col] = malloc(sizeof(char) * (row + 1));
	if (!(tab[col]))
		free_tab(tab, col);
}
