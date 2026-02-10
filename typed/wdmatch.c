/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: wdmatch — Practice Mode: Copy / Recall
*/

int	main(int argc, char **argv)
{
		int	i;
		int	j;

		i = 0;
		j = 0;
		if (argc == 3)
		{
			while (argv[1][i] && argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
					i++;
				j++;
			}
			if (argv[1][i] == '\0')
				write(1, argv[1], i);
		}
		write(1, "\n", 1);
		return (0);
}
