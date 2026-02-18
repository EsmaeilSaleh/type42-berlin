/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: print_bits — Practice Mode: Copy / Recall
*/

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i;
	char	bit;

	i = 7;
	while (i >=0)
	{
		bit = ((octet >> i) & 1) + '0')
		write(1, &bit, 1);
		i--;
	}
}
