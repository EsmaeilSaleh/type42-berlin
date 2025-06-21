/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: type42 <type42@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:00:00 by type42            #+#    #+#             */
/*   Updated: 2025/06/20 20:00:00 by type42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_split(const char *s, char c)
{
	size_t i = 0;
	size_t j = 0;
	size_t start = 0;
	size_t word_count;
	char **split;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	split = malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			split[j++] = word_dup(s + start, i - start + 1);
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}
