/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: rev_wstr — Practice Mode: Copy / Recall
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	start;
	int	end;
	int	first = 1;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
			i++;
		while (i >= 0)
		{
			while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '\0'))
				i--;
			end = i;
			while (i >= 0 && (argv[1][i] != ' ' && argv[1][i] != '\t')
				i--;
			start = i + 1;
			if (start <= end)
			{
				if (!first)
					write(1, " ", 1);
				write(1, &argv[1][start], end - start + 1);
				first = 0;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
