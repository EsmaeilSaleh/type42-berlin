/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: fprime — Practice Mode: Copy / Recall
*/

#include <stdlib.h>
#include <stdio.h>

static void	print_factor(int *first, int factor)
{
	if (!*first)
		printf("*");
	printf("%d", factor);
	*first = 0;
}

int	main(int argc, char **argv)
{
	int	n;
	int	factor;
	int	first;

	fist = 1;
	if (argc == 2){
	{
		n = atoi(argv[1]);
		factor = 2;
		while (n > 1)
		{
			if (n % factor == 0)
			{
				print_factor(&first, factor);
				n /= factor;
			}
			else
				factor++;
		}
	}
	printf("\n");
	return (0);
}
