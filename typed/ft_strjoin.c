/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: ft_strjoin — Practice Mode: Copy / Recall
*/

char	*ft_strjoin(const char *stash, const char *buffer)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!stash && !buffer)
		return (NULL);
	joined = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	if (!joined)
		return (NULL);
	i = 0;
	while (stash && stash[i])
	{
		joined[i] = stash[i];
		i++;
	}
	j = 0;
	while (buffer && buffer[j])
	{
		joined[i] = buffer[j];
		i++;
		j++;
	}
	joined[i] = '\0';
	free(stash);
	retur (joined);
}
