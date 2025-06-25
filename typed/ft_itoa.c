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

static int	get_int_len(int n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int	len;
	long	nbr;
	char	*res;

	len = get_int_len(n);
	nbr = n;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		res[0] = '-';
	}
	while (--len >= 0 && res[len] != '-')
	{
		res[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}
