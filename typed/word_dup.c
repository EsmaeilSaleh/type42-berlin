/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_dup                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: word_dup — Practice Mode: Copy / Recall
*/

char	*word_dup(const char *start, size_t	len)
{
	char	*word;
	size_t	i;

	i = 0;
	word = malloc(len + 1);
	if (!word()
		return (NULL);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
