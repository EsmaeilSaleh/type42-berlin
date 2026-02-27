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

int	main(int argc, char **argv)
{
	int	num;
	int	div = 2;
	int	first = 1;
	if (argc == 2)
	{
		num = atoi(argv[1]);
		if (num == 1)
			printf("1");
		while (num > 1)
		{_
			if (num % div == 0)
			{
				if (!first)
					printf("*");
				printf("%d", div);
				first = 0;
				num /= div;
			}
			else
				div++;
		}
	}
	printf("\n");
	return (0);
}
2D
