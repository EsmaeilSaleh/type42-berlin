/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: rotone — Practice Mode: Copy / Recall
*/

#include <unistd.h>

void	rotone(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = ((str[i] - 'A' + 1) % 26 + 'A';
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = ((str[i] - 'a' + 1) % 26 + 'a';
		write(1, &str[i], 1);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}
