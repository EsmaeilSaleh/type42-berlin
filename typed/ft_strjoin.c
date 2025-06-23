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

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t		i;
	char		*joined;
	const char	*p1;
	const char	*p2;

	if (!s1 || !s2)
		return (NULL);
	joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (NULL);
	i = 0;
	p1 = s1;
	p2 = s2;
	while (*p1)
		joined[i++] = *p1++;
	while (*p2)
		joined[i++] = *p2++;
	joined[i] = '\0';
	return (joined);
}
