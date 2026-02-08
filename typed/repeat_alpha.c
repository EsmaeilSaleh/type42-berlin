/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: repeat_alpha — Practice Mode: Copy / Recall
*/

#include <unistd.h>

static void	(char c)
{
	int	times;

	if (c >= 'a' && c <= 'z')
		times = c - 'a' + 1;
	if (c >= 'A' && c <= 'Z')
		times = c - 'A' + 1;
	else
		times = 1;
	while (times--)
		write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
			repeat_char(argv[1][i]);
			i++;
	}
	write(1, "\n", 1);
	return (0);
}
