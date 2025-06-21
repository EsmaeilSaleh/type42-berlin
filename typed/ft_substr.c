/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: ft_substr — Practice Mode: Copy / Recall
*/

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*substr;
	size_t	index;
	size_t	src_len;

	if (!src)
		return (NULL);
	src_len = ft_strlen(src);
	if (start >= src_len)
		return (ft_strdup(""));
	if (len > (src_len - start))
		len = src_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	index = 0;
	while (index < len && src[start + index])
	{
		substr[index] = src[start + index];
		index++;
	}
	substr[index] = '\0';
	return (substr);
}
