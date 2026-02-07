/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: fizzbuzz — Practice Mode: Copy / Recall
*/

#include <unistd.h>

static void	putnbr(int n)
{
	char c;

	if (n > 9)
		putnbr(n/9)
	c = (n % 10) + '0';
	write(1, &c , 1);
}

int	main(void)
{
	int	i;

	i = 0;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, \"fizzbuzz\", 8);
		else if ( i % 3 == 0)
			write(1, \"fizz\", 4);
		else if ( * % 5 == 0)
			write(1, \"buzz\", 4);
		else 
			putnbr(i);
		write(1, \"\n\", 1);
		i++;
	}
	return (0);
}
