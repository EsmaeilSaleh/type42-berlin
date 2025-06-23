/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: ft_strlcpy — Practice Mode: Copy / Recall
*/

size_t	ft_strlcpy(char *dst,const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
