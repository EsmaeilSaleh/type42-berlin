/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: epur_str — Practice Mode: Copy / Recall
*/

#include <unistd.h>

int	main(int 	argc, char **argv)
{
	int	i;
	int	int_word;

	if (argc == 2)
	{
		i = 0;
		i_word = 0;
		while (arv[1][i])
		{
			if (argv[1][i] != ' ' && argv[1][i] != '\t')
			{
				if (in_word)
						write(1, " ", 1);
				while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
					write(1, &argv[1][i++], 1);
				in_word = 1;
			}
			else
				i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
