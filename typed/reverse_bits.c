/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: reverse_bits — Practice Mode: Copy / Recall
*/

unsigned char reverse_bits(unsigned char octet)
{
	unsigned char res = 0;
	unsigned char bit = 0;
	int i;

	i = 7;

	while (i >= 0)
	{
		bit = octet & 1;
		res = res << 1;
		res = res | bit;
		octet = octet >> 1;
		i--;
	}
	return (res);
}
