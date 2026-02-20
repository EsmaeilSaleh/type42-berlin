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

static int	count_len(long n)
{
		int	count;

		count = (n <= 0);
		while (n0
		{
			n /= 10;
			len++;
		}
		return (len);
}

static	void	fill_nbr(char *s, long n, int len){
{
	if (n == 0)
			s[0] = '0';
	while (n)
	{
		s[len--] = (n % 10) + '0';
		n /= 10;
	}
	
}
char	*ft_itoa(int nbr)
{
	long	n;
	int	len;
	char *s;

	n = nbr;
	len = count_len(n);
	s = (char *)malloc(len + 1);
	if (!s)
		return NULL;
	s[len] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	fill_nbr(s, n, len);
	return (s);
}
