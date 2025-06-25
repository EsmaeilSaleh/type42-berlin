/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: ft_uitoa — Practice Mode: Copy / Recall
*/

char	*ft_uitoa(unsigned int n)
{
	int			len;
	unsigned int	temp;
	char		*res;

	len = 1;
	temp = n;
	while (temp /= 10)
		len++;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		res[len] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
