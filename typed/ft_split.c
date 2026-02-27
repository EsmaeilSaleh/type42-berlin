/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: ft_split — Practice Mode: Copy / Recall
*/

#include <stdlib.h>

static int	is_sep(char c);
static int	word_count(char *s);
static char	*dup_word(char *s);

char	**ft_split(char *str)
{
	char **tab;
	int	w;
	int	i;

	tab = (char **)malloc(sizeof(char *) * (word_count(str) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	w = 0;
	while (s[i])
	{
		while (str[i] && is_sep(str[i]))
			i++;
		if (str[i])
		{
			tab[w] = dup_word(&str[i]);

			if (!tab[w])
				return (NULL);
			while (str[i] && !is_sep(str[i]))
				i++;
			w++;
		}
	}
	tab[w] = NULL;
	return (tab);
}
