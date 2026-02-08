/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: rev_print — Practice Mode: Copy / Recall
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0

	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		while(argv[1][i])
			write(1, &argv[1][i], 1);
			i--;
		}
	write(1, "\n", 1);
	return (0);
}
