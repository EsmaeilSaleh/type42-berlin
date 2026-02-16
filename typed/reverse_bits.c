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

unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	unsigned char res;

	i = 8;
	res = 0;
	while (i--)
	{
		res = (res << 1) | (octet & 1);
		octet >>=1;
	}
	return (res);
}
