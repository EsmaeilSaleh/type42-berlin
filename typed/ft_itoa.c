/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: ft_itoa — Practice Mode: Copy / Recall
*/

char	*ft_itoa(int n)
{
	int		len = (n <= 0);
	long	nbr = n;
	char	*res;

	while (n)
	{
		n /= 10;
		len++;
	}
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		res[0] = '-';
	}
	while (len-- && res[len] != '-')
	{
		res[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}
