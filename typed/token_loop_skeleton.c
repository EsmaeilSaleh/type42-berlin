/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_loop_skeleton                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: token_loop_skeleton — Practice Mode: Copy / Recall
*/

#include <unistd.h>

void	token_loop_skeleton(char *s)
{
	int 	i;
	int	seen_word;

	i = 0;
	seen_word = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		if (!s[i])
			break ;
		if (seen_word)
			write(1, " ", 1);
		while (s[i] && s[i] != ' ' && s[i] != '\t')
			write(1, &s[i++], 1);
		seen_word = 1;
	}
}
